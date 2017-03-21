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
#include <iomanip>
#include <ostream>
#include <fstream>

template<const UInt32 n_R, const UInt32 n_C>
class TMatrix;

template<const UInt32 n_R>
using TRVector = TMatrix<n_R, 1>;

template<const UInt32 n_C>
using TCVector = TMatrix<1, n_C>;

template<const UInt32 n_R, const UInt32 n_C>
class TMatrix
{
public:
	void display();
	Float32& scalarAt(UInt32 ir, UInt32 ic);
	const Float32& scalarAt(UInt32 ir, UInt32 ic) const;
	TMatrix operator+(const TMatrix&) const;
	TMatrix operator-(const TMatrix&) const;
	TMatrix operator*(const Float32) const;

	template<const UInt32 n_C_new>
	TMatrix<n_R, n_C_new> operator*(const TMatrix<n_C, n_C_new> mat) const;
public:
	TMatrix();
	TMatrix(const std::string& filename);
	TMatrix(const TMatrix&) = default;
	TMatrix& operator=(const TMatrix&) = default;
	~TMatrix() = default;
private:
	Float32 mMatrix[n_R][n_C];
};

template<const UInt32 n_R, const UInt32 n_C>
TMatrix<n_R, n_C>::TMatrix(const std::string& filename) : mMatrix{0.0F}
{
	std::ifstream stream;
	std::string data;

	stream.open(filename);
	for(UInt32 ir = 0; ir < n_R; ir++)
	{
		stream >> data;
		for(UInt32 ic = 0; ic < n_C; ic++)
		{
			std::string tmp = data.substr(0, data.find(","));
			mMatrix[ir][ic] = std::stof(tmp);
			data = data.substr(data.find(",")+1);
		}
	}
}
template<const UInt32 n_R, const UInt32 n_C>
template<const UInt32 n_C_new>
TMatrix<n_R, n_C_new> TMatrix<n_R, n_C>::operator*(const TMatrix<n_C, n_C_new> mat) const
{
	TMatrix<n_R, n_C_new> newMat;
	for(UInt32 ir = 0; ir < n_R; ir++)
	{
		for(UInt32 ic = 0; ic < n_C_new; ic++)
		{
			for(UInt32 i = 0; i < n_C; i++)
			{

				newMat.scalarAt(ir+1, ic+1) += this->mMatrix[ir][i] * mat.scalarAt(i+1, ic+1);
			}
		}
	}
	return newMat;
}
template<const UInt32 n_R, const UInt32 n_C>
TMatrix<n_R, n_C> TMatrix<n_R, n_C>::operator-(const TMatrix& mat) const
{
	TMatrix<n_R, n_C> result;
	for(UInt32 ir = 0; ir < n_R; ir++)
	{
		for(UInt32 ic = 0; ic < n_C; ic++)
		{
			result.mMatrix[ir][ic] = mMatrix[ir][ic] -  mat.mMatrix[ir][ic];
		}
	}
	return result;
}
template<const UInt32 n_R, const UInt32 n_C>
TMatrix<n_R, n_C> TMatrix<n_R, n_C>::operator+(const TMatrix& mat) const
{
	TMatrix<n_R, n_C> result;
	for(UInt32 ir = 0; ir < n_R; ir++)
	{
		for(UInt32 ic = 0; ic < n_C; ic++)
		{
			result.mMatrix[ir][ic] = mMatrix[ir][ic] + mat.mMatrix[ir][ic];
		}
	}
	return result;
}
template<const UInt32 n_R, const UInt32 n_C>
TMatrix<n_R, n_C> TMatrix<n_R, n_C>::operator*(const Float32 scalar) const
{
	TMatrix<n_R, n_C> result;
	for(UInt32 ir = 0; ir < n_R; ir++)
	{
		for(UInt32 ic = 0; ic < n_C; ic++)
		{
			result.mMatrix[ir][ic] = scalar * mMatrix[ir][ic];
		}
	}
	return result;
}
template<const UInt32 n_R, const UInt32 n_C>
Float32& TMatrix<n_R, n_C>::scalarAt(UInt32 ir, UInt32 ic)
{
	return mMatrix[ir-1][ic-1];
}
template<const UInt32 n_R, const UInt32 n_C>
const Float32& TMatrix<n_R, n_C>::scalarAt(UInt32 ir, UInt32 ic) const
{
	return mMatrix[ir-1][ic-1];
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
			std::cout << std::setw(6) << mMatrix[ir][ic] << " ";
		}
		std::cout << std::endl;
	}
}

#endif
