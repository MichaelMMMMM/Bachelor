/**
 * @file	TMatrix.h
 * @author	Michael Meindl
 * @date	3.3.2017
 * @brief	Tempalte to calculate matrix operations.
 */
#ifndef TMATRIX_H
#define TMATRIX_H
#include "Global.h"
#include <string>
#include <iostream>

template<const UInt32 n_R, const UInt32 n_C>
class TMatrix
{
public:
	void display();
	Float32& scalarAt(UInt32 ir, UInt32 ic);
public:
	TMatrix();
	TMatrix(const TMatrix&) = default;
	TMatrix& operator=(const TMatrix&) = default;
	~TMatrix() = default;
private:
	Float32 mMatrix[n_R][n_C];
};

template<const UInt32 n_R, const UInt32 n_C>
Float32& TMatrix<n_R, n_C>::scalarAt(UInt32 ir, UInt32 ic)
{
	return mMatrix[ir+1][ic+1];
}
template<const UInt32 n_R, const UInt32 n_C>
TMatrix<n_R, n_C>::TMatrix() : mMatrix{0.0F}
{

}
template<const UInt32 n_R, const UInt32 n_C>
void TMatrix<n_R, n_C>::display()
{
	for(UInt32 ir = 0; ir < n_R; ir++)
	{
		for(UInt32 ic = 0; ic < n_C; ic++)
		{
			std::cout << mMatrix[ir][ic];
		}
		std::cout << std::endl;
	}
}

#endif
