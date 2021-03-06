/**
 * @file	TLQR.h
 * @author	Michael Meindl
 * @date	18.04.2017
 * @brief	Template class to calcualte the state controller.
 */
#ifndef TLQR_H
#define TLQR_H
#include "TMatrix.h"
#include <string>

template<UInt32 nbrX, UInt32 nbrU>
class TLQR
{
public:
	using InputType		= TRVector<nbrX>;
	using OutputType	= TRVector<nbrU>;
public:
	const OutputType& calcOutput(const InputType& input);
	const OutputType& getValue() const;
	void init(const std::string& kFile);		///! Helper method for late initializiation
public:
	TLQR() = default;
	TLQR(const TLQR&) = delete;
	TLQR& operator=(const TLQR&) = delete;
	~TLQR() = default;
private:
	OutputType	mOutput;

	TMatrix<nbrU, nbrX> mK;
};

template<UInt32 nbrX, UInt32 nbrU>
const typename TLQR<nbrX, nbrU>::OutputType& TLQR<nbrX, nbrU>::calcOutput(const typename TLQR<nbrX, nbrU>::InputType& input)
{
	mOutput = mK * input;
	mOutput = mOutput * (-1.0F);
	return mOutput;
}
template<UInt32 nbrX, UInt32 nbrU>
const typename TLQR<nbrX, nbrU>::OutputType& TLQR<nbrX, nbrU>::getValue() const
{
	return mOutput;
}
template<UInt32 nbrX, UInt32 nbrU>
void TLQR<nbrX, nbrU>::init(const std::string& kFile)
{
	mK = TMatrix<nbrU, nbrX>(kFile);
}

#endif
