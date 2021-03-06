/**
 * @file	CSensorCalibration.cpp
 * @author	Michael Meindl
 * @date	5.1.2017
 * @brief	Method definitions for CSensorCalibration.
 */
#include "CSensorCalibration.h"

bool CSensorCalibration::tryEntry(CMessage& msg, AState*& statePtr)
{
	EEvent event = msg.getEvent();
	if(EEvent::RUN_SENSOR_MEASUREMENT == event)
	{
		statePtr = this;
		return true;
	}
	return false;
}
bool CSensorCalibration::dispatch(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::TIMER_TICK == event)
	{
		mAction.sampleSensorCalibration();
		return true;
	}
	return false;
}
void CSensorCalibration::onEntry()
{
	mAction.entrySensorCalibration();
}
void CSensorCalibration::onExit()
{
	mAction.exitSensorCalibration();
}
