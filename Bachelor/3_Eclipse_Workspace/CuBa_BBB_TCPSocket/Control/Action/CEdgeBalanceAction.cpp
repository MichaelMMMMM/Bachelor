/**
 * @file	CEdgeBalanceAction.cpp
 * @author	Michael Meindl
 * @date	18.04.2017
 * @brief	Method definitions for CEdgeBalanceAction.
 **/
#include "CEdgeBalanceAction.h"
#include <iostream>
#include <cmath>

CEdgeBalanceAction::CEdgeBalanceAction() : mTime(0.0F), mEntryCounter(1U)
{

}
void CEdgeBalanceAction::updateConfig()
{
	std::cout << "[*] Control-Comp: Reloading Configuration . . .  " << std::endl;
	mSignalFlow.C1DControlSystem::updateConfig();
}
void CEdgeBalanceAction::entryBalance()
{
	std::cout << "[*] Control-Comp: Entering Edge-Balance/Balance . . . " << std::endl;
	sHardware.enableMotor();
	mSignalFlow.C1DControlSystem::activateControllers();
	mSignalFlow.C1DControlSystem::setObserverX0();
}
void CEdgeBalanceAction::exitBalance()
{
	std::cout << "[*] Control-Comp: Exiting Edge-Balance/Balance . . . " << std::endl;
	sHardware.disableMotor();
	mSignalFlow.C1DControlSystem::deactivateControllers();
}
void CEdgeBalanceAction::entryEdgeBalance()
{
	std::cout << "[*] Control-Comp: Entering Edge-Balance . . . " << std::endl;
	mTime = 0.0F;
	sTimerTask.setPeriodMS(20);
	sTimerTask.resume(true);
}
void CEdgeBalanceAction::exitEdgeBalance()
{
	std::cout << "[*] Control-Comp: Exiting Edge-Balance . . . " << std::endl;
	sTimerTask.pause(true);
}
void CEdgeBalanceAction::entryIdle()
{
	std::cout << "[*] Control-Comp: Entering Edge-Balance/Idle . . . " << std::endl;
	mSignalFlow.C1DControlSystem::deactivateControllers();
}
void CEdgeBalanceAction::exitIdle()
{
	std::cout << "[*] Control-Comp: Exiting Edge-Balance/Idle . . . " << std::endl;
}
void CEdgeBalanceAction::sample()
{
	CSensorData sensor_data;
	if(sHardware.fetchSensorData(sensor_data))
	{
		mSignalFlow.calcOutput(sensor_data);
		auto data = mSignalFlow.C1DControlSystem::getCompLQRData();
		sProxy.transmit1DCompLQRData(mTime, data, false);
		data      = mSignalFlow.C1DControlSystem::getPhiObsLQRData();
		sProxy.transmit1DPhiObsLQRData(mTime, data, false);
		if(std::isnan(data[3][1]))
		{
			std::cout << "[*] X3 is not a number!" << std::endl;
		}
		data      = mSignalFlow.C1DControlSystem::getFullObsLQRData();
		sProxy.transmit1DFullObsLQRData(mTime, data, false);
	}
	else
	{
		std::cout << "[*] Control-Comp: Failed to read Sensor-Values . . . " << std::endl;
	}
	mTime += 0.02F;
}
bool CEdgeBalanceAction::inBalanceArea()
{
	auto x = mSignalFlow.C1DControlSystem::getCompLQRData();
	Float32 phi       = x[1][1] > 0.0F ? x[1][1] : -x[1][1];
	if(phi < sPhiMax)
	{
		mEntryCounter++;
		if(mEntryCounter >= 50U)
		{
			return true;
		}
	}
	else
	{
		mEntryCounter = 0U;
	}
	return false;
}
void CEdgeBalanceAction::setTorques()
{
	CTorqueData torque;
	auto copy = mSignalFlow.C1DControlSystem::getValue();
	torque.mTorque2 = copy[1][1];
	sHardware.setTorque(torque);
}
void CEdgeBalanceAction::setPhiOffset(Float32 offset)
{
	std::cout << "[*] Control-Comp: Setting Phi-Offset: " << offset << std::endl;
	mSignalFlow.C1DOffsetCorrection::setPhiOffset(offset);
}
void CEdgeBalanceAction::setUKOffset(Float32 offset)
{
	std::cout << "[*] Control-Comp: Setting UK-Offset: " << offset << std::endl;
	mSignalFlow.C1DOffsetCorrection::setUKOffset(offset);
}
void CEdgeBalanceAction::setUROffset(Float32 offset)
{
	std::cout << "[*] Control-Comp: Setting UR-Offset: " << offset << std::endl;
	mSignalFlow.C1DOffsetCorrection::setUROffset(offset);
}
void CEdgeBalanceAction::selectControlSystem(E1DControlSystem sys)
{
	switch(sys)
	{
	case E1DControlSystem::COMP_LQR:
		std::cout << "[*] Control-Comp: Select 1D-Control-System: Complementary-Filter + LQR . . . " << std::endl;
		break;
	case E1DControlSystem::PHI_OBS_LQR:
		std::cout << "[*] Control-Comp: Select 1D-Control-System: Phi-Observer + LQR . .  ." << std::endl;
		break;
	case E1DControlSystem::FULL_OBS_LQR:
		std::cout << "[*] Control-Comp: Select 1D-Control-System: Comp-Filter + Full-State-Observer + LQR . . . " << std::endl;
		break;
	default:
		break;
	}
	mSignalFlow.C1DControlSystem::setControlSystem(sys);
}
