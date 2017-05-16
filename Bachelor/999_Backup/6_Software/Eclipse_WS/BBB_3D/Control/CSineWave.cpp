/**
 * @file	 CSineWave.cpp
 * @author	Michael Meindl
 * @date	11.11.2016
 */
#include "CSineWave.h"
#include <cmath>

static constexpr Float32 PI = 3.14159265358979323846;

CSineWave::CSineWave() : mFreq(0.0F),
						 mAmp(0.0F)
{

}
Float32 CSineWave::getValue(Float32 time)
{
	return mAmp*sin(2*PI*mFreq*time);
}
void CSineWave::setAmp(Float32 amp)
{
	mAmp = amp;
}
void CSineWave::setFreq(Float32 freq)
{
	mFreq = freq;
}
