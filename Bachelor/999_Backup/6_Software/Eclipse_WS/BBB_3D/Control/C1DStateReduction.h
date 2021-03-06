/**
 * @file	C1DStateReduction.h
 * @author	Michael Meindl
 * @date	14.03.2017
 * @brief	Takes the full state vector of the conrner model and transforms it to the edge case.
 */
#ifndef C1DSTATEREDUCTION_H
#define C1DSTATEREDUCTION_H
#include "TMatrix.h"

class C1DStateReduction
{
public:
	using InputType	  = TRVector<9U>;
	using OutputType  = TRVector<3U>;
public:
	const OutputType& calcOutput(const InputType& input);
	const OutputType& getValue();
public:
	C1DStateReduction();
	C1DStateReduction(const C1DStateReduction&) = delete;
	C1DStateReduction& operator=(const C1DStateReduction&) = delete;
	~C1DStateReduction() = default;
private:
	OutputType mOutput;
	static constexpr Float32 sCos45deg = 0.707106781186547F;
};

#endif
