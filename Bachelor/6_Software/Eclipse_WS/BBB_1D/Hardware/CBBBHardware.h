/**
 * @author	Michael Meindl
 * @date	6.12.2016
 * @brief	Host class to combine all other hardware-classes.
 */
#ifndef CBBBHARDWARE_H
#define CBBBHARDWARE_H
#include "CADC.h"
#include "CMotor.h"
#include "CBrake.h"
#include "CMPU6050.h"

class CBBBHardware
{
public:
	bool fetchValues(UInt16& adcValue,
					 SMPU6050Data& sensor1Data,
					 SMPU6050Data& sensor2Data);
	bool enableMotor();
	bool disableMotor();
	bool setTorque(float torque);
	bool openBrake();
	bool closeBrake();
public:
	CBBBHardware();
private:
	CADC mADC;
	CBrake mBrake;
	CMotor mMotor;
	CMPU6050 mSensor1;
	CMPU6050 mSensor2;
};

#endif
