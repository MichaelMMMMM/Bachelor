/**
 * @file	CCornerBalance.cpp
 * @author	Michael Meindl
 * @date	20.04.2017
 * @brief	Method definitions for CCornerBalance.
 */
#include "CCornerBalance.h"

CCornerBalance::CCornerBalance() : mState(sInitial)
{

}
bool CCornerBalance::dispatch(CMessage& msg)
{
	bool consumed = (this->*mState)(msg);

	if(consumed == false)
	{

	}
	return consumed;
}
bool CCornerBalance::onInitial(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::INIT == event)
	{
		mState = sIdle;
		mAction.entryIdle();
		return true;
	}
	return false;
}
bool CCornerBalance::onIdle(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		mAction.exitIdle();
		mState = sInitial;
		return true;
	}
	if(EEvent::TIMER_TICK == event)
	{
		mAction.sample();
		if(mAction.inBalanceArea() == true)
		{
			sInternalQueue = CMessage(EEvent::IN_BALANCE_AREA);
			sQueueSize	   = 1U;
		}
		return true;
	}
	if(EEvent::IN_BALANCE_AREA == event)
	{
		mAction.exitIdle();
		mState = sBalance;
		mAction.entryBalance();
		return true;
	}
	if(EEvent::RELOAD_CONFIG == event)
	{
		mAction.reloadConfig();
		return true;
	}
	return false;
}
bool CCornerBalance::onBalance(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		mAction.exitBalance();
		mState = sInitial;
		return true;
	}
	if(EEvent::TIMER_TICK == event)
	{
		mAction.sample();
		mAction.setTorques();
		if(mAction.inBalanceArea() == false)
		{
			sInternalQueue = CMessage(EEvent::IN_IDLE_AREA);
			sQueueSize	   = 1U;
		}
		return true;
	}
	if(EEvent::IN_IDLE_AREA == event)
	{
		mAction.exitBalance();
		mState = sIdle;
		mAction.entryIdle();
		return true;
	}
	return false;
}
bool CCornerBalance::tryEntry(CMessage& msg, AState*& statePtr)
{
	EEvent event = msg.getEvent();
	if(EEvent::RUN_CORNER_BALANCE == event)
	{
		statePtr = this;
		return true;
	}
	return false;
}
void CCornerBalance::onEntry()
{
	mAction.entryCornerBalance();
	CMessage init(EEvent::INIT);
	this->dispatch(init);
}
void CCornerBalance::onExit()
{
	CMessage exit(EEvent::EXIT);
	this->dispatch(exit);
	mAction.exitCornerBalance();
}

