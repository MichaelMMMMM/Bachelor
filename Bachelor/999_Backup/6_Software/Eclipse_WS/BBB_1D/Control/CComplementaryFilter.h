//26.8.16, Michael Meindl
#ifndef CCOMPLEMENTARYFILTER_H
#define CCOMPLEMENTARYFILTER_H
#include "Global.h"

///Class to filter Phi and Phi__d using a complementary filter.
class CComplementaryFilter
{
public:
	Float32 calculateValues(const Float32 phi,
						    const Float32 phi__d);
	Float32 getPhi();
public:
	CComplementaryFilter();
	CComplementaryFilter(const CComplementaryFilter&) = delete;
	CComplementaryFilter& operator=(const CComplementaryFilter&) = delete;
	~CComplementaryFilter() = default;
private:
	Float32 mFilteredPhi;		///< The latest filtered value for Phi
	Float32 mRecentPhi_C;		///< The recent filtered value for Phi
	bool mFirstRun;				///< Flag to indicate the first iteration of the filter
	UInt8 mPadding[3];			///< Fill bytes to prevent padding problems and compiler warnings
};

#endif
