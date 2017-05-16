/**
 * @file	CSensorCalibrationAction.cpp
 * @author	Michael Meindl
 * @date	5.4.2017
 * @brief	Method defitions for CSensorCalibrationAction.
 */
#include "CSensorCalibration.h"
#include <iostream>

CSensorCalibrationAction::CSensorCalibrationAction() : mTime(0.0F)
{

}
void CSensorCalibrationAction::entrySensorCalibration()
{
	mTime = 0.0F;
	sTimerTask.setPeriodMS(20);
	sTimerTask.resume(true);
	std::cout << "[*] Control-Comp: Entering Sensor-Calibration . . . " << std::endl;
}
void CSensorCalibrationAction::exitSensorCalibration()
{
	sTimerTask.pause(true);
	std::cout << "[*] Control-Comp: Exiting Sensor-Calibration . . . " << std::endl;
}
void CSensorCalibrationAction::sampleSensorCalibration()
{
	CSensorData data;
	if(sHardware.fetchSensorData(data))
	{
		sProxy.transmitSensorData(1, mTime, data.mSensor1Data, false);
		sProxy.transmitSensorData(2, mTime, data.mSensor2Data, false);
		sProxy.transmitSensorData(3, mTime, data.mSensor3Data, false);
		sProxy.transmitSensorData(4, mTime, data.mSensor4Data, false);
		sProxy.transmitSensorData(5, mTime, data.mSensor5Data, false);
		sProxy.transmitSensorData(6, mTime, data.mSensor6Data, false);
	}
	mTime += 0.02F;
}
