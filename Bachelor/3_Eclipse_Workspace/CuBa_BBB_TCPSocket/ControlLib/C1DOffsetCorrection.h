/**
 * @file	C1DOffsetCorrection.h
 * @author	Michael Meindl
 * @date	18.04.2017
 * @brief	Class to handle Offset-Compensation
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
	const OutputType& getValue() const;
	void setPhiOffset(Float32 offset);
	void setUKOffset(Float32 offset);
	void setUROffset(Float32 offset);
	void reset();
public:
	C1DOffsetCorrection();
	C1DOffsetCorrection(const C1DOffsetCorrection&) = delete;
	C1DOffsetCorrection& operator=(const C1DOffsetCorrection&) = delete;
	~C1DOffsetCorrection() = default;
private:
	OutputType mOutput;

	Float32	   mPhiOffset;
	Float32	   mUKOffset;
	Float32    mUROffset;
};

#endif
