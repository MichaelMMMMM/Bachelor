/**
 * @file	CLQRTestAction.cpp
 * @author	Michael Meindl
 * @date	08.02.2017
 * @brief	Method definitions for CLQRTestAction.
 */
#include "CLQRTestAction.h"
#include <iostream>
#include <sys/time.h>

CLQRTestAction::CLQRTestAction() : mTime(0.0F), mDelayCounter(0U)
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
	static bool balance_flag = false;
	CSensorData sensor_data;

	if(sHardware.fetchSensorData(sensor_data))
	{

		mSignalFlow.calcOutput(sensor_data);
		CStateData state_data = mSignalFlow.CCompFilter::getValue();
		CTorqueData tm_data   = mSignalFlow.CLQR::getValue();

		state_data.mGData.mTime  = mTime;
		state_data.mUKData.mTime = mTime;
		state_data.mURData.mTime = mTime;
		tm_data.mTime = mTime;

		Float32 g1_abs = state_data.mGData.mG_k1;
		g1_abs = g1_abs > 0 ? g1_abs : -g1_abs;
		Float32 g2_abs = state_data.mGData.mG_k2;
		g2_abs = g2_abs > 0 ? g2_abs : -g2_abs;
		Float32 g3_abs = state_data.mGData.mG_k3;
		g3_abs = g3_abs > 0 ? g3_abs : -g3_abs;

		constexpr Float32 sGMax = 1.0F;
		constexpr Float32 sGExit = 3.0F;
		if( ( g3_abs < sGMax) && (g2_abs < sGMax) && (g1_abs < sGMax) )
		{
			if(balance_flag == false)
			{
				mDelayCounter++;
				if(mDelayCounter >= 100U)
				{
					balance_flag = true;
					std::cout << "[*] Control-Component: Entering Balance-Area, Time: " << mTime << std::endl;
					mSignalFlow.COffsetCorrection::disableHighpass();
					sHardware.enableMotor();
					//sHardware.disableMotor();
				}
			}
			else
			{
				sHardware.setTorque(tm_data);
			}
		}
		else
		{
			if( (balance_flag == true) && ( (g3_abs > sGExit) || (g2_abs > sGExit) || (g1_abs > sGExit) ) )
			{
				balance_flag = false;
				mDelayCounter = 0U;
				std::cout << "[*] Control-Component: Exiting Balance-Area, Time: " << mTime << std::endl;
				mSignalFlow.COffsetCorrection::disableHighpass();
				sHardware.disableMotor();
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

	mTime += 0.02F;
}