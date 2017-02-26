/**
 * @file	CADCCalibration.cpp
 * @author	Michael Meindl
 * @date	8.1.2017
 * @brief	Method definitions for CADCCalibration.
 */
#include "CADCCalibration.h"

CADCCalibration::CADCCalibration()
{

}
bool CADCCalibration::dispatch(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::TIMER_TICK == event)
	{
		mAction.sampleADCCalibration();
		return true;
	}
	if(EEvent::SET_TORQUE == event)
	{
		Float32 torque = msg.getTorque();
		mAction.setTorque(torque);
		return true;
	}
	return false;
}
bool CADCCalibration::tryEntry(CMessage& msg, AState*& statePtr)
{
	EEvent event = msg.getEvent();
	if(EEvent::RUN_ADC_MEASUREMENT == event)
	{
		statePtr = this;
		return true;
	}
	return false;
}
void CADCCalibration::onEntry()
{
	mAction.entryADCCalibration();
}
void CADCCalibration::onExit()
{
	mAction.exitADCCalibration();
}
