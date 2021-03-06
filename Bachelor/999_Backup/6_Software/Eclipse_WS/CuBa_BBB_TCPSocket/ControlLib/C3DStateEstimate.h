/**
 * @file	C3DStateEstimate.h
 * @author	Michael Meindl
 * @date	18.04.2017
 * @brief	Class to estimate the state vector fromt he calibrated sensor values.
 */
#ifndef C3DSTATEESTIMATE_H
#define C3DSTATEESTIMATE_H
#include "Global.h"
#include "CSensorData.h"
#include "TMatrix.h"

class C3DStateEstimate
{
public:
	using InputType		= CSensorFloatData;
	using OutputType	= TRVector<9U>;
public:
	const OutputType& calcOutput(const InputType& input);
	const OutputType& getValue() const;
private:
	void estimatePhi(const InputType& input);
	void estimateUK(const InputType& input);
	void estimateUR(const InputType& input);
public:
	C3DStateEstimate();
	C3DStateEstimate(const C3DStateEstimate&) = delete;
	C3DStateEstimate& operator=(const C3DStateEstimate&) = delete;
	~C3DStateEstimate() = default;
private:
	OutputType mOutput;

	Float32 mBx[4];
	Float32 mBy[4];
	Float32 mBz[4];

	static constexpr Float32 sPi		    = 3.141592653589793F;
};

#endif
