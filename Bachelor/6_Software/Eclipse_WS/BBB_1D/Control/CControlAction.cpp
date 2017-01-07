/**
 * @file	CControlAction.cpp
 * @author	Michael Meindl
 * @date	5.1.2017
 * @brief	CControlAction.cpp
 */
#include "CControlAction.h"
#include <iostream>

CControlAction::CControlAction()
{
	sTimerThread.start();
}
void CControlAction::entryStandby()
{
	std::cout << "[*] Control-Comp: Entering Standby!" << std::endl;
	sTimerTask.pause(true);
	sHardware.setTorque(0.0F);
	sHardware.disableMotor();
}
void CControlAction::exitStandby()
{
	std::cout << "[*] Control-Comp: Exiting Standby!" << std::endl;
}
