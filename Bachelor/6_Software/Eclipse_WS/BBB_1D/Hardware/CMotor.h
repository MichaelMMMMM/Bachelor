/**
 * @author	Michael Meindl
 * @date	6.12.2016
 * @brief	Hardware abstraction for the motor drivers.
 */
#ifndef CMOTOR_H
#define CMOTOR_H
#include "Global.h"

class CMotor
{
public:
	bool enableMotor();
	bool disableMotor();
	bool setTorque(float torque);
public:
	CMotor();
	~CMotor();
private:
	int initGPIOPin(UInt8 gpioNr);
	int initPWM();
	int sysfsEcho(const char* file, const char* string);
private:
	int mDirectionPinFd;
	int mEnablePinFd;
	int mTorquePWMFd;
};

#endif
