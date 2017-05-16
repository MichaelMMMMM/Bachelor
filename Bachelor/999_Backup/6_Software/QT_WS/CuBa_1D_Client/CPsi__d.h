/**
 * @file	CPsi__d.h
 * @author	Michael Meindl
 * @date 	18.9.2016
 * @brief	Struct to hold the different psi__d values.
 */
#ifndef CPSI__D_H
#define CPSI__D_H
#include "Global.h"

struct CPsi__d
{
	Float32 mTime;
	Float32 mEstimation;
	Float32 mMean4;
	Float32 mMean8;
	Float32 mMean16;
};

#endif
