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
	if( (EEvent::SENSOR_1_DATA == event) ||
		(EEvent::SENSOR_2_DATA == event) ||
		(EEvent::SENSOR_3_DATA == event) ||
		(EEvent::SENSOR_4_DATA == event) ||
		(EEvent::SENSOR_5_DATA == event) ||
		(EEvent::SENSOR_6_DATA == event) ||
		(EEvent::ADC_DATA == event) 	 ||
		(EEvent::G_DATA == event) 		 ||
		(EEvent::UK_DATA == event)  	 ||
		(EEvent::UR_DATA == event)		 ||
		(EEvent::TORQUE_DATA == event) )
	{
		sAction.transmitMessage(msg);
		return true;
	}
	if(EEvent::CLIENT_DISCONNECT == event)
	{
		sAction.exitRunning();
		mState = sStandby;
		sAction.entryStandby();
		return true;
	}
	return false;
}
