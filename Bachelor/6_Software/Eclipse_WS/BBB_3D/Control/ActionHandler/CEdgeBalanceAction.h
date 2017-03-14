/**
 * @file	CEdgeBalanceAction.h
 * @author	Michael Meindl
 * @date	14.3.2017
 * @brief	Action Handler for balancing on the cube-edge.
 */
#ifndef CEDGEBALANCEACTION_H
#define CEDGEBALANCEACTION_H
#include "CControlActionBase.h"
#include "TLinHierarchy.h"
#include "TActionHolder.h"
#include "CStateEstimate.h"
#include "C1DStateReduction.h"
#include "C1DOffsetCorrection.h"
#include "C1DLPF.h"
#include "C1DCompFilter.h"
#include "TLQR.h"

class CEdgeBalanceAction : public CControlActionBase
{
public:
	void onEntryEdgeBalance();
	void onExitEdgeBalance();
	void onEntryIdle();
	void onExitIdle();
	void onEntryControl();
	void onExitControl();

	bool inControlArea();
	void sampleIdle();
	void sampleControl();
public:
	CEdgeBalanceAction();
	CEdgeBalanceAction(const CEdgeBalanceAction&) = delete;
	CEdgeBalanceAction& operator=(const CEdgeBalanceAction&) = delete;
	~CEdgeBalanceAction() = default;
private:
	using Controller	 = TLQR<3U, 1U>;
	using ActionTypeList = TYPELIST_5(CStateEstimate, C1DStateReduction, C1DOffsetCorrection, C1DCompFilter, Controller);
	TLinHierarchy<ActionTypeList, TActionHolder> mSignalFlow;
	C1DLPF	mXLPF;

	static constexpr Float32 sMaxGValue = 0.5F;
	Float32 mTime;

};

#endif
