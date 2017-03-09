/**
 * @file	CLQR.cpp
 * @author	Michael Meindl
 * @date	16.02.2017
 * @brief	Method definitions for CLQR.
 */
#include "CLQR.h"

const CTorqueData& CLQR::calcOutput(const CStateData& input)
{
	mOutput.mTorque1 = (input.mGData.mG_k1-0.08F)   * sF_TM1[0] + (input.mGData.mG_k2-0.08F)   * sF_TM1[1] + (input.mGData.mG_k3+0.01F)   * sF_TM1[2] +
			 	 	   input.mUKData.mUK_k1 * sF_TM1[3] + input.mUKData.mUK_k2 * sF_TM1[4] + input.mUKData.mUK_k3 * sF_TM1[5] +
					   input.mURData.mUR_k1 * sF_TM1[6] + input.mURData.mUR_k2 * sF_TM1[7] + input.mURData.mUR_k3 * sF_TM1[8];
	mOutput.mTorque2 = (input.mGData.mG_k1-0.08F)   * sF_TM2[0] + (input.mGData.mG_k2-0.08F)   * sF_TM2[1] + (input.mGData.mG_k3+0.01F)   * sF_TM2[2] +
			 	 	   input.mUKData.mUK_k1 * sF_TM2[3] + input.mUKData.mUK_k2 * sF_TM2[4] + input.mUKData.mUK_k3 * sF_TM2[5] +
					   input.mURData.mUR_k1 * sF_TM2[6] + input.mURData.mUR_k2 * sF_TM2[7] + input.mURData.mUR_k3 * sF_TM2[8];
	mOutput.mTorque3 = (input.mGData.mG_k1-0.08F)   * sF_TM3[0] + (input.mGData.mG_k2-0.08F)   * sF_TM3[1] + (input.mGData.mG_k3+0.01F)   * sF_TM3[2] +
			 	 	   input.mUKData.mUK_k1 * sF_TM3[3] + input.mUKData.mUK_k2 * sF_TM3[4] + input.mUKData.mUK_k3 * sF_TM3[5] +
					   input.mURData.mUR_k1 * sF_TM3[6] + input.mURData.mUR_k2 * sF_TM3[7] + input.mURData.mUR_k3 * sF_TM3[8];

	mOutput.mTorque1 *= -1.0F;
	mOutput.mTorque2 *= -1.0F;
	mOutput.mTorque3 *= -1.0F;

	return mOutput;
}
const CTorqueData& CLQR::getValue()
{
	return mOutput;
}