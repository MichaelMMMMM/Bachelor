/**
 * @file	CPT1.cpp
 * @author	Michael Meindl
 * @date	10.1.2017
 * @brief	Method definitions for CPT1.
 */
#include "CPT1.h"

CPT1::CPT1(float f_G) : mFirstRun(true),
						mFactor(1.0F/(f_G*0.02F)),
						mRecentOutput(0.0F)
{

}
Float32 CPT1::calculateOutput(Float32 input)
{
	if(mFirstRun == true)
	{
		mFirstRun = false;
		mRecentOutput = input;
		return mRecentOutput;
	}
	mRecentOutput = (input + mRecentOutput*mFactor)/(1.0F+mFactor);
	return mRecentOutput;
}
void CPT1::reset()
{
	mFirstRun = true;
}
Float32 CPT1::getValue() const
{
	return mRecentOutput;
}
