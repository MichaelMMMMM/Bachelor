/**
 * @file	CSineWave.h
 * @author	Michael Meindl
 * @date	11.11.2016
 */
#ifndef CSINEWAVE_H
#define CSINEWAVE_H
#include "Global.h"

class CSineWave
{
public:
	Float32 getValue(Float32 time);
	void setFreq(Float32 freq);
	void setAmp(Float32 amp);
public:
	CSineWave();
	CSineWave(const CSineWave&) = delete;
	CSineWave& operator=(const CSineWave&) = delete;
	~CSineWave() = default;
private:
	Float32 mFreq;
	Float32 mAmp;
};

#endif
