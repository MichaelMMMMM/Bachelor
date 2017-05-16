/**
 * @file	CADCData.h
 * @author	Michael Meindl
 * @date	08.02.2017
 * @brief	Data Abstraction for the ADC-Values.
 */
#ifndef CADCDATA_H
#define CADCDATA_H
#include "Global.h"

class CADCData
{
public:
	void display();
public:
	CADCData();
	CADCData(const CADCData&) = default;
	CADCData& operator=(const CADCData&) = default;
	~CADCData() = default;
public:
	Float32 mTime;
	UInt16  mADC1Value;
	UInt16  mADC2Value;
	UInt16  mADC3Value;
	UInt16  mPadding;
};

#endif
