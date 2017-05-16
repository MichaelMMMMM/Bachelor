/**
 * @file	CReceiveTask.cpp
 * @author	Michael Meindl
 * @date	28.9.2016
 * @brief	Method definitions for CReceiveTask.
 */
#include "CReceiveTask.h"
#include <iostream>

CReceiveTask::CReceiveTask(CServer& server) : mServer(server),
											  mRunningSem(false, true),
											  mProxyPtr(nullptr)
{

}
void CReceiveTask::init()
{
	mProxyPtr = &CProxy::getInstance();
	mServer.init();
}
void CReceiveTask::run()
{
	CMessage msg;
	while(true)
	{
		if(mServer.waitForClient())
		{
			mProxyPtr->clientConnect(true);
			std::cout << "[*] Comm-Comp: Client connected " << std::endl;
		}

		while(mServer.receiveMessage(msg))
		{
			mProxyPtr->routeClientMessage(msg, true);
		}
		mProxyPtr->clientDisconnect(true);
	}
}
bool CReceiveTask::pause(bool waitForever)
{
	std:: cout << "[*] Receive-Task: Pausing" << std::endl;
	return mRunningSem.take(waitForever);
}
bool CReceiveTask::resume(bool waitForever)
{
	std::cout << "[*] Receive-Task: Resuming" << std::endl;
	mRunningSem.give();
	return true;
}
