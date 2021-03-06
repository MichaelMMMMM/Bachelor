/**
 * @file	C1DCompFilter.h
 * @author	Michael Meindl
 * @date	14.03.2017
 * @brief	Class to filter the X1-Value for the edge-balancing.
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
	const OutputType& getValue();
public:
	C1DCompFilter();
	C1DCompFilter(const C1DCompFilter&) = delete;
	C1DCompFilter& operator=(const C1DCompFilter&) = delete;
	~C1DCompFilter() = default;
private:
	OutputType mOutput;

	static constexpr Float32 sAlpha = 0.98F;
	static constexpr Float32 sTa	= 0.02F;
};

#endif
