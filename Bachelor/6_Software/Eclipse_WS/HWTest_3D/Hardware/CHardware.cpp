/**
 * @file	CHardware.cpp
 * @author	Michael Meindl
 * @brief	08.02.2016
 * @brief	Method definitions for CHardware.
 */
#include "CHardware.h"

CHardware::CHardware() : mMotor1("4", "0", "67", "66"),
					     mMotor2("4", "1", "68", "69"),
						 mMotor3("1", "0", "44", "45")
{

}
bool CHardware::fetchSensorData(CSensorData& data)
{
	return mSensorSystem.readSensorData(data);
}
void CHardware::setTorque(CTorqueData& data)
{
	mMotor1.setTorque(data.mTorque1);
	mMotor2.setTorque(data.mTorque2);
	mMotor3.setTorque(data.mTorque3);
}
void CHardware::enableMotor()
{
	mMotor1.enableMotor();
	mMotor2.enableMotor();
	mMotor3.enableMotor();
}
void CHardware::disableMotor()
{
	mMotor1.disableMotor();
	mMotor2.disableMotor();
	mMotor3.disableMotor();
}
