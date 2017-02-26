/**
 * @file	CDT1.h
 * @author	Michael Meindl
 * @date	10.1.2017
 * @brief	Class to calculate a DT1-Highpass.
 */
#ifndef CDT1_H
#define CDT1_H
#include "CPT1.h"

class CDT1
{
public:
	Float32 calculateOutput(Float32 input);
public:
	CDT1(Float32 f_G);
	CDT1(const CDT1&) = delete;
	CDT1& operator=(const CDT1&) = delete;
	~CDT1() = default;
private:
	bool mFirstRun;
	CPT1 mLowPass;
};


#endif
