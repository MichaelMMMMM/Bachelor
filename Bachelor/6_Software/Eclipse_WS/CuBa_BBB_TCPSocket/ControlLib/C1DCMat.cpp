/**
 * @file	C1DCMat.cpp
 * @author	Michael Meindl
 * @date	19.04.2017
 * @brief	Method definitions for C1DCMat.
 */
#include "C1DCMat.h"

const C1DCMat::OutputType& C1DCMat::calcOutput(const C1DCMat::InputType& input)
{
	mOutput = mC * input;
	return mOutput;
}
const C1DCMat::OutputType& C1DCMat::getValue() const
{
	return mOutput;
}
void C1DCMat::init(const std::string& cFile)
{
	mC = TMatrix<2U, 3U>(cFile);
}
