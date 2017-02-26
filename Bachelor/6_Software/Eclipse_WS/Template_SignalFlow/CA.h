#ifndef CA_H
#define CA_H
#include "Global.h"

class CA
{
public:
	using InputType  = int;
	using OutputType = double;
	const double& getValue()
	{
		return mOutput;
	}
	void calcOutput(const int& input)
	{
		mOutput = 2.0 * static_cast<double>(input);
	}
public:
	explicit CA() : mOutput(0.0) {}
	CA(const CA&) = delete;
	CA& operator=(const CA&) = delete;
	~CA() = default;
private:
	double mOutput;
};


#endif
