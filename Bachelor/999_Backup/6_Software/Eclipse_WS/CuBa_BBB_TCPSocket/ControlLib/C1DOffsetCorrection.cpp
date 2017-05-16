/**
 * @file	C1DOffsetCorrection.h
 * @author	Michael Meindl
 * @date	19.04.2017
 * @brief	Method definitions for C1DOffsetCorrection;
 */
#include "C1DOffsetCorrection.h"

C1DOffsetCorrection::C1DOffsetCorrection() : mPhiOffset(0.0F),
											 mUKOffset(0.0F),
											 mUROffset(0.0F)
{

}
const C1DOffsetCorrection::OutputType& C1DOffsetCorrection::calcOutput(const C1DOffsetCorrection::InputType& input)
{
	auto copy = input;
	mOutput[1][1] = copy[1][1] + mPhiOffset;
	mOutput[2][1] = copy[2][1] + mUKOffset;
	mOutput[3][1] = copy[3][1] + mUROffset;
	return mOutput;
}
const C1DOffsetCorrection::OutputType& C1DOffsetCorrection::getValue() const
{
	return mOutput;
}
void C1DOffsetCorrection::setPhiOffset(Float32 offset)
{
	mPhiOffset = offset;
}
void C1DOffsetCorrection::setUKOffset(Float32 offset)
{
	mUKOffset  = offset;
}
void C1DOffsetCorrection::setUROffset(Float32 offset)
{
	mUROffset  = offset;
}
void C1DOffsetCorrection::reset()
{
	mPhiOffset = 0.0F;
	mUKOffset  = 0.0F;
	mUROffset  = 0.0F;
}
