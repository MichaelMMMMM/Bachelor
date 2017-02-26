/**
 * @file	CADCCalibration.cpp
 * @author	Michael Meindl
 * @date	08.02.2017
 * @brief	Method definitions for CADCalibration.
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
	if(EEvent::TORQUE_DATA == event)
	{
		CTorqueData data = *reinterpret_cast<CTorqueData*>(msg.getDataPtr());
		mAction.setTorques(data);
		return true;
	}
	return false;
}
bool CADCCalibration::tryEntry(CMessage& msg, AState*& statePtr)
{
	EEvent event = msg.getEvent();
	if(EEvent::RUN_ADC_CALIBRATION == event)
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
