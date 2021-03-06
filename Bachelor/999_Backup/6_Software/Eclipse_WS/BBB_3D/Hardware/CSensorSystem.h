/**
 * @file	CSensorSystem.h
 * @author	Michael Meindl
 * @date	07.02.2016
 * @brief	Class definition to read from the 6 MPU9250s.
 */
#ifndef CSENSORSYSTEM_H
#define CSENSORSYSTEM_H
#include "CMPU9250.h"
#include "CSwitch.h"
#include "CSensorData.h"
#include "CADCMMap.h"

class CSensorSystem
{
public:
	bool readSensorData(CSensorData& data);
public:
	CSensorSystem();
	CSensorSystem(const CSensorSystem&) = delete;
	CSensorSystem& operator=(const CSensorSystem&) = delete;
	~CSensorSystem() = default;
private:
	CSwitch  mSwitch;
	CMPU9250 mMPU;
	//CADC     mADC;
	CADCMMap mADC;
};

#endif
