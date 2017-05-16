/**
 * @file	CADCCalibrationAction.cpp
 * @author	Michael Meindl
 * @date	08.02.2017
 * @brief	Method defintions for CADCCalibrationAction.
 */
#include "CADCCalibrationAction.h"
#include <iostream>

CADCCalibrationAction::CADCCalibrationAction() : mTime(0.0F)
{

}
void CADCCalibrationAction::sampleADCCalibration()
{
	CSensorData data;
	if(sHardware.fetchSensorData(data))
	{
		data.mADCData.mTime = mTime;
		sProxy.transmitADCData(data.mADCData, false);
	}
	mTime += 0.02F;
}
void CADCCalibrationAction::setTorques(CTorqueData& data)
{
	std::cout << "[*] Control-Comp: Setting Torque " << data.mTorque1 << std::endl;
	sHardware.setTorque(data);
}
void CADCCalibrationAction::entryADCCalibration()
{
	std::cout << "[*] Control-Comp: Entering ADC-Calibration" << std::endl;
	mTime = 0.0F;
	sHardware.enableMotor();
}
void CADCCalibrationAction::exitADCCalibration()
{
	std::cout << "[*] Control-Comp: Exiting ADC-Calibration" << std::endl;
	sHardware.disableMotor();
}
