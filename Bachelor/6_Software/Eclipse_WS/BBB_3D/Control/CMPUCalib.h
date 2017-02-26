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
	Float32 getK1AngularVelocity() const;
	Float32 getK2AngularVelocity() const;
	Float32 getK3AngularVelocity() const;
public:
	CMPUCalib(const std::string& acalib_file, const std::string& gcalib_file);
	CMPUCalib(const CMPUCalib&) = delete;
	CMPUCalib& operator=(const CMPUCalib&) = delete;
	~CMPUCalib() = default;
private:
	Float32 mSAMatrix[3][3];
	Float32 mAOffsetVector[3];
	Float32 mAcceleration[3];

	Float32 mSGMatrix[3][3];
	Float32 mGOffsetVector[3];
	Float32 mAngularVelocity[3];
};

#endif
