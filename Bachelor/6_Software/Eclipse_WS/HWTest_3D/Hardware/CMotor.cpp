/**
 * @file	CMotor.cpp
 * @author	Michael Meindl
 * @date	30.01.2017
 * @brief	Method definitios for CMotor.
 */
#include "CMotor.h"

CMotor::CMotor(const std::string& pwmchipNr,
			   const std::string& pwmNr,
			   const std::string& enablePinNr,
			   const std::string& directionPinNr)
				: mTorquePWM(pwmchipNr, pwmNr),
				  mEnablePin(enablePinNr),
				  mDirectionPin(directionPinNr)
{
	mEnablePin.setLow();
	mTorquePWM.setDutyCycle(10.0F);
}
void CMotor::enableMotor()
{
	mEnablePin.setHigh();
}
void CMotor::disableMotor()
{
	mEnablePin.setLow();
}
void CMotor::setTorque(Float32 torque)
{
	torque >= 0 ? mDirectionPin.setLow() : mDirectionPin.setHigh();
	torque = torque >= 0 ? torque : -torque;
	torque = torque > sMaxTorque ? sMaxTorque : torque;
	Float32 pwm_value = 10.0F + 80.0F*(torque/sMaxTorque);
	mTorquePWM.setDutyCycle(pwm_value);
}
