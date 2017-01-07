/**
 * @file	CSensorData.h
 * @author	Michael Meindl
 * @date	18.9.2016
 * @brief	Struct to hold the raw sensor values.
 */
#ifndef CSENSORDATA_H
#define CSENSORDATA_H
#include "Global.h"

struct CSensorData
{
	Float32 mTime;
	Int16	mX1__dd;
	Int16	mX2__dd;
	Int16	mY1__dd;
	Int16	mY2__dd;
	Int16	mPhi1__d;
	Int16	mPhi2__d;
	Int16	mPsi__d;
	Int16	mPadding;
};

#endif
