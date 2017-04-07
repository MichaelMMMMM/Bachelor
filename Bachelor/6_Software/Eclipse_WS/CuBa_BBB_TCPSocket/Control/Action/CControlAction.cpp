/**
 * @file	CControlAction.cpp
 * @author	Michael Meindl
 * @date	08.02.2017
 * @brief	Method definitions for CControlAction.
 */
#include "CControlAction.h"
#include <iostream>

CControlAction::CControlAction()
{
	sTimerThread.start();
}
void CControlAction::entryStandby()
{
	std::cout << "[*] Control-Comp: Entering Standby . . . " << std::endl;
}
void CControlAction::exitStandby()
{
	std::cout << "[*] Control-Comp: Exiting Standby . . . " << std::endl;
}
