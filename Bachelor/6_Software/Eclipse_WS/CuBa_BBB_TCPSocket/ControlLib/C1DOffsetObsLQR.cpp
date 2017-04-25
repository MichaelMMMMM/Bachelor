/**
 * @file	C1DOffsetObsLQR.cpp
 * @author	Michael Meindl
 * @date	19.04.2017
 * @brief	Method definitions for C1DOffsetObsLQR.
 */
#include "C1DOffsetObsLQR.h"
#include <iostream>

C1DOffsetObsLQR::C1DOffsetObsLQR() : mActive(false)
{
	mLQR.init("config/Edge_Kd.csv");
	mObserver.init("config/Edge_Ao.csv",
				   "config/Edge_Bo.csv",
				   "config/Edge_Co.csv",
				   "config/Edge_Lo.csv");
}
const C1DOffsetObsLQR::OutputType& C1DOffsetObsLQR::calcOutput(const C1DOffsetObsLQR::InputType& input)
{
	if(mActive)
	{
		auto y   = mCompFilter.calcOutput(input);
		auto x_o = mObserver.calcOutput(y);
		TRVector<3U> x;
		x[1][1]  = y[1][1] - x_o[4][1];
		x[2][1]  = y[2][1] - x_o[5][1];
		x[3][1]  = y[3][1] - x_o[6][1];
		mOutput  = mLQR.calcOutput(y);

	}
	return mOutput;
}
const C1DOffsetObsLQR::OutputType& C1DOffsetObsLQR::getValue() const
{
	return mOutput;
}
void C1DOffsetObsLQR::setObsU(const TRVector<1U>& u)
{
	mObserver.setU(u);
}
TRVector<3U> C1DOffsetObsLQR::getOffsets()
{
	auto x_o = mObserver.getValue();
	TRVector<3U> ret;
	ret[1][1] = x_o[4][1];
	ret[2][1] = x_o[5][1];
	ret[3][1] = x_o[6][1];
	return ret;
}
TRVector<3U> C1DOffsetObsLQR::getX()
{
	auto x_o = mObserver.getValue();
	auto y   = mCompFilter.getValue();
	TRVector<3U> ret;
	ret[1][1] = y[1][1] - x_o[4][1];
	ret[2][1] = y[2][1] - x_o[5][1];
	ret[3][1] = y[3][1] - x_o[6][1];
	return ret;
}
void C1DOffsetObsLQR::setControllerActive(bool active)
{
	mActive = active;
	mSaturation.setMaximum(active ?  0.11F : 0.0F);
	mSaturation.setMinimum(active ? -0.11F : 0.0F);
}