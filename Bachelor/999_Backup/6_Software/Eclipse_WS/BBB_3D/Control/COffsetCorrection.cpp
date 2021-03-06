/**
 * @file	COffsetCorrection.cpp
 * @author	Michael Meindl
 * @date	17.02.2017
 * @brief	Method definitions for COffsetCorrection.
 */
#include "COffsetCorrection.h"

COffsetCorrection::COffsetCorrection() : mActiveFlag(false)
{

}
const COffsetCorrection::OutputType& COffsetCorrection::calcOutput(const COffsetCorrection::InputType& input)
{
	if(mActiveFlag == true)
	{
		mOutput.scalarAt(1,1) = input.scalarAt(1,1) + sG_k1_Offset;
		mOutput.scalarAt(2,1) = input.scalarAt(2,1) + sG_k2_Offset;
		mOutput.scalarAt(3,1) = input.scalarAt(3,1) + sG_k3_Offset - sPi;
		if(mOutput.scalarAt(3,1) < -5.0F)
		{
			mOutput.scalarAt(3,1) = mOutput.scalarAt(3,1) + 2*sPi;
		}
		mOutput.scalarAt(4,1) = input.scalarAt(4,1) + sUK_k1_Offset;
		mOutput.scalarAt(5,1) = input.scalarAt(5,1) + sUK_k2_Offset;
		mOutput.scalarAt(6,1) = input.scalarAt(6,1) + sUK_k3_Offset;
		mOutput.scalarAt(7,1) = input.scalarAt(7,1) + sUR_k1_Offset;
		mOutput.scalarAt(8,1) = input.scalarAt(8,1) + sUR_k2_Offset;
		mOutput.scalarAt(9,1) = input.scalarAt(9,1) + sUR_k3_Offset;
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
const COffsetCorrection::OutputType& COffsetCorrection::getValue()
{
	return mOutput;
}
