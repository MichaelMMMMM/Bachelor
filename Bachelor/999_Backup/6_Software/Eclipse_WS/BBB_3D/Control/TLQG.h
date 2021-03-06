/**
 * @file	TLQB.h
 * @author	Michael Meindl
 * @date	10.3.2017
 * @brief	Template class to realize a optimal controller + stationary kalman filter.
 */
#ifndef TLQG_H
#define TLQG_H
#include "TMatrix.h"

template<const UInt32 nrX, UInt32 nrU, UInt32 nrY>
class TLQG
{
public:
	CTorqueData calculateOutput(CStateData& x);
	void reset();
public:
	TLQG(const std::string& kFile,
		 const std::string& lFile,
		 const std::string& aFile,
		 const std::string& bFile,
		 const std::string& cFile,
		 const std::string& tkFile);
	TLQG(const TLQG&) = delete;
	TLQG& operator=(const TLQG&) = delete;
	~TLQG() = default;
private:
	TMatrix<nrU, nrX> mKd;
	TMatrix<nrX, nrY> mLd;
	TMatrix<nrX, nrX> mAd;
	TMatrix<nrX, nrU> mBd;
	TMatrix<nrY, nrX> mCd;
	TMatrix<nrX, 9U> mT_K;

	TRVector<nrY> mY;
	TRVector<nrY> mY_B;
	TRVector<nrX> mX_B;
	TRVector<nrX> mU_B;
	TRVector<nrU> mU;

	static constexpr Float32 sMaxU = 0.11F;
	bool mFirstRun;
};

template<const UInt32 nrX, const UInt32 nrU, const UInt32 nrY>
CTorqueData TLQG<nrX, nrU, nrY>::calculateOutput(CStateData& x)
{
	if(mFirstRun == true)
	{
		mFirstRun = false;
		TRVector<9U> x_vec;
		x_vec.scalarAt(1,1) = x.mGData.mG_k1;
		x_vec.scalarAt(2,1) = x.mGData.mG_k2;
		x_vec.scalarAt(3,1) = x.mGData.mG_k3;
		x_vec.scalarAt(4,1) = x.mUKData.mUK_k1;
		x_vec.scalarAt(5,1) = x.mUKData.mUK_k2;
		x_vec.scalarAt(6,1) = x.mUKData.mUK_k3;
		x_vec.scalarAt(7,1) = x.mURData.mUR_k1;
		x_vec.scalarAt(8,1) = x.mURData.mUR_k2;
		x_vec.scalarAt(9,1) = x.mURData.mUR_k3;
		mX_B = mT_K*x_vec;

		mY.scalarAt(1,1) = x.mUKData.mUK_k1;
		mY.scalarAt(2,1) = x.mUKData.mUK_k2;
		mY.scalarAt(3,1) = x.mUKData.mUK_k3;
		mY.scalarAt(4,1) = x.mURData.mUR_k1;
		mY.scalarAt(5,1) = x.mURData.mUR_k2;
		mY.scalarAt(6,1) = x.mURData.mUR_k3;

		mY_B = mCd * mX_B;

		mU = TRVector<nrU>();
	}
	else
	{
		TRVector<7U> uSummand = mBd * mU;
		TRVector<7U> xSummand = mAd * mX_B;
		TRVector<7U> ySummand = mLd * (mY - mY_B);
		mX_B = uSummand + xSummand + ySummand;
		mY_B = mCd * mX_B;

		mY.scalarAt(1,1) = x.mUKData.mUK_k1;
		mY.scalarAt(2,1) = x.mUKData.mUK_k2;
		mY.scalarAt(3,1) = x.mUKData.mUK_k3;
		mY.scalarAt(4,1) = x.mURData.mUR_k1;
		mY.scalarAt(5,1) = x.mURData.mUR_k2;
		mY.scalarAt(6,1) = x.mURData.mUR_k3;

		mU = mKd * mX_B;

		for(UInt32 i = 0; i < nrU; i++)
		{
			Float32 tm = -1.0F * mU.scalarAt(i, 1);
			tm = tm >  sMaxU ?  sMaxU : tm;
			tm = tm < -sMaxU ? -sMaxU : tm;
			mU.scalarAt(i,1) = tm;
		}
	}

	CTorqueData tm;
	tm.mTorque1 = mU.scalarAt(1,1);
	tm.mTorque2 = mU.scalarAt(2,1);
	tm.mTorque3 = mU.scalarAt(3,1);
	return tm;
}
template<const UInt32 nrX, const UInt32 nrU, const UInt32 nrY>
void TLQG<nrX, nrU, nrY>::reset()
{
	mFirstRun = true;
}
template<const UInt32 nrX, const UInt32 nrU, const UInt32 nrY>
TLQG<nrX, nrU, nrY>::TLQG(const std::string& kFile,
						  const std::string& lFile,
						  const std::string& aFile,
						  const std::string& bFile,
						  const std::string& cFile,
						  const std::string& tkFile) : mKd(kFile),
						  	  	  	  	  	  	  	   mLd(lFile),
													   mAd(aFile),
													   mBd(bFile),
													   mCd(cFile),
													   mT_K(tkFile),
													   mFirstRun(true)
{

}
#endif
