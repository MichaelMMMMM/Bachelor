/**
 * @file	CMPUData.h
 * @author	Michael Meindl
 * @date	06.02.2017
 * @brief	Data-Container for the MPU-Values.
 */
#ifndef CMPUDATA_H
#define CMPUDATA_H
#include "Global.h"

class CMPUData
{
public:
	void display();
public:
	CMPUData();
	CMPUData(const CMPUData&) = default;
	CMPUData& operator=(const CMPUData&) = default;
	~CMPUData() = default;
public:
    Float32 mTime;      //Timestamp
	Int16 mA_x;			//Acceleration-Component in X-Direction []
	Int16 mA_y;			//Acceleration-Component in Y-Direction []
	Int16 mA_z;			//Acceleration-Component in Z-Direction []
	Int16 mW_x;			//Angular-Velocity-Component in X-Direction []
	Int16 mW_y;			//Angular-Velocity-Component in Y-Direction []
	Int16 mW_z;			//Angular-Velocity-Component in Z-Direction []
};

#endif
