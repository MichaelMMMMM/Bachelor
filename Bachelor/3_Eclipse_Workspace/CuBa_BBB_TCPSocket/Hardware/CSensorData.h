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

class CSensorFloatData
{
public:
	CSensorFloatData();
	CSensorFloatData(const CSensorFloatData&) = default;
	CSensorFloatData& operator=(const CSensorFloatData&) = default;
	~CSensorFloatData() = default;
public:
	Float32	mST1_A[3];		///! Array holding x,y,z accelerations of the artificial sensor 1
	Float32 mST2_A[3];		///! Array holding x,y,z accelerations of the artificial sensor 2
	Float32 mST3_A[3];		///! Array holding x,y,z accelerations of the artificial sensor 3
	Float32 mST4_A[3];		///! Array holding x,y,z accelerations of the artificial sensor 4
	Float32 mS1_W[3];		///! Array holding x,y,z angular velocities of sensor 1
	Float32 mS2_W[3];		///! Array holding x,y,z angular velocities of sensor 2
	Float32 mS3_W[3];		///! Array holding x,y,z angular velocities of sensor 3
	Float32 mS4_W[3];		///! Array holding x,y,z angular velocities of sensor 4
	Float32 mS5_W[3];		///! Array holding x,y,z angular velocities of sensor 5
	Float32 mS6_W[3];		///! Array holding x,y,z angular velocities of sensor 6
	Float32 mADC[3];		///! Array holding angular velocities from the ADC-Values

};

#endif
