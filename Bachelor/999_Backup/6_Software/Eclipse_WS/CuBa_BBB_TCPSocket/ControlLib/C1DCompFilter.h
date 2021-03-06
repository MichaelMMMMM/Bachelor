/**
 * @file	C1DCompFilter.h
 * @author	Michael Meindl
 * @date	18.04.2017
 * @brief	Complementary Filter for balancing on the edge.
 */
#ifndef C1DCOMPFILTER_H
#define C1DCOMPFILTER_H
#include "TMatrix.h"

class C1DCompFilter
{
public:
	using InputType		= TRVector<3U>;
	using OutputType	= TRVector<3U>;
public:
	const OutputType& calcOutput(const InputType& input);
	const OutputType& getValue() const;
public:
	C1DCompFilter();
	C1DCompFilter(const C1DCompFilter&) = delete;
	C1DCompFilter& operator=(const C1DCompFilter&) = delete;
	~C1DCompFilter() = default;
private:
	OutputType mOutput;

	bool 	   mFirstRun;
	static constexpr Float32 sAlpha = 0.98F;
};

#endif
