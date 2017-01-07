/**
 * @file	CContainer.cpp
 * @author	Michael Meindl
 * @date	5.12.2016
 * @brief	Method definitions for the container.
 */
#include "CContainer.h"


CContainer::CContainer() : mReadSem(false, false)
{

}
bool CContainer::getContent(bool waitForever,
							SContent& content)
{
	if(mReadSem.take(waitForever))
	{
		content = mContent;
		return true;
	}
	return false;
}
void CContainer::signalReader()
{
	mReadSem.give();
}
bool CContainer::writeADCValue(const UInt16 adcValue)
{
	mContent.mADCValue = adcValue;
	return true;
}
bool CContainer::writeTorqueValue(const float torque)
{
	mContent.mMotorTorque = torque;
	return true;
}
bool CContainer::writeSensor1Data(const SMPU6050Data& sensorData)
{
	mContent.mSensor1Data = sensorData;
	return true;
}
bool CContainer::writeSensor2Data(const SMPU6050Data& sensorData)
{
	mContent.mSensor2Data = sensorData;
	return true;
}
bool CContainer::writeStateData(const SStateVectorData& stateValue)
{
	mContent.mStateData = stateValue;
	return true;
}
