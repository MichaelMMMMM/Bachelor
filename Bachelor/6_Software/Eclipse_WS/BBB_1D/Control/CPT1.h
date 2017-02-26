/**
 * @file	CPT1.h
 * @author	Michael Meindl
 * @date	10.1.2017
 * @brief	Class to calculate a PT1-Lowpass.
 */
#ifndef CPT1_H
#define CPT1_H
#include "ControlConfig.h"

class CPT1
{
public:
	Float32 calculateOutput(Float32 input);
public:
	CPT1(Float32 f_G);
	CPT1(const CPT1&) = delete;
	CPT1& operator=(const CPT1&) = delete;
	~CPT1() = default;
private:
	bool 		  mFirstRun;
	const Float32 mFactor;
	Float32   	  mRecentOutput;
};

#endif
