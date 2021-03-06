/**
 * @file	C1DOffsetObsLQR.cpp
 * @author	Michael Meindl
 * @date	19.04.2017
 * @brief	Method definitions for C1DOffsetObsLQR.
 */
#include "C1DOffsetObsLQR.h"
#include <iostream>

C1DOffsetObsLQR::C1DOffsetObsLQR() : mActive(false), mPhiOffFilter(0.05F),
								     mUKOffFilter(0.05F), mUROffFilter(0.05F)
{
	mLQR.init("config/Edge_Kd.csv");
	mObserver.init("config/Edge_Ao.csv",
				   "config/Edge_Bo.csv",
				   "config/Edge_Co.csv",
				   "config/Edge_Lo.csv");
}
void C1DOffsetObsLQR::updateConfig()
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
		auto phi_off = mPhiOffFilter.calculateOutput(x_o[1][1]);
		auto uk_off  = mUKOffFilter.calculateOutput(x_o[2][1]);
		auto ur_off  = mUROffFilter.calculateOutput(x_o[3][1]);
		x[1][1]  = y[1][1] - phi_off;
		x[2][1]  = y[2][1] - uk_off;
		x[3][1]  = y[3][1] - ur_off;
		mOutput  = mLQR.calcOutput(x);
		std::cout << std::setw(10) << phi_off << std::setw(10) << uk_off << std::setw(10) << ur_off << std::endl;
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
	TRVector<3U> ret;
	ret[1][1] = mPhiOffFilter.getValue();
	ret[2][1] = mUKOffFilter.getValue();
	ret[3][1] = mUROffFilter.getValue();
	return ret;
}
TRVector<3U> C1DOffsetObsLQR::getX()
{
	auto y   = mCompFilter.getValue();
	TRVector<3U> ret;
	ret[1][1] = y[1][1] - mPhiOffFilter.getValue();
	ret[2][1] = y[2][1] - mUKOffFilter.getValue();
	ret[3][1] = y[3][1] - mUROffFilter.getValue();
	return ret;
}
void C1DOffsetObsLQR::setControllerActive(bool active)
{
	mActive = active;
	mSaturation.setMaximum(active ?  0.11F : 0.0F);
	mSaturation.setMinimum(active ? -0.11F : 0.0F);
}
