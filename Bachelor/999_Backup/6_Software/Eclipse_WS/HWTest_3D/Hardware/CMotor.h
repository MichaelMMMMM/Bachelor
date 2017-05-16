/**
 * @file	CMotor.h
 * @author	Michael Meindl
 * @date	30.01.2017
 * @brief	Class to initialize and utilize the motors.
 */
#ifndef CMOTOR_H
#define CMOTOR_H
#include "CPWM.h"
#include "CGPIO.h"

class CMotor
{
public:
	void enableMotor();
	void disableMotor();
	void setTorque(Float32 torque);
public:
	CMotor(const std::string& pwmchipNr,
		   const std::string& pwmNr,
		   const std::string& enablePinNr,
		   const std::string& directionPinNr);
	CMotor(const CMotor&) = delete;
	CMotor& operator=(const CMotor&) = delete;
	~CMotor() = default;
private:
	static constexpr Float32 sMaxTorque = 0.1107F;
	CPWM mTorquePWM;
	CGPIO mEnablePin;
	CGPIO mDirectionPin;
};

#endif
