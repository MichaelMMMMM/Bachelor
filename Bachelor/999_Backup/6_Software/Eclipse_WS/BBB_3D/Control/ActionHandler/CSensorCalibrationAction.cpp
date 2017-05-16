/**
 * @file	CSensorCalibrationAction.cpp
 * @author	Michael Meindl
 * @date	08.02.2017
 * @brief	Method definitions for CSensorCalibrationAction.
 */
#include "CSensorCalibrationAction.h"
#include <iostream>

CSensorCalibrationAction::CSensorCalibrationAction() : mTime(0.0F)
{

}
void CSensorCalibrationAction::sampleSensorCalibration()
{
	mTime += 0.02F;
	CSensorData data;
	if(sHardware.fetchSensorData(data))
	{
		data.mSensor1Data.mTime = mTime;
		data.mSensor2Data.mTime = mTime;
		data.mSensor3Data.mTime = mTime;
		data.mSensor4Data.mTime = mTime;
		data.mSensor5Data.mTime = mTime;
		data.mSensor6Data.mTime = mTime;
		sProxy.transmitSensorData(EEvent::SENSOR_1_DATA, data.mSensor1Data, false);
		sProxy.transmitSensorData(EEvent::SENSOR_2_DATA, data.mSensor2Data, false);
		sProxy.transmitSensorData(EEvent::SENSOR_3_DATA, data.mSensor3Data, false);
		sProxy.transmitSensorData(EEvent::SENSOR_4_DATA, data.mSensor4Data, false);
		sProxy.transmitSensorData(EEvent::SENSOR_5_DATA, data.mSensor5Data, false);
		sProxy.transmitSensorData(EEvent::SENSOR_6_DATA, data.mSensor6Data, false);
	}
	else
	{
		std::cout << "[*] Control-Comp: Failed to read the sensor values . . . " << std::endl;
	}
}
void CSensorCalibrationAction::entrySensorCalibration()
{
	std::cout << "[*] Control-Comp: Entering Sensor-Calibration . . . " << std::endl;
	mTime = 0.0F;
}
void CSensorCalibrationAction::exitSensorCalibration()
{
	std::cout << "[*] Control-Comp: Exiting Sensor-Calibration . . . " << std::endl;
}
