/**
 * @file 	CFilterSystem
 * @author	Michael Meindl
 * @date	10.1.2017
 * @brief	Class to carry out the different filter operations.
 */
#ifndef CFILTERSYSTEM_H
#define CFILTERSYSTEM_H
#include "CPT1.h"
#include "CDT1.h"
#include "CComplementaryFilter.h"
#include "CPhi.h"
#include "CPhi__d.h"
#include "CPsi__d.h"
#include "EFilter.h"
#include "CProxy.h"

class CFilterSystem
{
public:
	void calculateValues(Float32 phi,
						 Float32 phi__d,
						 Float32 psi__d);
	void calculateHighpass();
	Float32 getControlPhi() const;
	Float32 getControlPhi__d() const;
	Float32 getControlPsi__d() const;
	Float32 getFilteredPhi() 	const;
	Float32 getFilteredPhi__d() const;
	Float32 getFilteredPsi__d() const;
	void setPhiOffset(Float32 offset);
	void setPhi__dOffset(Float32 offset);
	void setPsi__dOffset(Float32 offset);
	void reset();
	void setFilter(EFilter filter);
	void setHighpassFlag(bool flag);
public:
	CFilterSystem(CProxy& proxy);
	CFilterSystem(const CFilterSystem&) = delete;
	CFilterSystem& operator=(const CFilterSystem&) = delete;
	~CFilterSystem() = default;
private:
	CProxy& mProxy;
	CComplementaryFilter mPhiCompFilter;

	CPT1 mPhi__dPT1_5Hz;
	CPT1 mPhi__dPT1_10Hz;

	CPT1 mPsi__dPT1_5Hz;
	CPT1 mPsi__dPT1_10Hz;

	Float32 mPhiOffset;
	Float32 mPhi__dOffset;
	Float32 mPsi__dOffset;

	CPhi 	mPhi;
	CPhi__d mPhi__d;
	CPsi__d mPsi__d;

	EFilter mPhiFilter;
	EFilter mPhi__dFilter;
	EFilter mPsi__dFilter;

	bool mHighpassFlag;
	CDT1 mPhiHighpass;
	CDT1 mPhi__dHighpass;

	Float32 mControlPhi;
	Float32 mControlPhi__d;

	Float32 mTime;
};

#endif
