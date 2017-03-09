/**
 * @file	CLQRTestAction.h
 * @author	Michael Meindl
 * @date	16.02.2017
 * @brief	Action Handler for CLQRTest.
 */
#ifndef CLQRTESTACTION_H
#define CLQRTESTACTION_H
#include "CControlActionBase.h"
#include "TLinHierarchy.h"
#include "TActionHolder.h"
#include "CStateEstimate.h"
#include "CLQR.h"
#include "CCompFilter.h"
#include "COffsetCorrection.h"

class CLQRTestAction : public CControlActionBase
{
public:
	void onLQRTestEntry();
	void onLQRTestExit();
	void sampleLQRTest();
	void setCompFilterActiveFlag(bool flag);
	void setOffsetCorrectionActiveFlag(bool flag);
public:
	CLQRTestAction();
	CLQRTestAction(const CLQRTestAction&) = default;
	CLQRTestAction& operator=(const CLQRTestAction&) = default;
	~CLQRTestAction() = default;
private:
	using ActionTypeList = TYPELIST_4(CStateEstimate, COffsetCorrection, CCompFilter, CLQR);
	TLinHierarchy<ActionTypeList, TActionHolder> mSignalFlow;
	Float32 mTime;
	UInt32 mDelayCounter;
};

#endif