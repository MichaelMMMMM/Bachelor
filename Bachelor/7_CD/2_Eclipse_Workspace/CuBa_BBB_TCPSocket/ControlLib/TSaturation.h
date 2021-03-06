/**
 * @file	TSaturation.h
 * @author	Michael Meindl
 * @date	19.04.2017
 * @brief	Template class to saturate a n-dimensional signal.
 */
#ifndef TSATURATION_H
#define TSATURATION_H
#include "TMatrix.h"

template<const UInt32 n>
class TSaturation
{
public:
	using InputType		= TRVector<n>;
	using OutputType	= TRVector<n>;
public:
	const OutputType& calcOutput(const InputType& input);
	const OutputType& getValue() const;
	void setMaximum(Float32 max);
	void setMinimum(Float32 min);
	void setActiveFlag(bool flag);
public:
	TSaturation();
	TSaturation(const TSaturation&) = delete;
	TSaturation& operator=(const TSaturation&) = delete;
	~TSaturation() = default;
private:
	OutputType mOutput;
	Float32	   mMax;
	Float32    mMin;
};

template<const UInt32 n>
TSaturation<n>::TSaturation() : mMax(0.0F), mMin(0.0F)
{

}
template<const UInt32 n>
const typename TSaturation<n>::OutputType& TSaturation<n>::calcOutput(const typename TSaturation<n>::InputType& input)
{
	auto copy = input;
	for(UInt32 k = 0U; k < n; k++)
	{
		Float32 element = copy[k+1][1];
		if(element > mMax)
		{
			mOutput[k+1][1] = mMax;
		}
		else if(element < mMin)
		{
			mOutput[k+1][1] = mMax;
		}
		else
		{
			mOutput[k+1][1] = element;
		}
	}
	return mOutput;
}
template<const UInt32 n>
const typename TSaturation<n>::OutputType& TSaturation<n>::getValue() const
{
	return mOutput;
}
template<const UInt32 n>
void TSaturation<n>::setMaximum(Float32 max)
{
	mMax = max;
}
template<const UInt32 n>
void TSaturation<n>::setMinimum(Float32 min)
{
	mMin = min;
}

#endif
