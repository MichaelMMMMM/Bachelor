/**
 * @file	CStateData.h
 * @author	Michael Meindl
 * @date	16.02.2017
 * @brief	Data Abstraction for the state vector composed of subclasses.
 */
#ifndef CSTATEDATA_H
#define CSTATEDATA_H
#include "Global.h"
#include "TMatrix.h"

class CGData
{
public:
	void display();
public:
	Float32 mTime;
	Float32 mG_k1;
	Float32 mG_k2;
	Float32 mG_k3;
public:
	CGData();
	CGData(Float32 g1, Float32 g2, Float32 g3);
	CGData(const CGData&) = default;
	CGData& operator=(const CGData&) = default;
	~CGData() = default;
};

class CUKData
{
public:
	void display();
public:
	Float32 mTime;
	Float32 mUK_k1;
	Float32 mUK_k2;
	Float32 mUK_k3;
public:
	CUKData();
	CUKData(Float32 uk1, Float32 uk2, Float32 uk3);
	CUKData(const CUKData&) = default;
	CUKData& operator=(const CUKData&) = default;
	~CUKData() = default;
};

class CURData
{
public:
	void display();
public:
	Float32 mTime;
	Float32 mUR_k1;
	Float32 mUR_k2;
	Float32 mUR_k3;
public:
	CURData();
	CURData(Float32 ur1, Float32 ur2, Float32 ur3);
	CURData(const CURData&) = default;
	CURData& operator=(const CURData&) = default;
	~CURData() = default;
};

class CStateData
{
public:
	void display();
public:
	CGData  mGData;
	CUKData mUKData;
	CURData mURData;
public:
	CStateData(const TRVector<9U>& x) : mGData{x.scalarAt(1,1), x.scalarAt(2,1), x.scalarAt(3,1)},
										mUKData{x.scalarAt(4,1), x.scalarAt(5,1), x.scalarAt(6,1)},
										mURData{x.scalarAt(7,1), x.scalarAt(8,1), x.scalarAt(9,1)}{}
	CStateData() = default;
	CStateData(const CStateData&) = default;
	CStateData& operator=(const CStateData&) = default;
	~CStateData() = default;
};

#endif
