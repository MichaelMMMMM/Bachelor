/**
 * @file	CLQRTestAction.cpp
 * @author	Michael Meindl
 * @date	08.02.2017
 * @brief	Method definitions for CLQRTestAction.
 */
#include "CLQRTestAction.h"
#include <iostream>
#include <sys/time.h>

CLQRTestAction::CLQRTestAction() : mTime(0.0F),
								   mDelayCounter(0U),
								   mLQG("/root/control_data/3D_Kk_mat.csv",
										"/root/control_data/3D_L_mat.csv",
										"/root/control_data/3D_A_mat.csv",
										"/root/control_data/3D_B_mat.csv",
										"/root/control_data/3D_C_mat.csv",
										"/root/control_data/3D_T_K_mat.csv"),
								   mLQRFlag(true),
								   mSamplingCounter(0)
{

}
void CLQRTestAction::setCompFilterActiveFlag(bool flag)
{
	std::cout << "[*] Control-Comp: Setting Comp-Filter-Active-Flag: " << flag << std::endl;
	flag ? mSignalFlow.CCompFilter::activate() : mSignalFlow.CCompFilter::deactivate();
}
void CLQRTestAction::setOffsetCorrectionActiveFlag(bool flag)
{
	std::cout << "[*] Control-Comp: Setting Offset-Correction-Active-Flag: " << flag << std::endl;
	flag ? mSignalFlow.COffsetCorrection::activate() : mSignalFlow.COffsetCorrection::deactive();
}
void CLQRTestAction::onLQRTestEntry()
{
	std::cout << "[*] Control-Comp: Entering LQR-Test" << std::endl;
	//sHardware.enableMotor();
	mSignalFlow.CCompFilter::reset();
	mSignalFlow.CCompFilter::deactivate();
	mSignalFlow.COffsetCorrection::deactive();
	mTime = 0.0F;
}
void CLQRTestAction::onLQRTestExit()
{
	std::cout << "[*] Control-Comp: Exiting LQR-Test" << std::endl;
	sHardware.disableMotor();
}
void CLQRTestAction::sampleLQRTest()
{
	mSamplingCounter++;
	if(mSamplingCounter >= 2)
	{
		CSensorData sensor_data;
		sHardware.fetchSensorData(sensor_data);
		mSamplingCounter = 0;
	}
	else
	{
		static bool balance_flag = false;
		CSensorData sensor_data;

		struct timeval timebegin, timeend;
		long seconds, useconds;
		gettimeofday(&timebegin, (struct timezone*)0);

		if(sHardware.fetchSensorData(sensor_data))
		{
			mSignalFlow.calcOutput(sensor_data);
			CStateData state_data  = mSignalFlow.CCompFilter::getValue();
			TRVector<3U> u   	   = mSignalFlow.TLQR<9U, 3U>::getValue();

			CTorqueData tm_data(u);
			CTorqueData tm_b;

			state_data.mGData.mTime  = mTime;
			state_data.mUKData.mTime = mTime;
			state_data.mURData.mTime = mTime;
			tm_data.mTime = mTime;

			Float32 phi2_abs = state_data.mGData.mG_k2;
			Float32 phi3_abs = state_data.mGData.mG_k3;
			phi2_abs = phi2_abs > 0 ? phi2_abs : -phi2_abs;
			phi3_abs = phi3_abs > 0 ? phi3_abs : -phi3_abs;

			constexpr Float32 sGMax  = 0.1F;
			constexpr Float32 sGExit = 0.2F;
			if( ( phi3_abs < sGMax) && (phi2_abs < sGMax) )
			{
				if(balance_flag == false)
				{
					mDelayCounter++;
					if(mDelayCounter >= 50U)
					{
						balance_flag = true;
						std::cout << "[*] Control-Component: Entering Balance-Area, Time: " << mTime << std::endl;
						sHardware.enableMotor();
						//sHardware.disableMotor();
					}
				}
				else
				{
					tm_b = mLQG.calculateOutput(state_data);
					if(mLQRFlag == true)
					{
						sHardware.setTorque(tm_data);
					}
					else
					{
						sHardware.setTorque(tm_b);
					}
				}
			}
			else
			{
				if( (balance_flag == true) && ( (phi3_abs > sGExit) && (phi2_abs > sGExit) ) )
				{
					balance_flag = false;
					mDelayCounter = 0U;
					std::cout << "[*] Control-Component: Exiting Balance-Area, Time: " << mTime << std::endl;
					sHardware.disableMotor();
					mLQG.reset();
				}
			}

			sProxy.transmitGData(state_data.mGData, false);
			sProxy.transmitUKData(state_data.mUKData, false);
			sProxy.transmitURData(state_data.mURData, false);
			sProxy.transmitTorqueData(tm_data, false);
		}
		else
		{
			std::cout << "[*] Control-Comp: Failed to read Sensor-Data" << std::endl;
		}

		gettimeofday(&timeend, (struct timezone*)0);
		seconds = timeend.tv_sec - timebegin.tv_sec;
		useconds = timeend.tv_usec - timebegin.tv_usec;
		if(useconds < 0)
		{
			useconds += 1000000;
			seconds--;
		}
		//std::cerr << "seconds: " << seconds << " useconds: " << useconds << std::endl;

		mTime += 0.02F;
	}
}
