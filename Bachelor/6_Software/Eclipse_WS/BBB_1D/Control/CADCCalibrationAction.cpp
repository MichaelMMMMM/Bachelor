/**
 * @file	CADCCalibrationAction.cpp
 * @author	Michael Meindl
 * @date	8.1.2017
 * @brief	Method definitions for CADCCalibrationAction.
 */
#include "CADCCalibrationAction.h"
#include "ControlConfig.h"

CADCCalibrationAction::CADCCalibrationAction() : mTime(0.0F)
{

}
void CADCCalibrationAction::entryADCCalibration()
{
	sHardware.setTorque(0.0F);
	sHardware.enableMotor();
	sTimerTask.resume(true);
	mTime = 0.0F;
}
void CADCCalibrationAction::exitADCCalibration()
{
	sHardware.setTorque(0.0F);
	sHardware.disableMotor();
	sTimerTask.pause(true);
}
void CADCCalibrationAction::setTorque(Float32 torque)
{
	sHardware.setTorque(torque);
}
void CADCCalibrationAction::sampleADCCalibration()
{
	UInt16 adcValue = 0;
	SMPU6050Data sensor1Data;
	SMPU6050Data sensor2Data;

	sHardware.fetchValues(adcValue, sensor1Data, sensor2Data);

	CSensorData data;
	data.mTime   = mTime;
	data.mPsi__d = adcValue;

	sProxy.transmitSensorData(data, true);
	mTime += ControlConfig::Ta;
}
