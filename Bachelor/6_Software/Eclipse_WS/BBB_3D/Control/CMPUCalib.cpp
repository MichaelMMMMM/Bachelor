/**
 * @file	CMPUCalib.cpp
 * @author	Michael Meindl
 * @date	19.02.2017
 * @brief	Method definitions for CMPUCalib.
 */
#include "CMPUCalib.h"
#include <ostream>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

CMPUCalib::CMPUCalib(const std::string& acalib_file,
					 const std::string& gcalib_file) : mSAMatrix{0.0F},
													   mAOffsetVector{0.0F},
													   mAcceleration{0.0F},
													   mSGMatrix{0.0F},
													   mGOffsetVector{0.0F},
													   mAngularVelocity{0.0F}
{
	ifstream stream;
	stream.open(acalib_file);
	string data;

	for(int k = 0; k < 3; k++)
	{
		stream >> data;
		for(int n = 0; n < 4; n++)
		{
			string tmp = data.substr(0, data.find(","));
			if(n == 3)
			{
				mAOffsetVector[k] = std::stof(tmp);
			}
			else
			{
				mSAMatrix[k][n] = std::stof(tmp);
			}
			data = data.substr(data.find(",")+1);
		}
	}

	stream.close();

	stream.open(gcalib_file);

	for(int k = 0; k < 3; k++)
	{
		stream >> data;
		for(int n = 0; n < 4; n++)
		{
			string tmp = data.substr(0, data.find(","));
			if(n == 3)
			{
				mGOffsetVector[k] = std::stof(tmp);
			}
			else
			{
				mSGMatrix[k][n] = std::stof(tmp);
			}
			data = data.substr(data.find(",")+1);
		}
	}

	int bp = 23;
}
void CMPUCalib::calibrate(const CMPUData& data)
{
	Float32 x = static_cast<Float32>(data.mA_x);
	Float32 y = static_cast<Float32>(data.mA_y);
	Float32 z = static_cast<Float32>(data.mA_z);

	mAcceleration[0] = mSAMatrix[0][0] * x +
					   mSAMatrix[0][1] * y +
				 	   mSAMatrix[0][2] * z +
					   mAOffsetVector[0];
	mAcceleration[1] = mSAMatrix[1][0] * x +
					   mSAMatrix[1][1] * y +
					   mSAMatrix[1][2] * z +
					   mAOffsetVector[1];
	mAcceleration[2] = mSAMatrix[2][0] * x +
					   mSAMatrix[2][1] * y +
					   mSAMatrix[2][2] * z +
					   mAOffsetVector[2];

	x = static_cast<Float32>(data.mW_x);
	y = static_cast<Float32>(data.mW_y);
	z = static_cast<Float32>(data.mW_z);

	mAngularVelocity[0] = mSGMatrix[0][0] * x +
					      mSGMatrix[0][1] * y +
				 	      mSGMatrix[0][2] * z +
					      mGOffsetVector[0];
	mAngularVelocity[1] = mSGMatrix[1][0] * x +
					      mSGMatrix[1][1] * y +
					      mSGMatrix[1][2] * z +
					      mGOffsetVector[1];
	mAngularVelocity[2] = mSGMatrix[2][0] * x +
					      mSGMatrix[2][1] * y +
					      mSGMatrix[2][2] * z +
					      mGOffsetVector[2];
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
Float32 CMPUCalib::getK1AngularVelocity() const
{
	return mAngularVelocity[0];
}
Float32 CMPUCalib::getK2AngularVelocity() const
{
	return mAngularVelocity[1];
}
Float32 CMPUCalib::getK3AngularVelocity() const
{
	return mAngularVelocity[2];
}
