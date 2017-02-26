/**
 * @file	CSensorData.h
 * @author	Michael Meindl
 * @date	07.02.2017
 * @brief	Data-Class to hold the sensor values from the 6 MPUs and 3 ADCs.
 */
#ifndef CSENSORDATA_H
#define CSENSORDATA_H
#include "CMPUData.h"
#include "CADCData.h"

class CSensorData
{
public:
	void display();
public:
	CSensorData();
	CSensorData(const CSensorData&) = default;
	CSensorData& operator=(const CSensorData&) = default;
	~CSensorData() = default;
public:
	CMPUData mSensor1Data;
	CMPUData mSensor2Data;
	CMPUData mSensor3Data;
	CMPUData mSensor4Data;
	CMPUData mSensor5Data;
	CMPUData mSensor6Data;
	CADCData mADCData;
};

#endif
