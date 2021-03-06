/**
 * @file	CStateData.h
 * @author	Michael Meindl
 * @date	16.02.2017
 * @brief	Data Abstraction for the state vector composed of subclasses.
 */
#ifndef CSTATEDATA_H
#define CSTATEDATA_H
#include "Global.h"

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
	CStateData() = default;
	CStateData(const CStateData&) = default;
	CStateData& operator=(const CStateData&) = default;
	~CStateData() = default;
};

#endif
