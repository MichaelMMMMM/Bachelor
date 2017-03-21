/**
 * @file	C1DOffsetCorrection.cpp
 * @author	Michael Meindl
 * @date	14.03.2017
 * @brief	Method definitions for C1DOffsetCorrection.
 */
#include "C1DOffsetCorrection.h"
#include <iostream>

C1DOffsetCorrection::C1DOffsetCorrection() : mActiveFlag(true)
{
	mOffset.scalarAt(1,1) = sX1Offset;
	mOffset.scalarAt(2,1) = sX2Offset;
	mOffset.scalarAt(3,1) = sX3Offset;
}
const C1DOffsetCorrection::OutputType& C1DOffsetCorrection::calcOutput(const C1DOffsetCorrection::InputType& input)
{
	OutputType inputCopy = input;
	mOutput = mActiveFlag ? inputCopy + mOffset : inputCopy;
	return mOutput;
}
const C1DOffsetCorrection::OutputType& C1DOffsetCorrection::getValue()
{
	return mOutput;
}
void C1DOffsetCorrection::setActiveFlag(bool flag)
{
	mActiveFlag = flag;
	std::cout << "[*] Control-Comp: 1D-Offset-Correction Active-Flag: " << flag << std::endl;
}
