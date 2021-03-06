/**
 * @file	CF1Calib.h
 * @author	Michael Meindl
 * @date	18.04.2017
 * @brief	Class to handle sensor calibration using 1:1 polynomials.
 */
#ifndef CF1CALIB_H
#define CF1CALIB_H
#include "CPoly1F1.h"
#include "CSensorData.h"

class CF1Calib
{
public:
	using InputType		= CSensorData;
	using OutputType	= CSensorFloatData;
public:
	const OutputType& calcOutput(const InputType& input);
	const OutputType& getValue() const;
public:
	CF1Calib();
	CF1Calib(const CF1Calib&) = delete;
	CF1Calib& operator=(const CF1Calib&) = delete;
	~CF1Calib() = default;
private:
	OutputType	mOutput;

	CPoly1F1 mST1_A_Poly[3];
	CPoly1F1 mST2_A_Poly[3];
	CPoly1F1 mST3_A_Poly[3];
	CPoly1F1 mST4_A_Poly[3];

	CPoly1F1 mS1_W_Poly[3];
	CPoly1F1 mS2_W_Poly[3];
	CPoly1F1 mS3_W_Poly[3];
	CPoly1F1 mS4_W_Poly[3];
	CPoly1F1 mS5_W_Poly[3];
	CPoly1F1 mS6_W_Poly[3];

	CPoly1F1 mADC_Poly[3];
};

#endif
