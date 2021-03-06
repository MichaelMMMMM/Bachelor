/**
 * @file	CPoly1.cpp
 * @date	16.02.2017
 * @author	Michael Meindl
 * @brief	Method definitions for CPoly1.
 */
#include "CPoly1.h"

CPoly1::CPoly1(Float32 factor, Float32 offset) : mFactor(factor),
												 mOffset(offset)
{

}
Float32 CPoly1::calcOutput(Float32 input)
{
	return input * mFactor + mOffset;
}
