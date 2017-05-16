/**
 * @file	CControlTest.cpp
 * @author	Michael Meindl
 * @date	8.1.2017
 * @brief	Method definitions for CControlTest.
 */
#include "CControlTest.h"

CControlTest::CControlTest() : mState(sIdle)
{

}
bool CControlTest::dispatch(CMessage& msg)
{
	bool consumed = (this->*mState)(msg);
	if(consumed == false)
	{
		EEvent event = msg.getEvent();
		if(EEvent::SET_PHI_OFFSET == event)
		{
			mAction.setPhiOffset(*reinterpret_cast<Float32*>(msg.getDataPtr()));
			consumed = true;
		}
		if(EEvent::SET_FILTER == event)
		{
			mAction.setFilter(*reinterpret_cast<EFilter*>(msg.getDataPtr()));
			consumed = true;
		}
		if(EEvent::SET_HIGHPASS_FLAG == event)
		{
			mAction.setHighpassFlag(*reinterpret_cast<bool*>(msg.getDataPtr()));
			consumed = true;
		}
		if(EEvent::SET_LQR_FLAG == event)
		{
			mAction.setLQRFlag(*reinterpret_cast<bool*>(msg.getDataPtr()));
			consumed = true;
		}
		if(EEvent::SET_OBS_FLAG == event)
		{
			mAction.setObsFlag(*reinterpret_cast<bool*>(msg.getDataPtr()));
			consumed = true;
		}
	}
	return consumed;
}
bool CControlTest::tryEntry(CMessage& msg, AState*& statePtr)
{
	EEvent event = msg.getEvent();
	if(EEvent::RUN_CONTROL_TEST == event)
	{
		statePtr = this;
		return true;
	}
	return false;
}
void CControlTest::onEntry()
{
	mAction.entryControlTest();
	mState = sIdle;
	mAction.entryIdle();
}
void CControlTest::onExit()
{
	mAction.exitControlTest();
	if(mState == sIdle)
	{
		mAction.exitIdle();
		return;
	}
	if(mState == sBalance)
	{
		mAction.exitBalance();
		return;
	}

}
bool CControlTest::onIdle(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::TIMER_TICK == event)
	{
		if(mAction.inBalanceArea() == true)
		{
			mAction.exitIdle();
			mState = sBalance;
			mAction.entryBalance();
		}
		return true;
	}
	return false;
}
bool CControlTest::onBalance(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::TIMER_TICK == event)
	{
		if(mAction.inBalanceArea() == true)
		{
			mAction.sampleControlTest();
		}
		else
		{
			mAction.exitBalance();
			mState = sIdle;
			mAction.entryIdle();
		}
		return true;
	}
	return false;
}
