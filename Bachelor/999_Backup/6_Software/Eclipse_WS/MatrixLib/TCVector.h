/**
 * @file	TCVector.h
 * @author	Michael Meindl
 * @date	24.03.2017
 * @brief	Template class to use Column-Vectors.
 */
#ifndef TCVECTOR_H
#define TCVECTOR_H
#include "Global.h"

template<const UInt32 n_C>
class TCVector
{
public:
	Float32& operator[](const UInt32 i);
	TCVector<n_C> operator+(const TCVector<n_C>&) const;
	TCVector<n_C> operator-(const TCVector<n_C>&) const;
	TCVector<n_C> operator*(const Float32 factor) const;
public:
	TCVector();
	TCVector(const TCVector&) = default;
	TCVector& operator=(const TCVector&) = default;
	~TCVector() = default;
private:
	Float32 mVector[n_C];
};

template<const UInt32 n_C>
Float32& TCVector<n_C>::operator[](const UInt32 i)
{
	return mVector[i-1];
}
template<const UInt32 n_C>
TCVector<n_C> TCVector<n_C>::operator+(const TCVector<n_C>& summand) const
{
	TCVector<n_C> ret;
	for(UInt32 i = 0; i < n_C; i++)
	{
		ret.mVector[i] = this->mVector[i] + summand.mVector[i];
	}
	return ret;
}
template<const UInt32 n_C>
TCVector<n_C> TCVector<n_C>::operator-(const TCVector<n_C>& subtrahend) const
{
	TCVector<n_C> ret;
	for(UInt32 i = 0; i < n_C; i++)
	{
		ret.mVector[i] = this->mVector[i] - subtrahend.mVector[i];
	}
	return ret;
}
template<const UInt32 n_C>
TCVector<n_C> TCVector<n_C>::operator*(const Float32 factor) const
{
	TCVector<n_C> ret;
	for(UInt32 i = 0; i < n_C; i++)
	{
		ret.mVector[i] = this->mVector[i] * factor;
	}
	return ret;
}
template<const UInt32 n_C>
TCVector<n_C>::TCVector() : mVector{0.0F}
{

}

#endif
