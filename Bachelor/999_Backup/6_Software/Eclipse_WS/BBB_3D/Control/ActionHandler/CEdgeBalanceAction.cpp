/**
 * @file	CEdgeBalanceAction.cpp
 * @author	Michael Meindl
 * @date	15.03.2017
 * @brief	Method definitions for CEdgeBalanceAction.
 */
#include "CEdgeBalanceAction.h"
#include <iostream>
#include <sys/time.h>

CEdgeBalanceAction::CEdgeBalanceAction() : mLQG("/root/control_data/1D_K_mat.csv",
											    "/root/control_data/1D_L_mat.csv",
												"/root/control_data/1D_A_mat.csv",
												"/root/control_data/1D_B_mat.csv",
												"/root/control_data/1D_C_mat.csv"),
										   mTime(0.0F),
										   mLQRFlag(true),
										   mSampleCounter(0)
{

	mSine.setFreq(2.0F);
	mSine.setAmp(0.01F);
}
void CEdgeBalanceAction::sampleIdle()
{
	mSampleCounter++;
	if(mSampleCounter >= 2)
	{
		mSampleCounter = 0;
		CSensorData sensor_data;
		sHardware.fetchSensorData(sensor_data);
	}
	else
	{
		CSensorData sensor_data;
		if(sHardware.fetchSensorData(sensor_data))
		{
			mSignalFlow.calcOutput(sensor_data);
			TRVector<3U> x = mSignalFlow.C1DOffsetCorrection::getValue();
			TRVector<1U> u = mSignalFlow.TLQR<3U, 1U>::getValue();
			x = mXLPF.calcOutput(x);
			TRVector<4U> data;
			data.scalarAt(1U, 1U) = x.scalarAt(1U, 1U);
			data.scalarAt(2U, 1U) = x.scalarAt(2U, 1U);
			data.scalarAt(3U, 1U) = x.scalarAt(3U, 1U);
			data.scalarAt(4U, 1U) = u.scalarAt(1U, 1U);

			sProxy.transmitLQRData1D(data, false);
		}
	}
}
bool CEdgeBalanceAction::inControlArea()
{
	TRVector<3U> x = mSignalFlow.C1DCompFilter::getValue();
	Float32 x_g    = x.scalarAt(1,1);
	x_g			   = x_g > 0.0F ? x_g : -x_g;
	return x_g < sMaxGValue;
}
void CEdgeBalanceAction::sampleControl()
{
	mSampleCounter++;
	if(mSampleCounter >= 2)
	{
		mSampleCounter = 0;
		CSensorData sensor_data;
		sHardware.fetchSensorData(sensor_data);
	}
	else
	{
		CSensorData sensor_data;
		if(sHardware.fetchSensorData(sensor_data))
		{
		    mSignalFlow.calcOutput(sensor_data);
		    TRVector<3U> x = mSignalFlow.C1DCompFilter::getValue();
			TRVector<1U> u = mSignalFlow.TLQR<3U, 1U>::getValue();
			TRVector<4U> data;
			data.scalarAt(1U, 1U) = x.scalarAt(1U, 1U);
			data.scalarAt(2U, 1U) = x.scalarAt(2U, 1U);
			data.scalarAt(3U, 1U) = x.scalarAt(3U, 1U);
			data.scalarAt(4U, 1U) = u.scalarAt(1U, 1U);

			sProxy.transmitLQRData1D(data, false);

			Float32 u_lqg 	 = mLQG.calculateOutput(x.scalarAt(1,1), x.scalarAt(2,1), x.scalarAt(3,1));
			TRVector<3U> x_b = mLQG.getStateVector();
			TRVector<4U> data_b;
			data_b.scalarAt(1U, 1U) = x_b.scalarAt(1,1);
			data_b.scalarAt(2U, 1U) = x_b.scalarAt(2,1);
			data_b.scalarAt(3U, 1U) = x_b.scalarAt(3,1);
			data_b.scalarAt(4U, 1U) = u_lqg;

			sProxy.transmitLQGData1D(data, false);

			Float32 u_off = 0.0F;//mSine.getValue(mTime);

			if(mLQRFlag == true)
			{
				CTorqueData tm;
				tm.mTorque1 = 0.0F; tm.mTorque2 = u.scalarAt(1U, 1U) + u_off; tm.mTorque3 = 0.0F;
				sHardware.setTorque(tm);
			}
			else
			{
				CTorqueData tm;
				tm.mTorque1 = 0.0F; tm.mTorque2 = u_lqg; tm.mTorque3 = 0.0F;
				sHardware.setTorque(tm);
			}
		}
		mTime += 0.02F;
	}
}
void CEdgeBalanceAction::onEntryEdgeBalance()
{
	std::cout << "[*] Control-Comp: Entering Edge-Balance" << std::endl;
	mLQG.reset();
}
void CEdgeBalanceAction::onExitEdgeBalance()
{
	std::cout << "[*] Control-Comp: Exiting Edge-Balance" << std::endl;
}
void CEdgeBalanceAction::onEntryIdle()
{
	std::cout << "[*] Control-Comp: Entering Idle" << std::endl;
}
void CEdgeBalanceAction::onExitIdle()
{
	std::cout << "[*] Control-Comp: Exiting Idle" << std::endl;
}
void CEdgeBalanceAction::onEntryControl()
{
	std::cout << "[*] Control-Comp: Entering Control" << std::endl;
	sHardware.enableMotor();
}
void CEdgeBalanceAction::onExitControl()
{
	std::cout << "[*] Control-Comp: Exiting Control" << std::endl;
	sHardware.disableMotor();
}
void CEdgeBalanceAction::setOffsetCorrectionFlag(bool flag)
{
	mSignalFlow.C1DOffsetCorrection::setActiveFlag(flag);
}
void CEdgeBalanceAction::setLQRFlag(bool flag)
{
	std::cout << "[*] Control-Comp: Setting LQR-Flag: " << flag << std::endl;
	mLQRFlag = flag;
}
