/**
 * @file	C3DCompFilter.h
 * @author	Michael Meindl
 * @date	20.04.2017
 * @brief	Complementary-Filter for the Corner-Balancing State-Vector.
 */
#ifndef C3DCOMPFILTER_H
#define C3DCOMPFILTER_H
#include "TMatrix.h"

class C3DCompFilter
{
public:
	using InputType		= TRVector<9U>;
	using OutputType	= TRVector<9U>;
public:
	const OutputType& calcOutput(const InputType& input);
	const OutputType& getValue() const;
	void reset();
public:
	C3DCompFilter();
	C3DCompFilter(const C3DCompFilter&) = delete;
	C3DCompFilter& operator=(const C3DCompFilter&) = delete;
	~C3DCompFilter() = default;
private:
	OutputType mOutput;

	bool 		    mFirstRun;
	TMatrix<3U, 3U> mDPhi;
	static constexpr Float32 sAlpha = 0.98F;
};

#endif
