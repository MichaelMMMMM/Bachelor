/*
 * @file	CLQB.h
 * @author	Michael Meindl
 * @date	2.3.2017
 * @brief	Class to calculate the observer + LQR-controller.
 */
#ifndef CLQB_H
#define CLQB_H
#include "Global.h"
#include "TMatrix.h"
#include <string>

class CLQB
{
public:
	Float32 calculateOutput(Float32 phi, Float32 phi__d, Float32 psi__d);
	void reset();
public:
	CLQB(const std::string& kFile,
		 const std::string& lFile,
		 const std::string& aFile,
		 const std::string& bFile,
		 const std::string& cFile);
	CLQB(const CLQB&) = delete;
	CLQB& operator=(const CLQB&) = delete;
	~CLQB() = default;
private:
	TCVector<3U>    mKd;
	TMatrix<3U, 2U> mLd;
	TMatrix<3U, 3U> mAd;
	TMatrix<3U, 1U> mBd;
	TMatrix<2U, 3U> mCd;

	TRVector<2U> mY;
	TRVector<2U> mY_B;
	TRVector<3U> mX_B;
	TRVector<3U> mU_B;
	TRVector<1U> mU;


	static constexpr Float32 sMaxTorque = 0.07F;
	bool mFirstRun;
};

#endif
