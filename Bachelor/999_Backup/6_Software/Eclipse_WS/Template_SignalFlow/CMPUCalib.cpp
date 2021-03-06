/**
 * @file	CMPUCalib.cpp
 * @author	Michael Meindl
 * @date	19.02.2017
 * @brief	Method definitions for CMPUCalib.
 */
#include "CMPUCalib.h"
#include <ostream>
#include <fstream>
using namespace std;

CMPUCalib::CMPUCalib(const std::string& calib_file) : mSMatrix{0.0F},
													  mOffsetVector{0.0F},
													  mAcceleration{0.0F}
{
	ifstream stream;
	stream.open(calib_file);
	string data;
	stream >> data;

}
void CMPUCalib::calibrate(const CMPUData& data)
{
	Float32 x = static_cast<Float32>(data.mA_x);
	Float32 y = static_cast<Float32>(data.mA_y);
	Float32 z = static_cast<Float32>(data.mA_z);

	mAcceleration[0] = mSMatrix[0][0] * x +
					   mSMatrix[0][1] * y +
				 	   mSMatrix[0][2] * z +
					   mOffsetVector[0];
	mAcceleration[1] = mSMatrix[1][0] * x +
					   mSMatrix[1][1] * y +
					   mSMatrix[1][2] * z +
					   mOffsetVector[1];
	mAcceleration[2] = mSMatrix[2][0] * x +
					   mSMatrix[2][1] * y +
					   mSMatrix[2][2] * z +
					   mOffsetVector[2];
}
Float32 CMPUCalib::getK1Acceleration() const
{
	return mAcceleration[0];
}
Float32 CMPUCalib::getK2Acceleration() const
{
	return mAcceleration[1];
}
Float32 CMPUCalib::getK3Acceleration() const
{
	return mAcceleration[2];
}
