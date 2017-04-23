/**
 * @file	TMatrix.h
 * @author	Michael Meindl
 * @date	24.03.2017
 * @brief	Template class to utilize matrixes.
 */
#ifndef TMATRIX_H
#define TMATRIX_H
#include "TCVector.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <fstream>

template<const UInt32 n_R, const UInt32 n_C>
class TMatrix
{
public:
	void display();
	TCVector<n_C>& operator[](const UInt32 ic);
	TMatrix<n_R, n_C> operator+(const TMatrix<n_R, n_C>& summand) const;
	TMatrix<n_R, n_C> operator-(const TMatrix<n_R, n_C>& subtrahend) const;
	template<const UInt32 n_C_new>
	TMatrix<n_R, n_C_new> operator*(const TMatrix<n_C, n_C_new>& factor);
	TMatrix<n_R, n_C> operator*(Float32 factor);
public:
	TMatrix();
	TMatrix(const std::string& filename);
	TMatrix(const TMatrix&) = default;
	TMatrix& operator=(const TMatrix&) = default;
	~TMatrix() = default;
private:
	TCVector<n_C> mMatrix[n_R];
};

template<UInt32 n_R>
using TRVector = TMatrix<n_R, 1>;

template<const UInt32 n_R, const UInt32 n_C>
template<const UInt32 n_C_new>
TMatrix<n_R, n_C_new> TMatrix<n_R, n_C>::operator*(const TMatrix<n_C, n_C_new>& f)
{
	TMatrix<n_C, n_C_new> factor = f;
	TMatrix<n_R, n_C_new> ret;
	for(UInt32 ir = 0; ir < n_R; ir++)
	{
		for(UInt32 ic = 0; ic < n_C_new; ic++)
		{
			for(UInt32 i = 0; i < n_C; i++)
			{

				ret[ir+1][ic+1] += (*this)[ir+1][i+1] * factor[i+1][ic+1];
			}
		}
	}
	return ret;
}
template<const UInt32 n_R, const UInt32 n_C>
TMatrix<n_R, n_C> TMatrix<n_R, n_C>::operator*(Float32 factor)
{
	TMatrix<n_R, n_C> ret;
	for(UInt32 ir = 0; ir < n_R; ir++)
	{
		ret.mMatrix[ir] = this->mMatrix[ir] * factor;
	}
	return ret;
}
template<const UInt32 n_R, const UInt32 n_C>
TCVector<n_C>& TMatrix<n_R, n_C>::operator[](const UInt32 i)
{
	return mMatrix[i-1];
}
template<const UInt32 n_R, const UInt32 n_C>
TMatrix<n_R, n_C> TMatrix<n_R, n_C>::operator+(const TMatrix<n_R, n_C>& summand) const
{
	TMatrix<n_R, n_C> ret;
	for(UInt32 ir = 0; ir < n_R; ir++)
	{
		ret.mMatrix[ir] = this->mMatrix[ir] + summand.mMatrix[ir];
	}
	return ret;
}
template<const UInt32 n_R, const UInt32 n_C>
TMatrix<n_R, n_C> TMatrix<n_R, n_C>::operator-(const TMatrix<n_R, n_C>& subtrahend) const
{
	TMatrix<n_R, n_C> ret;
	for(UInt32 ir = 0; ir < n_R; ir++)
	{
		ret.mMatrix[ir] = this->mMatrix[ir] - subtrahend.mMatrix[ir];
	}
	return ret;
}
template<const UInt32 n_R, const UInt32 n_C>
TMatrix<n_R, n_C>::TMatrix()
{

}
template<const UInt32 n_R, const UInt32 n_C>
TMatrix<n_R, n_C>::TMatrix(const std::string& filename)
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
			mMatrix[ir][ic+1] = std::stof(tmp);
			data = data.substr(data.find(",")+1);
		}
	}
}
template<const UInt32 n_R, const UInt32 n_C>
void TMatrix<n_R, n_C>::display()
{
	for(UInt32 ir = 0; ir < n_R; ir++)
	{
		for(UInt32 ic = 0; ic < n_C; ic++)
		{
			std::cout << std::setw(10) << (*this)[ir+1][ic+1] << " ";
		}
		std::cout << std::endl;
	}
}
#endif
