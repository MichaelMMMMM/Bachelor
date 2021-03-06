/**
 * @file	C1DLPF.h
 * @author	Michael Meindl
 * @date	14.03.2017
 * @brief	Class to Low-Pass-Filter the State-Vector.
 */
#ifndef C1DLPF_H
#define C1DLPF_H
#include "CPT1.h"
#include "TMatrix.h"

class C1DLPF
{
public:
	using InputType		= TRVector<3U>;
	using OutputType	= TRVector<3U>;
public:
	const OutputType& calcOutput(const InputType& input);
	const OutputType& getValue();
public:
	C1DLPF();
	C1DLPF(const C1DLPF&) = delete;
	C1DLPF& operator=(const C1DLPF&) = delete;
	~C1DLPF() = default;
private:
	OutputType mOutput;
	CPT1 	   mX1LPF;

	static constexpr Float32 sGF_X1 = 1.0F;
};

#endif
