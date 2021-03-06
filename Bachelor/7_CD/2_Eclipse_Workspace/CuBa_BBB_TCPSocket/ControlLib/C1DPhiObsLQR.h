/**
 * @file	C1DPhiObsLQR.h
 * @author	Michael Meindl
 * @date	19.04.2017
 * @brief	Subsystem to calculate the observer from y=[uk;ur]->x=[phi;uk;ur] and the following LQR.
 */
#ifndef C1DPHIOBSLQR_H
#define C1DPHIOBSLQR_H
#include "TLinHierarchy.h"
#include "TActionHolder.h"
#include "TObserver.h"
#include "C1DCMat.h"
#include "TLQR.h"
#include "TSaturation.h"
#include "CPT1.h"

class C1DPhiObsLQR
{
public:
	using InputType		= TRVector<3U>;
	using OutputType	= TRVector<1U>;
public:
	const OutputType& calcOutput(const InputType& input);
	const OutputType& getValue() const;
	void setObserverX0(const TRVector<3U>& x0);
	void setObserverU(const TRVector<1U>& u);
	void setControllerActive(bool active);
	void updateConfig();
	TRVector<3U> getX();
public:
	C1DPhiObsLQR();
	C1DPhiObsLQR(const C1DPhiObsLQR&) = delete;
	C1DPhiObsLQR& operator=(const C1DPhiObsLQR&) = delete;
	~C1DPhiObsLQR() = default;
private:
	OutputType mOutput;

	using Controller = TLQR<3U, 1U>;
	using Observer   = TObserver<3U, 2U, 1U>;
	using Saturation = TSaturation<1U>;
	using ActionList = TYPELIST_4(C1DCMat, Observer, Controller, Saturation);
	TLinHierarchy<ActionList, TActionHolder> mSignalFlow;
};

#endif
