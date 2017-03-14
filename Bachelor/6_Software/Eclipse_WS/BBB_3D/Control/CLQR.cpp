/**
 * @file	CLQR.cpp
 * @author	Michael Meindl
 * @date	16.02.2017
 * @brief	Method definitions for CLQR.
 */
#include "CLQR.h"

const CLQR::OutputType& CLQR::calcOutput(const CLQR::InputType& input)
{



	mOutput.scalarAt(1,1) = input.scalarAt(1,1) * sF_TM1[0] + input.scalarAt(2,1) * sF_TM1[1] + input.scalarAt(3,1) * sF_TM1[2] +
			 	 	   	   	input.scalarAt(4,1) * sF_TM1[3] + input.scalarAt(5,1) * sF_TM1[4] + input.scalarAt(6,1) * sF_TM1[5] +
							input.scalarAt(7,1) * sF_TM1[6] + input.scalarAt(8,1) * sF_TM1[7] + input.scalarAt(9,1) * sF_TM1[8];
	mOutput.scalarAt(2,1) = input.scalarAt(1,1) * sF_TM2[0] + input.scalarAt(2,1) * sF_TM2[1] + input.scalarAt(3,1) * sF_TM2[2] +
			 	 	   	   	input.scalarAt(4,1) * sF_TM2[3] + input.scalarAt(5,1) * sF_TM2[4] + input.scalarAt(6,1) * sF_TM2[5] +
							input.scalarAt(7,1) * sF_TM2[6] + input.scalarAt(8,1) * sF_TM2[7] + input.scalarAt(9,1) * sF_TM2[8];
	mOutput.scalarAt(3,1) = input.scalarAt(1,1) * sF_TM3[0] + input.scalarAt(2,1) * sF_TM3[1] + input.scalarAt(3,1) * sF_TM3[2] +
			 	 	   	   	input.scalarAt(4,1) * sF_TM3[3] + input.scalarAt(5,1) * sF_TM3[4] + input.scalarAt(6,1) * sF_TM3[5] +
							input.scalarAt(7,1) * sF_TM3[6] + input.scalarAt(8,1) * sF_TM3[7] + input.scalarAt(9,1) * sF_TM3[8];

	mOutput.scalarAt(1,1) *= -1.0F;
	mOutput.scalarAt(2,1) *= -1.0F;
	mOutput.scalarAt(3,1) *= -1.0F;

	return mOutput;
}
const CLQR::OutputType& CLQR::getValue()
{
	return mOutput;
}
