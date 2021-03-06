/**
 * @file	CMPUCalib.h
 * @author	Michael Meindl
 * @date	19.02.2017
 * @brief	Class to calibrate the sensor data.
 */
#ifndef CMPUCALIB_H
#define CMPUCALIB_H
#include "CMPUData.h"
#include <string>

class CMPUCalib
{
public:
	void calibrate(const CMPUData& data);
	Float32 getK1Acceleration() const;
	Float32 getK2Acceleration() const;
	Float32 getK3Acceleration() const;
public:
	CMPUCalib(const std::string& calib_file);
	CMPUCalib(const CMPUCalib&) = delete;
	CMPUCalib& operator=(const CMPUCalib&) = delete;
	~CMPUCalib() = default;
private:
	Float32 mSMatrix[3][3];
	Float32 mOffsetVector[3];
	Float32 mAcceleration[3];
};

#endif
