/**
 * @file	CPWM.h
 * @author	Michael Meindl
 * @date	30.01.2017
 * @brief	Class to initialize and utilize the PWMs.
 */
#ifndef CPWM_H
#define CPWM_H
#include "Global.h"

class CPWM
{
public:
	bool setDutyCycle(Float32 duty_cycle);
public:
	CPWM(const std::string& chipNr,
			  const std::string& pwmNr);
	CPWM(const CPWM&) = delete;
	CPWM& operator=(const CPWM&) = delete;
	~CPWM() = default;
private:
	static constexpr Float32 sPeriod    = 2000000.0F;
	int mDutyCycleFD;
};

#endif
