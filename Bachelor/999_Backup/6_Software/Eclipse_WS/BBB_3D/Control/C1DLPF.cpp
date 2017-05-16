/**
 * @file	C1DLPF.cpp
 * @author	Michael Meindl
 * @date	14.03.2017
 * @brief	Method defintions for C1DLPF.
 */
#include "C1DLPF.h"

C1DLPF::C1DLPF() : mX1LPF(sGF_X1)
{

}
const C1DLPF::OutputType& C1DLPF::calcOutput(const C1DLPF::InputType& input)
{
	mOutput = input;
	mOutput.scalarAt(1,1) = mX1LPF.calculateOutput(mOutput.scalarAt(1,1));
	return mOutput;
}
const C1DLPF::OutputType&C1DLPF::getValue()
{
	return mOutput;
}
