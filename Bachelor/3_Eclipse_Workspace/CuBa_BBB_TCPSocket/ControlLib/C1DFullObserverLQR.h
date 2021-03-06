/**
 * @file	C1DFullObserverLQR.h
 * @author	Michael Meindl
 * @date	01.05.2017
 * @brief	Class to first calculate the Complementary-Filter and use an observer to furth decrease noise.
 */
#ifndef C1DFULLOBSERVERLQR_H
#define C1DFULLOBSERVERLQR_H
#include "Global.h"
#include "TLQR.h"
#include "C1DCompFilter.h"
#include "TObserver.h"
#include "TLinHierarchy.h"
#include "TSaturation.h"
#include "TActionHolder.h"

class C1DFullObserverLQR
{
public:
	using InputType		= TRVector<3U>;
	using OutputType	= TRVector<1U>;
public:
	const OutputType& calcOutput(const InputType& input);
	const OutputType& getValue() const;
	TRVector<3U> getX();
	void updateConfig();
	void setObserverU(TRVector<1U> u);
	void setObserverX0(TRVector<3U> x0);
	void setControllerActive(bool active);
public:
	C1DFullObserverLQR();
	C1DFullObserverLQR(const C1DFullObserverLQR&) = delete;
	C1DFullObserverLQR& operator=(const C1DFullObserverLQR&) = delete;
	~C1DFullObserverLQR() = default;
private:
	OutputType	mOutput;

	using Controller = TLQR<3U, 1U>;
	using Observer   = TObserver<3U, 3U, 1U>;
	using Saturation = TSaturation<1U>;
	using ActionList = TYPELIST_4(C1DCompFilter, Observer, Controller, Saturation);
	TLinHierarchy<ActionList, TActionHolder> mSignalFlow;
};

#endif
