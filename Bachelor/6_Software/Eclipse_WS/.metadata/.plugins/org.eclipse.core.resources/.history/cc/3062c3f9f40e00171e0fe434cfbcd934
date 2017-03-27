/**
 * @file	CHardware.h
 * @author	Michael Meindl
 * @date	08.02.2017
 * @brief	CHardware is composite of the different Hardware-Classes in order to control and utilize the Hardware-Peripherals.
 */
#ifndef CHARDWARE_H
#define CHARDWARE_H
#include "CSensorSystem.h"
#include "CMotor.h"
#include "CTorqueData.h"

class CHardware
{
public:
	bool fetchSensorData(CSensorData& data);
	void setTorque(CTorqueData& data);
	void enableMotor();
	void disableMotor();
	void reset() { mSensorSystem.reset(); };
public:
	CHardware();
	CHardware(const CHardware&) = delete;
	CHardware& operator=(const CHardware&) = delete;
	~CHardware() = default;
private:
	CSensorSystem mSensorSystem;
	CMotor 		  mMotor1;
	CMotor		  mMotor2;
	CMotor		  mMotor3;
};

#endif
