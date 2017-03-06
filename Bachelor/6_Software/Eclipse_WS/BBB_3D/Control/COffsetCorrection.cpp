/**
 * @file	COffsetCorrection.cpp
 * @author	Michael Meindl
 * @date	17.02.2017
 * @brief	Method definitions for COffsetCorrection.
 */
#include "COffsetCorrection.h"

COffsetCorrection::COffsetCorrection() : mActiveFlag(false),
										 mG1PT1(sHP_GF),
									     mG2PT1(sHP_GF),
										 mG3PT1(sHP_GF),
										 mHPFlag(false)
{

}
const CStateData& COffsetCorrection::calcOutput(const CStateData& input)
{
	if(mActiveFlag == true)
	{
		mOutput.mGData.mG_k1 = input.mGData.mG_k1 - sG_0 + sG_k1_Offset;
		mOutput.mGData.mG_k2 = input.mGData.mG_k2 - sG_0 + sG_k2_Offset;
		mOutput.mGData.mG_k3 = input.mGData.mG_k3 - sG_0 + sG_k3_Offset;
		mOutput.mUKData.mUK_k1 = input.mUKData.mUK_k1 + sUK_k1_Offset;
		mOutput.mUKData.mUK_k2 = input.mUKData.mUK_k2 + sUK_k2_Offset;
		mOutput.mUKData.mUK_k3 = input.mUKData.mUK_k3 + sUK_k3_Offset;

		mOutput.mURData = input.mURData;

		if(mHPFlag == true)
		{
			mOutput.mGData.mG_k1 -= mG1PT1.calculateOutput(mOutput.mGData.mG_k1);
			mOutput.mGData.mG_k2 -= mG2PT1.calculateOutput(mOutput.mGData.mG_k2);
			mOutput.mGData.mG_k3 -= mG3PT1.calculateOutput(mOutput.mGData.mG_k3);
		}
	}
	else
	{
		mOutput = input;
	}

	return mOutput;
}
void COffsetCorrection::activate()
{
	mActiveFlag = true;
}
void COffsetCorrection::deactive()
{
	mActiveFlag = false;
}
const CStateData& COffsetCorrection::getValue()
{
	return mOutput;
}
void COffsetCorrection::reset()
{
	mG1PT1.reset();
	mG2PT1.reset();
	mG3PT1.reset();
}
void COffsetCorrection::enableHighpass()
{
	mHPFlag = true;
	this->reset();
}
void COffsetCorrection::disableHighpass()
{
	mHPFlag = false;
}
