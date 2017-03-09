/**
 * @file	CCompFilter.h
 * @author	Michael Meindl
 * @date	16.02.2017
 * @brief	Complementary-Filter for the 3D-Cube.
 */
#ifndef CCOMPFILTER_H
#define CCOMPFILTER_H
#include "CStateData.h"
#include "CPT1.h"

class CCompFilter
{
public:
	using InputType = CStateData;
	using OutputType = CStateData;
public:
	const CStateData& calcOutput(const CStateData& input);
	const CStateData& getValue();
	void reset();
	void activate();
	void deactivate();
public:
	CCompFilter();
	CCompFilter(const CCompFilter&) = delete;
	CCompFilter& operator=(const CCompFilter&) = delete;
	~CCompFilter() = default;
private:
	bool mActiveFlag;
	bool mFirstRun;
	CStateData mOutput;
	CPT1 mUR1Filter;
	CPT1 mUR2Filter;
	CPT1 mUR3Filter;

	Float32 mGInt[3];

	static constexpr Float32 sAlpha = 0.9901F;
};

#endif