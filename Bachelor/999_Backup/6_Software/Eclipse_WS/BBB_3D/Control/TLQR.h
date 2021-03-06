/**
 * @file	TLQR.h
 * @author	Michael Meindl
 * @date	14.03.2017
 * @brief	Template class to calculate a LQR-Controller.
 */
#ifndef TLQR_H
#define TLQR_H
#include "TMatrix.h"
#include <string>

template<const UInt32 nrX, const UInt32 nrU>
class TLQR
{
public:
	using InputType  = TRVector<nrX>;
	using OutputType = TRVector<nrU>;
public:
	const OutputType& calcOutput(const InputType& input);
	const OutputType& getValue();
public:
	TLQR();
	TLQR(const TLQR&) = delete;
	TLQR& operator=(const TLQR&) = delete;
	~TLQR() = default;
private:
	OutputType mOutput;
	TMatrix<nrU, nrX> mK;
};

template<const UInt32 nrX, const UInt32 nrU>
TLQR<nrX, nrU>::TLQR()
{

}
template<const UInt32 nrX, const UInt32 nrU>
const TRVector<nrU>& TLQR<nrX, nrU>::calcOutput(const TRVector<nrX>& input)
{
	mOutput = mK * input;
	mOutput = mOutput * (-1.0F);
	return mOutput;
}
template<const UInt32 nrX, const UInt32 nrU>
const TRVector<nrU>& TLQR<nrX, nrU>::getValue()
{
	return mOutput;
}

#endif
