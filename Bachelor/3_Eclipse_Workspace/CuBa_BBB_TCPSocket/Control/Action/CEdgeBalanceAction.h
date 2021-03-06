/**
 * @file	CEdgeBalanceAction.h
 * @author	Michael Meindl
 * @date	18.04.2017
 * @brief	Action handler for balancing on the edge.
 */
#ifndef CEDGEBALANCEACTION_H
#define CEDGEBALANCEACTION_H
#include "CControlActionBase.h"
#include "TLinHierarchy.h"
#include "TActionHolder.h"
#include "CHardware.h"
#include "CF1Calib.h"
#include "C3DStateEstimate.h"
#include "C1DStateReduction.h"
#include "C1DOffsetCorrection.h"
#include "C1DControlSystem.h"
#include "E1DControlSystem.h"

class CEdgeBalanceAction : public CControlActionBase
{
public:
	void entryEdgeBalance();
	void exitEdgeBalance();
	void entryIdle();
	void exitIdle();
	void entryBalance();
	void exitBalance();

	void sample();
	bool inBalanceArea();
	void setTorques();
	void setPhiOffset(Float32 offset);
	void setUKOffset(Float32 offset);
	void setUROffset(Float32 offset);
	void selectControlSystem(E1DControlSystem sys);
	void updateConfig();
public:
	CEdgeBalanceAction();
	CEdgeBalanceAction(const CEdgeBalanceAction&) = delete;
	CEdgeBalanceAction& operator=(const CEdgeBalanceAction&) = delete;
	~CEdgeBalanceAction() = default;
private:
	Float32 mTime;
	UInt32  mEntryCounter;

	using ActionList = TYPELIST_5(CF1Calib, C3DStateEstimate, C1DStateReduction,C1DOffsetCorrection, C1DControlSystem);
	TLinHierarchy<ActionList, TActionHolder> mSignalFlow;

	static constexpr Float32 sPhiMax = 0.15F;
};


#endif
