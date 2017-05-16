/**
 * @file	CCornerBalanceAction.h
 * @author	Michael Meindl
 * @date	20.04.2017
 * @brief	Action handler for Corner-Balancing.
 */
#ifndef CCORNERBALANCINGACTION_H
#define CCORNERBALANCINGACTION_H
#include "CControlActionBase.h"
#include "TLinHierarchy.h"
#include "TActionHolder.h"
#include "C3DStateEstimate.h"
#include "CF1Calib.h"
#include "C3DOffsetCorrection.h"
#include "C3DCompFilter.h"
#include "TLQR.h"

class CCornerBalanceAction : public CControlActionBase
{
public:
	void entryCornerBalance();
	void exitCornerBalance();
	void entryIdle();
	void exitIdle();
	void entryBalance();
	void exitBalance();

	void sample();
	bool inBalanceArea();
	void setTorques();
	void reloadConfig();
public:
	CCornerBalanceAction();
	CCornerBalanceAction(const CCornerBalanceAction&) = delete;
	CCornerBalanceAction& operator=(const CCornerBalanceAction&) = delete;
	~CCornerBalanceAction() = default;
private:
	Float32 mTime;
	UInt32  mDelayCounter;

	using Controller = TLQR<9U, 3U>;
	using ActionList = TYPELIST_5(CF1Calib, C3DStateEstimate, C3DOffsetCorrection, C3DCompFilter, Controller);
	TLinHierarchy<ActionList, TActionHolder> mSignalFlow;

	static constexpr Float32 sPhiMax = 0.1F;

};

#endif
