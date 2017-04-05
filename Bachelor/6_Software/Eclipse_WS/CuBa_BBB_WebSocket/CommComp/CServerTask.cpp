/**
 * @file	CServerTask.cpp
 * @author	Michael Meindl
 * @date	4.4.2017
 * @brief	Method definitions for CServerTask.
 */
#include "CServerTask.h"
#include <iostream>

CServerTask::CServerTask() : mSocket(18000)
{

}
void CServerTask::init()
{

}
void CServerTask::run()
{
	mSocket.run(500);
}
void CServerTask::send(const std::string& msg)
{
	if(mSocket.getNumberOfConnections() > 0)
	{
		mSocket.broadcast(msg);
		mSocket.TriggerAllProtocolsCallback();
	}
}
