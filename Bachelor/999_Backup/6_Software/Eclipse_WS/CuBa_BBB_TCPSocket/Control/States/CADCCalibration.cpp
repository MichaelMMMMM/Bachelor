/**
 * @file	CADCCalibration.cpp
 * @author	Michael Meindl
 * @date	5.4.2017
 * @brief	Method defintions for CADCCalibration.
 */
#include "CADCCalibration.h"

template<>
bool CADCCalibration::dispatch(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::TIMER_TICK == event)
	{
		mAction.sampleADCCalibration();
		return true;
	}
	return false;
}
template<>
void CADCCalibration::onEntry()
{
	mAction.entryADCCalibration();
}
template<>
void CADCCalibration::onExit()
{
	mAction.exitADCCalibration();
}
