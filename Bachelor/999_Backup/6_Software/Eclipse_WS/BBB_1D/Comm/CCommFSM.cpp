/**
 * @file	CCommFSM.cpp
 * @author	Michael Meindl
 * @date	6.10.2016
 */
#include "CCommFSM.h"

CCommFSM::CCommFSM()
{

}
bool CCommFSM::dispatch(CMessage& msg)
{
	bool consumed = CCommFSMBase::dispatch(msg);

	while(sQueueSize != 0)
	{
		CMessage internalMsg = sInternalQueue;
		sQueueSize 			 = 0;
		consumed = CCommFSMBase::dispatch(internalMsg);
	}
	return consumed;
}
bool CCommFSM::onInitial(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::INIT == event)
	{
		mState = sStandby;
		sAction.entryStandby();
		return true;
	}
	return false;
}
bool CCommFSM::onStandby(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		sAction.exitStandby();
		mState = sInitial;
		return true;
	}
	if(EEvent::CLIENT_CONNECT == event)
	{
		sAction.exitStandby();
		mState = sRunning;
		sAction.entryRunning();
		return true;
	}
	return false;
}
bool CCommFSM::onRunning(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		sAction.exitRunning();
		mState = sInitial;
		return true;
	}
	if(EEvent::CLIENT_DISCONNECT == event)
	{
		sAction.exitRunning();
		mState = sStandby;
		sAction.entryStandby();
		return true;
	}
	if(EEvent::TX_PHI_DATA == event ||
	   EEvent::TX_PHI__D_DATA == event ||
	   EEvent::TX_PSI__D_DATA == event ||
	   EEvent::TX_SENSOR_DATA == event)
	{
		sAction.transmitMessage(msg);
		return true;
	}
	return false;
}
