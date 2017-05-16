/**
 * @file	CPhi.h
 * @author	Michael Meindl
 * @date	18.9.2016
 * @brief	Struct to hold the phi values.
 */
#ifndef CPHI_H
#define CPHI_H
#include "Global.h"

struct CPhi
{
	Float32 mTime;
	Float32 mEstimation;
	Float32 mComplementary;
	Float32 mKalman;
};

#endif
