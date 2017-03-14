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
			const Float32 g1 = mOutput.scalarAt(1,1) - 5.663806140750229F;
			const Float32 g2 = mOutput.scalarAt(2,1) - 5.663806140750229F;
			const Float32 g3 = mOutput.scalarAt(3,1) - 5.663806140750229F;

			const Float32& w1 = input.scalarAt(4,1);
			const Float32& w2 = input.scalarAt(5,1);
			const Float32& w3 = input.scalarAt(6,1);

			Float32 g__d[] = {0.0F, 0.0F, 0.0F};
			g__d[0] = g2*w3-g3*w2;
			g__d[1] = g3*w1-w3*g1;
			g__d[2] = g1*w2-g2*w1;

			mOutput.scalarAt(1,1) = sAlpha*(mOutput.scalarAt(1,1) + 0.02F*g__d[0])+(1-sAlpha)*input.scalarAt(1,1);
			mOutput.scalarAt(2,1) = sAlpha*(mOutput.scalarAt(2,1) + 0.02F*g__d[1])+(1-sAlpha)*input.scalarAt(2,1);
			mOutput.scalarAt(3,1) = sAlpha*(mOutput.scalarAt(3,1) + 0.02F*g__d[2])+(1-sAlpha)*input.scalarAt(3,1);
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
