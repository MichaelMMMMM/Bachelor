/**
 * @file	CPoly1.h
 * @author	Michael Meindl
 * @date	16.02.2017
 * @brief	Class to calculate a polynom of first order.
 */
#ifndef CPOLY1_H
#define CPOLY1_H
#include "Global.h"

class CPoly1
{
public:
	Float32 calcOutput(Float32 input);
public:
	CPoly1(Float32 factor, Float32 offset);
	CPoly1(const CPoly1&) = delete;
	CPoly1& operator=(const CPoly1&) = delete;
	~CPoly1() = default;
private:
	const Float32 mFactor;
	const Float32 mOffset;
};

#endif
