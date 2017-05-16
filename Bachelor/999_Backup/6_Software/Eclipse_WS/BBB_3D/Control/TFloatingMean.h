//Michael Meindl, 5.9.2016
#ifndef TFLOATINGMEAN_H
#define TFLOATINGMEAN_H
#include "Global.h"

/// Template-Class to calculate the floating mean of a data set.
template<const UInt32 n>
class TFloatingMean
{
public:
	float calculateValue(Float32 newValue);
public:
	TFloatingMean<n>();
	TFloatingMean<n>(const TFloatingMean<n>&) = delete;
	TFloatingMean<n>& operator=(const TFloatingMean<n>&) = delete;
	~TFloatingMean<n>() = default;
private:
	Float32 mValues[n];
	UInt32 mLastIndex;
};

template<const UInt32 n>
Float32 TFloatingMean<n>::calculateValue(Float32 newValue)
{
	static bool firstRun = true;
	if(true == firstRun)
	{
		for(UInt32 index = 0U; index < n; index++)
		{
			mValues[index] = newValue;
		}
		firstRun = false;
		return newValue;
	}
	mValues[mLastIndex] = newValue;
	mLastIndex = mLastIndex == (n-1U) ? 0U : mLastIndex + 1U;
	Float32 mean = 0.0F;
	for(UInt32 index = 0U; index < n; index++)
	{
		mean += mValues[mLastIndex];
	}
	return mean/n;
}
template<const UInt32 n>
TFloatingMean<n>::TFloatingMean() : mValues{0.0F},
									   mLastIndex(0U)
{

}

#endif
