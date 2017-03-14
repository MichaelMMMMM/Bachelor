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
	if(EEvent::TIMER_TICK == event)
	{
		mAction.sampleControl();
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