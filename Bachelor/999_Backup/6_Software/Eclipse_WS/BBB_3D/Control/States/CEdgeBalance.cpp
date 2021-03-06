/**
 * @file	CEdgeBalance.cpp
 * @author	Michael Meindl
 * @date	14.03.2017
 * @brief	Method definitions for CEdgeBalance.
 */
#include "CEdgeBalance.h"

CEdgeBalance::CEdgeBalance() : mState(sDefault)
{

}
bool CEdgeBalance::dispatch(CMessage& msg)
{
	return (this->*mState)(msg);
}
bool CEdgeBalance::onDefault(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::INIT == event)
	{
		mState = sIdle;
		mAction.onEntryIdle();
		return true;
	}
	return false;
}
bool CEdgeBalance::onIdle(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		mAction.onExitIdle();
		mState = sDefault;
		return true;
	}
	if(EEvent::TIMER_TICK == event)
	{
		mAction.sampleIdle();
		if(mAction.inControlArea())
		{
			sInternalQueue = CMessage(EEvent::IN_CONTROL_AREA);
			sQueueSize     = 1U;
		}
		return true;
	}
	if(EEvent::IN_CONTROL_AREA == event)
	{
		mAction.onExitIdle();
		mState = sControl;
		mAction.onEntryControl();
		return true;
	}
	if(EEvent::OFFSETCORRECTION_ACTIVE_FLAG == event)
	{
		mAction.setOffsetCorrectionFlag(*reinterpret_cast<bool*>(msg.getDataPtr()));
		return true;
	}
	if(EEvent::LQR_LQG_FLAG == event)
	{
		mAction.setLQRFlag(*reinterpret_cast<bool*>(msg.getDataPtr()));
		return true;
	}
	return false;
}
bool CEdgeBalance::onControl(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		mAction.onExitControl();
		mState = sDefault;
		return true;
	}
	if(EEvent::OUT_OF_CONTROL_AREA == event)
	{
		mAction.onExitControl();
		mState = sIdle;
		mAction.onEntryIdle();
	}
	if(EEvent::TIMER_TICK == event)
	{
		mAction.sampleControl();
		if(mAction.inControlArea() == false)
		{
			sInternalQueue = CMessage(EEvent::OUT_OF_CONTROL_AREA);
			sQueueSize     = 1U;
		}
		return true;
	}
	return false;
}
bool CEdgeBalance::tryEntry(CMessage& msg, AState*& statePtr)
{
	EEvent event = msg.getEvent();
	if(EEvent::RUN_EDGE_BALANCE == event)
	{
		statePtr = this;
		return true;
	}
	return false;
}
void CEdgeBalance::onEntry()
{
	mAction.onEntryEdgeBalance();
	CMessage msg(EEvent::INIT);
	this->dispatch(msg);
}
void CEdgeBalance::onExit()
{
	CMessage msg(EEvent::EXIT);
	this->dispatch(msg);
	mAction.onExitEdgeBalance();
}
