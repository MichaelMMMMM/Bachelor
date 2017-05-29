/**
 * @file	CSensorCalibrationAction.cpp
 * @author	Michael Meindl
 * @date	5.1.2017
 * @brief	Method defintions for CSensorCalibrationAction.
 */
#include "CSensorCalibrationAction.h"
#include "SMPU6050Data.h"
#include "CSensorData.h"
#include "ControlConfig.h"
#include <iostream>

CSensorCalibrationAction::CSensorCalibrationAction() : mTime(0.0F)
{

}
void CSensorCalibrationAction::entrySensorCalibration()
{
	std::cout << "[*] Control-Comp: Entering Sensor-Calibration!" << std::endl;
	sTimerTask.resume(true);
	mTime = 0.0F;

}
void CSensorCalibrationAction::exitSensorCalibration()
{
	std::cout << "[*] Control-Comp: Exiting Sensor-Calibration!" << std::endl;
	sTimerTask.pause(true);
}
void CSensorCalibrationAction::sampleSensorCalibration()
{
	SMPU6050Data sensor1Data;
	SMPU6050Data sensor2Data;
	UInt16 adcValue;

	mTime += ControlConfig::Ta;

	if(sHardware.fetchValues(adcValue, sensor1Data, sensor2Data))
	{
		CSensorData data;
		data.mTime 		= mTime;
		data.mX1__dd 	= sensor1Data.mX__dd;
		data.mX2__dd 	= sensor2Data.mX__dd;
		data.mY1__dd 	= sensor1Data.mY__dd;
		data.mY2__dd 	= sensor2Data.mY__dd;
		data.mPhi1__d 	= sensor1Data.mPhi__d;
		data.mPhi2__d 	= sensor2Data.mPhi__d;
		sProxy.transmitSensorData(data, false);
	}
}