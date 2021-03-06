/**
 * @file	TObserver.h
 * @author	Michael Meindl
 * @date	19.04.2017
 * @brief	Template class to calculate a Luenberger-Observer.
 */
#ifndef TOBSERVER_H
#define TOBSERVER_H
#include "TMatrix.h"
#include <string>

template<const UInt32 nX, const UInt32 nY, const UInt32 nU>
class TObserver
{
public:
	using InputType		= TRVector<nY>;
	using OutputType	= TRVector<nX>;
public:
	const OutputType& calcOutput(const InputType& input);
	const OutputType& getValue() const;
	void init(const std::string& aFile,
			  const std::string& bFile,
			  const std::string& cFile,
			  const std::string& lFile);
	void setX(const TRVector<nX>& x);
	void setU(const TRVector<nU>& u);
public:
	TObserver() = default;
	TObserver(const TObserver&) = delete;
	TObserver& operator=(const TObserver&) = delete;
	~TObserver() = default;
private:
	OutputType	mOutput;

	TMatrix<nX, nX> mA;
	TMatrix<nX, nU> mB;
	TMatrix<nY, nX> mC;
	TMatrix<nX, nY> mL;
	TRVector<nU>	mU;
};

template<const UInt32 nX, const UInt32 nY, const UInt32 nU>
const typename TObserver<nX, nY, nU>::OutputType&
		TObserver<nX, nY, nU>::calcOutput(const typename TObserver<nX, nY, nU>::InputType& in)
{
	auto input = in;
	TRVector<nX>& x = mOutput;
	TRVector<nY> y  = mC * x;
	mOutput    = mB * mU + mA * mOutput + mL * (input - y);
	return mOutput;
}
template<const UInt32 nX, const UInt32 nY, const UInt32 nU>
const typename TObserver<nX, nY, nU>::OutputType&
		TObserver<nX, nY, nU>::getValue() const
{
	return mOutput;
}
template<const UInt32 nX, const UInt32 nY, const UInt32 nU>
void TObserver<nX, nY, nU>::init(const std::string& aFile,
								 const std::string& bFile,
								 const std::string& cFile,
								 const std::string& lFile)
{
	mA = TMatrix<nX, nX>(aFile);
	mB = TMatrix<nX, nU>(bFile);
	mC = TMatrix<nY, nX>(cFile);
	mL = TMatrix<nX, nY>(lFile);
}
template<const UInt32 nX, const UInt32 nY, const UInt32 nU>
void TObserver<nX, nY, nU>::setX(const TRVector<nX>& x)
{
	mOutput = x;
}
template<const UInt32 nX, const UInt32 nY, const UInt32 nU>
void TObserver<nX, nY, nU>::setU(const TRVector<nU>& u)
{
	mU = u;
}
#endif
