/**
 * @file	CSensorCalibration.cpp
 * @author	Michael Meindl
 * @date	5.4.2017
 * @brief	Instantiation of the Substate for the Sensor-Calibration.
 */
#include "CSensorCalibration.h"

template<>
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
template<>
void CSensorCalibration::onEntry()
{
	mAction.entrySensorCalibration();
}
template<>
void CSensorCalibration::onExit()
{
	mAction.exitSensorCalibration();
}
