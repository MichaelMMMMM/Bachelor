/**
 * @file	C1DStateReduction.cpp
 * @author	Michael Meindl
 * @date	18.04.2017
 * @brief	Method definitions for C1DStateReduction.
 */
#include "C1DStateReduction.h"

const C1DStateReduction::OutputType& C1DStateReduction::calcOutput(const C1DStateReduction::InputType& input)
{
	InputType copy = input;
	mOutput[1][1] = copy[2][1] - sPhiOffset;
	mOutput[2][1] = copy[5][1];
	mOutput[3][1] = copy[8][1];
	return mOutput;
}
const C1DStateReduction::OutputType& C1DStateReduction::getValue() const
{
	return mOutput;
}
