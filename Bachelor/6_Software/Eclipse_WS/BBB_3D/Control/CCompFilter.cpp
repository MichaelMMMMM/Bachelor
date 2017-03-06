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
const CStateData& CCompFilter::calcOutput(const CStateData& input)
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
			mOutput = input;
			mOutput.mGData.mG_k1 = -9.81F;
			mOutput.mGData.mG_k2 = 0.0F;
			mOutput.mGData.mG_k3 = 0.0F;
			mGInt[0] = -9.81F;
			mGInt[1] = 0.0F;
			mGInt[2] = 0.0F;
		}
		else
		{
			const Float32 g1 = mOutput.mGData.mG_k1 - 5.663806140750229F;
			const Float32 g2 = mOutput.mGData.mG_k2 - 5.663806140750229F;
			const Float32 g3 = mOutput.mGData.mG_k3 - 5.663806140750229F;

			const Float32& w1 = input.mUKData.mUK_k1;
			const Float32& w2 = input.mUKData.mUK_k2;
			const Float32& w3 = input.mUKData.mUK_k3;

			Float32 g__d[] = {0.0F, 0.0F, 0.0F};
			g__d[0] = g2*w3-g3*w2;
			g__d[1] = g3*w1-w3*g1;
			g__d[2] = g1*w2-g2*w1;

			mOutput.mGData.mG_k1 = sAlpha*(mOutput.mGData.mG_k1 + 0.02F*g__d[0])+(1-sAlpha)*input.mGData.mG_k1;
			mOutput.mGData.mG_k2 = sAlpha*(mOutput.mGData.mG_k2 + 0.02F*g__d[1])+(1-sAlpha)*input.mGData.mG_k2;
			mOutput.mGData.mG_k3 = sAlpha*(mOutput.mGData.mG_k3 + 0.02F*g__d[2])+(1-sAlpha)*input.mGData.mG_k3;
			mOutput.mUKData      = input.mUKData;
			mOutput.mURData      = input.mURData;
		}
		return mOutput;
	}
}
const CStateData& CCompFilter::getValue()
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
