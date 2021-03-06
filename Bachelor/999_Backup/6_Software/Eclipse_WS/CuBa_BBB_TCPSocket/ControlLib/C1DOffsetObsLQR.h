/**
 * @file	C1DOffsetObsLQR.h
 * @author	Michael Meindl
 * @date	19.04.2017
 * @brief	Subsystem to calculate the controller with an offset observer.
 */
#ifndef C1DOFFSETOBSLQR_H
#define C1DOFFSETOBSLQR_H
#include "TLinHierarchy.h"
#include "TActionHolder.h"
#include "TLQR.h"
#include "TSaturation.h"
#include "TObserver.h"
#include "C1DCompFilter.h"
#include "CPT1.h"

class C1DOffsetObsLQR
{
public:
	using InputType		= TRVector<3U>;
	using OutputType	= TRVector<1U>;
public:
	const OutputType& calcOutput(const InputType& input);
	const OutputType& getValue() const;
	void setObsU(const TRVector<1U>& u);
	TRVector<3U> getOffsets();
	void setControllerActive(bool active);
	TRVector<3U> getX();
	void updateConfig();
public:
	C1DOffsetObsLQR();
	C1DOffsetObsLQR(const C1DOffsetObsLQR&) = delete;
	C1DOffsetObsLQR& operator=(const C1DOffsetObsLQR&) = delete;
	~C1DOffsetObsLQR() = default;
private:
	OutputType mOutput;

	bool mActive;

	CPT1	mPhiOffFilter;
	CPT1	mUKOffFilter;
	CPT1	mUROffFilter;

	C1DCompFilter         mCompFilter;
	TObserver<6U, 3U, 1U> mObserver;
	TLQR<3U, 1U>		  mLQR;
	TSaturation<1U>		  mSaturation;
};


#endif
