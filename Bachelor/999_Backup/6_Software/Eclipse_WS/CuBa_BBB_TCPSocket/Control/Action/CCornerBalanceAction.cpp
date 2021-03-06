/**
 * @file	CCornerBalanceAction.cpp
 * @author	Michael Meindl
 * @date	20.04.2017
 * @brief	Method definitions for CCornerBalanceAction.
 */
#include "CCornerBalanceAction.h"
#include <iostream>

CCornerBalanceAction::CCornerBalanceAction() : mTime(0.0F), mDelayCounter(0U)
{
	mSignalFlow.TLQR<9U, 3U>::init("config/Corner_Kd.csv");
}
void CCornerBalanceAction::entryCornerBalance()
{
	std::cout << "[*] Control-Comp: Entering Corner-Balance . . . " << std::endl;
	mTime = 0.0F;
	sTimerTask.setPeriodMS(20);
	sTimerTask.resume(true);
	mSignalFlow.C3DCompFilter::reset();
}
void CCornerBalanceAction::exitCornerBalance()
{
	std::cout << "[*] Control-Comp: Exiting Corner-Balance . . . " << std::endl;
	sTimerTask.pause(true);
}
void CCornerBalanceAction::entryIdle()
{
	std::cout << "[*] Control-Comp: Entering Corner-Balance/Idle . . ." << std::endl;
}
void CCornerBalanceAction::exitIdle()
{
	std::cout << "[*] Control-Comp: Exiting Corner-Balance/Idle . . . " << std::endl;
}
void CCornerBalanceAction::entryBalance()
{
	std::cout << "[*] Control-Comp: Entering Corner-Balance/Balance . . . Time: " << mTime << std::endl;
	sHardware.enableMotor();
}
void CCornerBalanceAction::exitBalance()
{
	std::cout << "[*] Control-Comp: Exiting Corner-Balance/Balance . . . Time: " << mTime << std::endl;
	sHardware.disableMotor();
}
void CCornerBalanceAction::setTorques()
{
	TRVector<3U> u = mSignalFlow.TLQR<9U, 3U>::getValue();
	CTorqueData torque;
	torque.mTorque1 = u[1][1];
	torque.mTorque2 = u[2][1];
	torque.mTorque3 = u[3][1];
	sHardware.setTorque(torque);
}
bool CCornerBalanceAction::inBalanceArea()
{
	TRVector<9U> x = mSignalFlow.C3DCompFilter::getValue();
	Float32 phi2_abs = x[2][1] > 0.0F ? x[2][1] : - x[2][1];
	Float32 phi3_abs = x[3][1] > 0.0F ? x[3][1] : - x[3][1];

	if( (phi2_abs < sPhiMax) && (phi3_abs < sPhiMax) )
	{
		if(mDelayCounter >= 50U)
		{
			return true;
		}
		else
		{
			mDelayCounter++;
		}
	}
	else
	{
		mDelayCounter = 0U;
	}
	return false;
}
void CCornerBalanceAction::sample()
{
	CSensorData data;
	if(sHardware.fetchSensorData(data))
	{
		mSignalFlow.calcOutput(data);
		auto x = mSignalFlow.C3DCompFilter::getValue();
		auto u = mSignalFlow.TLQR<9U, 3U>::getValue();
		TRVector<2U> phi; phi[1][1] = x[2][1]; phi[2][1] = x[3][1];
		TRVector<3U> uk;  uk[1][1]  = x[4][1]; uk[2][1]  = x[5][1]; uk[3][1] = x[6][1];
		TRVector<3U> ur;  ur[1][1]  = x[7][1]; ur[2][1]  = x[8][1]; ur[3][1] = x[9][1];
		sProxy.transmit3DCompLQRPhi(mTime, phi, false);
		sProxy.transmit3DCompLQRUK(mTime, uk, false);
		sProxy.transmit3DCompLQRUR(mTime, ur, false);
		sProxy.transmit3DCompLQRTM(mTime, u, false);
	}
	else
	{
		std::cout << "[*] Control-Comp: Failed to read Sensor-Data . . . " << std::endl;
	}
	mTime += 0.02F;
}
void CCornerBalanceAction::reloadConfig()
{
	std::cout << "[*] Control-Comp: Loading Configuration . . . " << std::endl;
	mSignalFlow.TLQR<9U, 3U>::init("config/Corner_Kd.csv");
}
