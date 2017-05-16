/**
 * @file	CCompFilter.cpp
 * @author	Michael Meindl
 * @date	16.02.2017
 * @brief	Method definitions for CCompFilter.
 */
#include "CCompFilter.h"

CCompFilter::CCompFilter() : mActiveFlag(false),
							 mFirstRun(true),
							 mUR1Filter(15.0F),
							 mUR2Filter(15.0F),
							 mUR3Filter(15.0F),
							 mGInt{-9.81F, 0.0F, 0.0F}
{

	mDPhi.scalarAt(1,1) = 0.8660F;
	mDPhi.scalarAt(1,2) = 0.8660F;
	mDPhi.scalarAt(1,3) = 0.0F;
	mDPhi.scalarAt(2,1) = -0.707106781186547F;
	mDPhi.scalarAt(2,2) = 0.707106781186547F;
	mDPhi.scalarAt(2,3) = 0.0F;
	mDPhi.scalarAt(3,1) = -0.5F;
	mDPhi.scalarAt(3,2) = -0.5F;
	mDPhi.scalarAt(3,3) = 1.0F;
}
const CCompFilter::OutputType& CCompFilter::calcOutput(const CCompFilter::InputType& input)
{
	if(mActiveFlag == false)
	{
		mOutput = input;
		return mOutput;
	}
	else
	{
		if(mFirstRun == true)
		{
			mFirstRun = false;
			mOutput   = input;
		}
		else
		{
			TRVector<3U> uk;
			uk.scalarAt(1,1) = input.scalarAt(4,1);
			uk.scalarAt(2,1) = input.scalarAt(5,1);
			uk.scalarAt(3,1) = input.scalarAt(6,1);
			TRVector<3U> phi__d = mDPhi * uk;
			//mOutput.scalarAt(1,1) = sAlpha*(mOutput.scalarAt(1,1) + 0.02F*phi__d.scalarAt(1,1)) + (1.0F-sAlpha)*input.scalarAt(1,1);
			mOutput.scalarAt(1,1) = 0.0F;
			mOutput.scalarAt(2,1) = sAlpha*(mOutput.scalarAt(2,1) + 0.02F*phi__d.scalarAt(2,1)) + (1.0F-sAlpha)*input.scalarAt(2,1);
			mOutput.scalarAt(3,1) = sAlpha*(mOutput.scalarAt(3,1) + 0.02F*phi__d.scalarAt(3,1)) + (1.0F-sAlpha)*input.scalarAt(3,1);
			mOutput.scalarAt(4,1) = input.scalarAt(4,1);
			mOutput.scalarAt(5,1) = input.scalarAt(5,1);
			mOutput.scalarAt(6,1) = input.scalarAt(6,1);
			mOutput.scalarAt(7,1) = input.scalarAt(7,1);
			mOutput.scalarAt(8,1) = input.scalarAt(8,1);
			mOutput.scalarAt(9,1) = input.scalarAt(9,1);

		}
		return mOutput;
	}
}
const CCompFilter::OutputType& CCompFilter::getValue()
{
	return mOutput;
}
void CCompFilter::reset()
{
	mFirstRun = true;
}
void CCompFilter::activate()
{
	mActiveFlag = true;
}
void CCompFilter::deactivate()
{
	mActiveFlag = false;
	mFirstRun   = true;
}
