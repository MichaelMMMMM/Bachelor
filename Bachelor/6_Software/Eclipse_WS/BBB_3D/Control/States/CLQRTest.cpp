/**
 * @file	CLQRTest.cpp
 * @author	Michael Meindl
 * @date	16.02.2017
 * @brief	Method definitions for CLQRTest.
 */
#include "CLQRTest.h"

bool CLQRTest::tryEntry(CMessage& msg, AState*& statePtr)
{
	EEvent event = msg.getEvent();
	if(EEvent::RUN_CONTROL == event)
	{
		statePtr = this;
		return true;
	}
	return false;
}
bool CLQRTest::dispatch(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::TIMER_TICK == event)
	{
		mAction.sampleLQRTest();
		return true;
	}
	if(EEvent::COMPFILTER_ACTIVE_FLAG == event)
	{
		bool flag = *reinterpret_cast<bool*>(msg.getDataPtr());
		mAction.setCompFilterActiveFlag(flag);
		return true;
	}
	if(EEvent::OFFSETCORRECTION_ACTIVE_FLAG == event)
	{
		bool flag = *reinterpret_cast<bool*>(msg.getDataPtr());
		mAction.setOffsetCorrectionActiveFlag(flag);
		return true;
	}
	return false;
}
void CLQRTest::onEntry()
{
	mAction.onLQRTestEntry();
}
void CLQRTest::onExit()
{
	mAction.onLQRTestExit();
}
