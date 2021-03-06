/**
 * @file	C3DStateEstiamte.cpp
 * @author	Michael Meindl
 * @date	18.04.2017
 * @brief	Method definitions for C3DStateEstimate.
 */
#include "C3DStateEstimate.h"
#include <cmath>
#include <iostream>
#include <ostream>
#include <fstream>
using namespace std;

C3DStateEstimate::C3DStateEstimate() : mBx{0.0F}, mBy{0.0F}, mBz{0.0F}
{
	fstream stream;
	stream.open("config/accel_compensation_bx.csv");
	string data;
	stream >> data;
	for(int i = 0; i < 4; i++)
	{
		std::string tmp = data.substr(0, data.find(","));
		mBx[i] = std::stof(tmp);
		data = data.substr(data.find(",")+1);
	}
	stream.close();

	stream.open("config/accel_compensation_by.csv");
	for(int i = 0; i < 4; i++)
	{
		std::string tmp = data.substr(0, data.find(","));
		mBy[i] = std::stof(tmp);
		data = data.substr(data.find(",")+1);
	}
	stream.close();

	stream.open("config/accel_compensation_bz.csv");
	for(int i = 0; i < 4; i++)
	{
		std::string tmp = data.substr(0, data.find(","));
		mBz[i] = std::stof(tmp);
		data = data.substr(data.find(",")+1);
	}
	stream.close();
}
const C3DStateEstimate::OutputType& C3DStateEstimate::calcOutput(const C3DStateEstimate::InputType& input)
{
	this->estimatePhi(input);
	this->estimateUK(input);
	this->estimateUR(input);

	return mOutput;
}
void C3DStateEstimate::estimatePhi(const C3DStateEstimate::InputType& input)
{
	Float32 g_k1 = (input.mST1_A[0] * mBx[0] + input.mST2_A[0] * mBx[1] +
				    input.mST3_A[0] * mBx[2] + input.mST4_A[0] * mBx[3]) / (mBx[0] + mBx[1] + mBx[2] + mBx[3]);
	Float32 g_k2 = (input.mST1_A[1] * mBy[0] + input.mST2_A[1] * mBy[1] +
				    input.mST3_A[1] * mBy[2] + input.mST4_A[1] * mBy[3]) / (mBy[0] + mBy[1] + mBy[2] + mBy[3]);
	Float32 g_k3 = (input.mST1_A[2] * mBz[0] + input.mST2_A[2] * mBz[1] +
				    input.mST3_A[2] * mBz[2] + input.mST4_A[2] * mBz[3]) / (mBz[0] + mBz[1] + mBz[2] + mBz[3]);
	Float32 g_n  = sqrtf(g_k1*g_k1 + g_k2*g_k2 + g_k3*g_k3);
	mOutput[1][1] = 0.0F;
	mOutput[2][1] = -asinf(g_k3/g_n);
	mOutput[3][1] = -atan2f(g_k2/g_n, g_k1/g_n);
	if(mOutput[3][1] < (-sPi/2.0F))
	{
		mOutput[3][1] = mOutput[3][1] + sPi;
	}
	else if(mOutput[3][1] > (sPi/2.0F))
	{
		mOutput[3][1] = mOutput[3][1] - sPi;
	}
}
void C3DStateEstimate::estimateUK(const C3DStateEstimate::InputType& input)
{
	mOutput[4][1] = (input.mS1_W[1] + input.mS2_W[1] + input.mS3_W[2] +
				     input.mS4_W[2] + input.mS5_W[0] + input.mS6_W[0]) / 6.0F;
	mOutput[5][1] = (input.mS1_W[0] + input.mS2_W[0] + input.mS3_W[1] +
				     input.mS4_W[1] + input.mS5_W[2] + input.mS6_W[2]) / 6.0F;
	mOutput[6][1] = (input.mS1_W[2] + input.mS2_W[2] + input.mS3_W[0] +
				     input.mS4_W[0] + input.mS5_W[1] + input.mS6_W[1]) / 6.0F;
}
void C3DStateEstimate::estimateUR(const C3DStateEstimate::InputType& input)
{
	for(UInt32 n = 0U; n < 3U; n++)
	{
		mOutput[7U+n][1] = input.mADC[n] + mOutput[4U+n][1];
	}
}
const C3DStateEstimate::OutputType& C3DStateEstimate::getValue() const
{
	return mOutput;
}
