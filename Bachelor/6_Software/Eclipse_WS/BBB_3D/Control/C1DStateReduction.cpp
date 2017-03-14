/**
 * @file	C1DStateReduction.cpp
 * @author	Michael Meindl
 * @date	14.03.2017
 * @brief	Method defintions for C1DStateReduction.
 */
#include "C1DStateReduction.h"

C1DStateReduction::C1DStateReduction()
{

}
const C1DStateReduction::OutputType& C1DStateReduction::calcOutput(const C1DStateReduction::InputType& input)
{
	mOutput.scalarAt(1,1) = sCos45deg * ( input.scalarAt(2,1) + input.scalarAt(3,1) );
	mOutput.scalarAt(2,1) = input.scalarAt(4,1);
	mOutput.scalarAt(3,1) = input.scalarAt(7,1);
	return mOutput;
}
const C1DStateReduction::OutputType& C1DStateReduction::getValue()
{
	return mOutput;
}
