/**
 * @file	C3DOffsetCorrection.cpp
 * @author	Michael Meindl
 * @date	20.04.2017
 * @brief	Method definitions for C3DOffsetCorrection.
 */
#include "C3DOffsetCorrection.h"

C3DOffsetCorrection::C3DOffsetCorrection()
{
	mX_Offset[1][1] = sX1_Offset;
	mX_Offset[2][1] = sX2_Offset;
	mX_Offset[3][1] = sX3_Offset;
	mX_Offset[4][1] = sX4_Offset;
	mX_Offset[5][1] = sX5_Offset;
	mX_Offset[6][1] = sX6_Offset;
	mX_Offset[7][1] = sX7_Offset;
	mX_Offset[8][1] = sX8_Offset;
	mX_Offset[9][1] = sX9_Offset;

}
const C3DOffsetCorrection::OutputType& C3DOffsetCorrection::calcOutput(const C3DOffsetCorrection::InputType& input)
{
	mOutput = input + mX_Offset;

	return mOutput;
}
const C3DOffsetCorrection::OutputType& C3DOffsetCorrection::getValue() const
{
	return mOutput;
}
