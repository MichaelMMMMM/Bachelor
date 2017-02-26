/**
 * @file	CDT1.cpp
 * @author	Michael Meindl
 * @date	10.1.2017
 * @brief	Method definitions for CDT1.
 */
#include "CDT1.h"

CDT1::CDT1(Float32 f_G) : mFirstRun(true),
						  mLowPass(f_G)
{

}
Float32 CDT1::calculateOutput(Float32 input)
{
	if(mFirstRun == true)
	{
		mFirstRun = false;
		mLowPass.calculateOutput(input);
		return input;
	}
	return input - mLowPass.calculateOutput(input);
}
