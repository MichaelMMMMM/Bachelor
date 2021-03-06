/**
 * @file	C1DStateReduction.cpp
 * @author	Michael Meindl
 * @date	14.03.2017
 * @brief	Method defintions for C1DStateReduction.
 */
#include "C1DStateReduction.h"
#include <cmath>

C1DStateReduction::C1DStateReduction()
{

}
const C1DStateReduction::OutputType& C1DStateReduction::calcOutput(const C1DStateReduction::InputType& input)
{
	Float32 g1 = input.scalarAt(1,1);
	Float32 g2 = input.scalarAt(2,1);
	Float32 g3 = input.scalarAt(3,1);

	Float32 gAbs = sqrt(g1*g1+g2*g2+g3*g3);
	mOutput.scalarAt(1,1) = input.scalarAt(2U, 1U);
	mOutput.scalarAt(2,1) = input.scalarAt(5,1);
	mOutput.scalarAt(3,1) = input.scalarAt(8,1);
	return mOutput;
}
const C1DStateReduction::OutputType& C1DStateReduction::getValue()
{
	return mOutput;
}
