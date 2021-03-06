/**
 * @file	C1DStateReduction.h
 * @author	Michael Meindl
 * @date	18.04.2017
 * @brief	Class to extract the state vector for balancing on an edge from the state vector for corner balancing.
 */
#ifndef C1DSTATEREDUCTION_H
#define C1DSTATEREDUCTION_H
#include "TMatrix.h"

class C1DStateReduction
{
public:
	using InputType		= TRVector<9U>;
	using OutputType	= TRVector<3U>;
public:
	const OutputType& calcOutput(const InputType& input);
	const OutputType& getValue() const;
public:
	C1DStateReduction() = default;
	C1DStateReduction(const C1DStateReduction&) = delete;
	C1DStateReduction& operator=(const C1DStateReduction&) = delete;
	~C1DStateReduction() = default;
private:
	OutputType mOutput;

	static constexpr Float32 sPhiOffset = 0.7854F;
};

#endif
