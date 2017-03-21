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
#include "TMatrix.h"

class CCompFilter
{
public:
	using InputType  = TRVector<9U>;
	using OutputType = TRVector<9U>;
public:
	const OutputType& calcOutput(const InputType& input);
	const OutputType& getValue();
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
	OutputType mOutput;
	CPT1 mUR1Filter;
	CPT1 mUR2Filter;
	CPT1 mUR3Filter;

	Float32 mGInt[3];

	TMatrix<3U, 3U> mDPhi;
	static constexpr Float32 sAlpha = 0.98F;

};

#endif
