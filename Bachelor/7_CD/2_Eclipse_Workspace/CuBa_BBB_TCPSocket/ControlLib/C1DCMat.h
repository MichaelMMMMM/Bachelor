/**
 * @file	C1DCMat.h
 * @author	Michael Meindl
 * @date	19.04.2017
 * @brief	Caculates C*x for the 1D-System to eliminate phi.
 */
#ifndef C1DCMAT_H
#define C1DCMAT_H
#include "TMatrix.h"
#include <string>

class C1DCMat
{
public:
	using InputType		= TRVector<3U>;
	using OutputType	= TRVector<2U>;
public:
	const OutputType& calcOutput(const InputType& input);
	const OutputType& getValue() const;
	void init(const std::string& cFile);
public:
	C1DCMat() = default;
	C1DCMat(const C1DCMat&) = delete;
	C1DCMat& operator=(const C1DCMat&) = delete;
	~C1DCMat() = default;
private:
	OutputType mOutput;

	TMatrix<2U, 3U> mC;
};

#endif
