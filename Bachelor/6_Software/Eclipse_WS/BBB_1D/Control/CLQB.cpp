/*
 * @file	CLQB.cpp
 * @author	Michael Meindl
 * @date	2.3.2017
 * @brief	Method definitions for CLQB.
 */
#include "CLQB.h"
#include <iostream>
#include <ostream>
#include <fstream>
using namespace std;

CLQB::CLQB(const string& kFile,
		   const string& lFile,
		   const string& aFile,
		   const string& bFile,
		   const string& cFile) : mKd(kFile), mLd(lFile), mAd(aFile),mBd(bFile), mCd(cFile), mFirstRun(true)
{

}
Float32 CLQB::calculateOutput(Float32 phi, Float32 phi__d, Float32 psi__d)
{
	if(mFirstRun == true)
	{
		mFirstRun = false;
		mX_B.scalarAt(1,1) = phi;
		mX_B.scalarAt(2,1) = phi__d;
		mX_B.scalarAt(3,1) = psi__d;
		mU.scalarAt(1,1) = 0.0F;
		mY.scalarAt(1,1) = phi__d;
		mY.scalarAt(2,1) = psi__d;
		mY_B = mCd * mX_B;

		return mU.scalarAt(1,1);
	}
	else
	{
		TRVector<3U> uSummand = mBd * mU;
		TRVector<3U> xSummand = mAd * mX_B;
		TRVector<3U> ySummand = mLd * (mY - mY_B);
		mX_B = uSummand + xSummand + ySummand;
		mY_B = mCd * mX_B;
		mY.scalarAt(1,1) = phi__d;
		mY.scalarAt(2,1) = psi__d;

		TRVector<3U> x;
		x.scalarAt(1,1) = mX_B.scalarAt(1,1);
		x.scalarAt(2,1) = phi__d;
		x.scalarAt(3,1) = psi__d;
		mU   = mKd * x;
		//mU = mKd * mX_B;
		std::cout << "X_B:" << std::endl;
		mX_B.display();

		Float32 tm = -1.0F * mU.scalarAt(1,1);
		tm = tm > sMaxTorque  ? sMaxTorque  : tm;
		tm = tm < -sMaxTorque ? -sMaxTorque : tm;

		mU.scalarAt(1,1) = tm;
		return tm;
	}
}
void CLQB::reset()
{
	mFirstRun = true;
}