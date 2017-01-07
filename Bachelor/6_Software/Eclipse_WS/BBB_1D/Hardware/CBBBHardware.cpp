/**
 * @author	Michael Meindl
 * @date	6.12.2016
 * @brief	Method definitions for CBBBHardware.
 */
#include "CBBBHardware.h"

CBBBHardware::CBBBHardware() : mSensor1(1),
							   mSensor2(2)
{

}
bool CBBBHardware::fetchValues(UInt16& adcValue,
				 	 	 	   SMPU6050Data& sensor1Data,
							   SMPU6050Data& sensor2Data)
{
	if(!mADC.fetchValue(adcValue))
	{
		return false;
	}
	if(!mSensor1.fetchValues(sensor1Data))
	{
		return false;
	}
	if(!mSensor2.fetchValues(sensor2Data))
	{
		return false;
	}
	return true;
}
bool CBBBHardware::enableMotor()
{
	return mMotor.enableMotor();
}
bool CBBBHardware::disableMotor()
{
	return mMotor.disableMotor();
}
bool CBBBHardware::setTorque(float torque)
{
	mBrake.openBrake();
	return mMotor.setTorque(torque);
}
bool CBBBHardware::openBrake()
{
	mMotor.enableMotor();
	return mBrake.openBrake();
}
bool CBBBHardware::closeBrake()
{
	mMotor.disableMotor();
	return mBrake.closeBrake();
}
