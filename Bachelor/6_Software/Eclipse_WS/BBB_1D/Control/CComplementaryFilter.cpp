//26.8.16, Michael Meindl
#include "CComplementaryFilter.h"
#include "ControlConfig.h"
#include <cmath>

CComplementaryFilter::CComplementaryFilter() : mFilteredPhi(0.0F),
											   mRecentPhi_C(0.0F),
											   mFirstRun(true),
											   mPadding{0U}
{

}
Float32 CComplementaryFilter::calculateValues(const Float32 phi,
										   const Float32 phi__d)
{
	if(true == mFirstRun)
	{
		///Initial run, use the unfiltered values
		mFirstRun 			= false;
		mRecentPhi_C  		= phi;
	}
	//Calculate the filtered Phi value
	Float32 firstSummand = mRecentPhi_C  + (ControlConfig::Ta * phi__d);
	mFilteredPhi = ControlConfig::CompAlpha * firstSummand +
					( (1 - ControlConfig::CompAlpha) * phi );
	//Save the recent values
	mRecentPhi_C 	= mFilteredPhi;
	return mFilteredPhi;
}
Float32 CComplementaryFilter::getPhi()
{
	return mFilteredPhi;
}
