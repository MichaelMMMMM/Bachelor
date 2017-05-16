/**
 * @file	CControlComp.cpp
 * @author	Michael Meindl
 * @date	5.1.2017
 * @brief	Method definitions for CControlComp.
 */
#include "CControlComp.h"
#include <iostream>

void CControlComp::init()
{
	std::cout << "[*] Control-Comp: Initializing . .  . " << std::endl;
}
void CControlComp::run()
{
	std::cout << "[*] Control-Comp: Running . . . " << std::endl;

	CMessage msg;

	while(true)
	{
		if(mQueue.popFront(msg, true))
		{
			mFSM.dispatch(msg);
		}
	}
}
