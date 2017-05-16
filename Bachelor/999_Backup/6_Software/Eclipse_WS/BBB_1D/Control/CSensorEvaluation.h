/**
 * @file	CSensorEvaluation.h
 * @author	Michael Meindl
 * @date 	13.9.2016
 */
#ifndef CSENSOREVALUATION_H
#define CSENSOREVALUATION_H
#include "Global.h"
#include "CSensorData.h"
#include "CBBBHardware.h"

class CSensorEvaluation
{
public:
	Float32 getPhi() const;
	Float32 getPhi__d() const;
	Float32 getPhi__dd() const;
	Float32 getPsi__d() const;
	void calculateValues();
	void resetValues();
public:
	CSensorEvaluation(CBBBHardware& hw);
	CSensorEvaluation(const CSensorEvaluation&) = delete;
	CSensorEvaluation& operator=(const CSensorEvaluation&) = delete;
	~CSensorEvaluation() = default;
private:
	CBBBHardware& mHW;
	UInt16 mADCValue;
	SMPU6050Data mSensor1Data;
	SMPU6050Data mSensor2Data;
	Float32 mPhi;
	Float32 mPhi__d;
	Float32 mPhi__dd;
	Float32 mPsi__d;
};

#endif
