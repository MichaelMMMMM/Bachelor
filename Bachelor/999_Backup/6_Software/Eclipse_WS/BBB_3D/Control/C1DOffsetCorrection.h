/**
 * @file	C1DOffsetCorrection.h
 * @author	Michael Meindl
 * @date	14.03.2017
 * @brief	Class to correct the Offsets of the 1D-State-Vector.
 */
#ifndef C1DOFFSETCORRECTION_H
#define C1DOFFSETCORRECTION_H
#include "TMatrix.h"

class C1DOffsetCorrection
{
public:
	using InputType		= TRVector<3U>;
	using OutputType	= TRVector<3U>;
public:
	const OutputType& calcOutput(const InputType& input);
	const OutputType& getValue();
	void setActiveFlag(bool flag);
public:
	C1DOffsetCorrection();
	C1DOffsetCorrection(const C1DOffsetCorrection&) = delete;
	C1DOffsetCorrection& operator=(const C1DOffsetCorrection&) = delete;
	~C1DOffsetCorrection() = default;
private:
	OutputType mOutput;
	OutputType mOffset;
	bool 	   mActiveFlag;

	static constexpr Float32 sX1Offset = -0.785398163397448F - 0.029F;
	static constexpr Float32 sX2Offset = 0.001364F;
	static constexpr Float32 sX3Offset = 0.702F;
};

#endif
