/**
 * @file	C1DCompFilter.cpp
 * @author	Michael Meindl
 * @date	18.04.2017
 * @brief	Method definitions for C1DCompFilter.
 */
#include "C1DCompFilter.h"

C1DCompFilter::C1DCompFilter() : mFirstRun(true)
{

}
const C1DCompFilter::OutputType& C1DCompFilter::calcOutput(const C1DCompFilter::InputType& input)
{
	if(mFirstRun == true)
	{
		mFirstRun = false;
		mOutput = input;
	}
	else
	{
		OutputType copy = input;
		Float32 recent_phi = mOutput[1][1];
		mOutput[1][1]   = sAlpha * (recent_phi + 0.02F * copy[2][1]) + (1.0F - sAlpha)*copy[1][1];
		mOutput[2][1]   = copy[2][1];
		mOutput[3][1]   = copy[3][1];
	}
	return mOutput;
}
const C1DCompFilter::OutputType& C1DCompFilter::getValue() const
{
	return mOutput;
}
