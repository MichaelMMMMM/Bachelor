/**
 * @file	CEdgeBalance.cpp
 * @author	Michael Meindl
 * @date	18.04.2017
 * @brief	Method definitions for CEdgeBalance.
 */
#include "CEdgeBalance.h"

CEdgeBalance::CEdgeBalance() : mState(sInitial)
{

}
bool CEdgeBalance::dispatch(CMessage& msg)
{
	bool consumed = (this->*mState)(msg);
	if(consumed == false)
	{
		EEvent event = msg.getEvent();
		if(EEvent::PHI_OFFSET == event)
		{
			mAction.setPhiOffset(*reinterpret_cast<Float32*>(msg.getDataPtr()));
			return true;
		}
		if(EEvent::UK_OFFSET == event)
		{
			mAction.setUKOffset(*reinterpret_cast<Float32*>(msg.getDataPtr()));
			return true;
		}
		if(EEvent::UR_OFFSET == event)
		{
			mAction.setUROffset(*reinterpret_cast<Float32*>(msg.getDataPtr()));
			return true;
		}
		if(EEvent::SELECT_1D_CONTROL == event)
		{
			mAction.selectControlSystem(*reinterpret_cast<E1DControlSystem*>(msg.getDataPtr()));
			return true;
		}
		if(EEvent::RELOAD_CONFIG == event)
		{
			mAction.updateConfig();
			return true;
		}
	}
	return consumed;
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
	mAction.entryEdgeBalance();
	CMessage init(EEvent::INIT);
	this->dispatch(init);
}
void CEdgeBalance::onExit()
{
	CMessage exit(EEvent::EXIT);
	this->dispatch(exit);
	mAction.exitEdgeBalance();
}
bool CEdgeBalance::onInitial(CMessage& msg)
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
bool CEdgeBalance::onIdle(CMessage& msg)
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
		if(mAction.inBalanceArea())
		{
			sInternalQueue = CMessage(EEvent::IN_BALANCE_AREA);
			sQueueSize     = 1;
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
	return false;
}
bool CEdgeBalance::onBalance(CMessage& msg)
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
			sQueueSize	   = 1;
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

