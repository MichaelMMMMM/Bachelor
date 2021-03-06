/**
 * @file	CControlTestAction.h
 * @author	Michael Meindl
 * @date	8.1.2017
 * @brief	Action class for the control-test.
 */
#ifndef CCONTROLTESTACTION_H
#define CCONTROLTESTACTION_H
#include "CControlActionBase.h"
#include "CSensorEvaluation.h"
#include "CComplementaryFilter.h"
#include "CLQRControl.h"
#include "CFilterSystem.h"
#include "CCascadeControl.h"
#include "CLQB.h"

class CControlTestAction : public CControlActionBase
{
public:
	void entryControlTest();
	void exitControlTest();
	void entryIdle();
	void exitIdle();
	void entryBalance();
	void exitBalance();
	void sampleControlTest();
	bool inBalanceArea();
	void setPhiOffset(Float32 offset);
	void setPhi__dOffset(Float32 offset);
	void setPsi__dOffset(Float32 offset);
	void setFilter(EFilter filter);
	void setHighpassFlag(bool flag);
	void setLQRFlag(bool flag);
	void setObsFlag(bool flag);
public:
	CControlTestAction();
	CControlTestAction(const CControlTestAction&) = delete;
	CControlTestAction& operator=(const CControlTestAction&) = delete;
	~CControlTestAction() = default;
private:
	CFilterSystem 	  mFilterSystem;
	CSensorEvaluation mSensorEval;
	CLQRControl 	  mLQR;
	CCascadeControl   mCascControl;
	CLQB			  mLQB;
	bool 			  mLQRFlag;
	bool   			  mObsFlag;
};

#endif
