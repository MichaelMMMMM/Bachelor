/**
 * @file	CADCCalibrationAction.cpp
 * @author	Michael Meindl
 * @date	5.4.2017
 * @brief	Method definitions for CADCCalibrationAction.
 */
#include "CADCCalibrationAction.h"
#include <iostream>

CADCCalibrationAction::CADCCalibrationAction() : mTime(0.0F)
{

}
void CADCCalibrationAction::entryADCCalibration()
{
	std::cout << "[*] Control-Comp: Entering ADC-Calibration . . . " << std::endl;
	mTime = 0.0F;
	sTimerTask.setPeriodMS(20);
	sTimerTask.resume(true);
	sHardware.enableMotor();
}
void CADCCalibrationAction::exitADCCalibration()
{
	std::cout << "[*] Control-Comp: Exiting ADC-Calibration . . . " << std::endl;
	sTimerTask.pause(true);
	sHardware.disableMotor();
}
void CADCCalibrationAction::sampleADCCalibration()
{
	CSensorData data;
	if(sHardware.fetchSensorData(data))
	{
		sProxy.transmitADCData(mTime, data.mADCData, false);
	}
	mTime += 0.02F;
}
