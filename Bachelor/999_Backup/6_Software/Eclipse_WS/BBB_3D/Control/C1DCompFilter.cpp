/**
 * @file	C1DCompFilter.cpp
 * @author	Michael Meindl
 * @date	14.03.2017
 * @brief	Method definitons for C1DCompFilter.
 */
#include "C1DCompFilter.h"

C1DCompFilter::C1DCompFilter()
{

}
const C1DCompFilter::OutputType& C1DCompFilter::calcOutput(const C1DCompFilter::InputType& input)
{
	mOutput.scalarAt(1,1) = sAlpha * (mOutput.scalarAt(1,1) + sTa * input.scalarAt(2,1) ) + ( 1.0F - sAlpha) * input.scalarAt(1,1);
	mOutput.scalarAt(2,1) = input.scalarAt(2,1);
	mOutput.scalarAt(3,1) = input.scalarAt(3,1);
	return mOutput;
}
const C1DCompFilter::OutputType& C1DCompFilter::getValue()
{
	return mOutput;
}
