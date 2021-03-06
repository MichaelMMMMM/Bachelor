/**
 * @file	C3DCompFilter.cpp
 * @author	Michael Meindl
 * @date	20.04.2017
 * @brief	Method definitons for C3DCompFilter.
 */
#include "C3DCompFilter.h"

C3DCompFilter::C3DCompFilter() : mFirstRun(true)
{
	mDPhi[1][1] = 0.8660F;
	mDPhi[2][1] = 0.8660F;
	mDPhi[3][1] = 0.0F;
	mDPhi[2][1] = -0.707106781186547F;
	mDPhi[2][2] = 0.707106781186547F;
	mDPhi[2][3] = 0.0F;
	mDPhi[3][1] = -0.5F;
	mDPhi[3][2] = -0.5F;
	mDPhi[3][3] = 1.0F;
}
const C3DCompFilter::OutputType& C3DCompFilter::calcOutput(const C3DCompFilter::InputType& input)
{
	if(mFirstRun == true)
	{
		mFirstRun = false;
		mOutput   = input;
	}
	else
	{
		TRVector<3U> uk;
		auto copy = input;
		uk[1][1] = copy[4][1];
		uk[2][1] = copy[5][1];
		uk[3][1] = copy[6][1];
		TRVector<3U> dPhi = mDPhi * uk;

		mOutput[1][1] = 0.0F;
		mOutput[2][1] = sAlpha * (mOutput[2][1] + 0.02F * dPhi[2][1]) + (1.0F - sAlpha) * copy[2][1];
		mOutput[3][1] = sAlpha * (mOutput[3][1] + 0.02F * dPhi[3][1]) + (1.0F - sAlpha) * copy[3][1];
//		mOutput[2][1] = copy[2][1];
//		mOutput[3][1] = copy[3][1];
		mOutput[4][1] = copy[4][1];
		mOutput[5][1] = copy[5][1];
		mOutput[6][1] = copy[6][1];
		mOutput[7][1] = copy[7][1];
		mOutput[8][1] = copy[8][1];
		mOutput[9][1] = copy[9][1];
	}
	return mOutput;
}
const C3DCompFilter::OutputType& C3DCompFilter::getValue() const
{
	return mOutput;
}
void C3DCompFilter::reset()
{
	mFirstRun = true;
}
