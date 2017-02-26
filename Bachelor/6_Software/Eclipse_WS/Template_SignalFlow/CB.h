#ifndef CB_H
#define CB_H
#include "Global.h"

class CB
{
public:
	using InputType = double;
	using OutputType = float;
	const float& getValue()
	{
		return mOutput;
	}
	void calcOutput(const double& input)
	{
		mOutput = static_cast<float>(input) - 1.0F;
	}
public:
	CB() : mOutput(0.0F) {}
	CB(const CB&) = delete;
	CB& operator=(const CB&) = delete;
	~CB() = default;
private:
	float mOutput;
};

#endif
