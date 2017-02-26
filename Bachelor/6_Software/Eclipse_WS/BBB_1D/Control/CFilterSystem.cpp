/**
 * @file	CFilterSystem.cpp
 * @author	Michael Meindl
 * @date	10.1.2017
 * @brief	Method definitions for CFilterSystem.
 */
#include "CFilterSystem.h"
#include <iostream>

CFilterSystem::CFilterSystem(CProxy& proxy) : mProxy(proxy),
											  mPhi__dPT1_5Hz(5.0F),
											  mPhi__dPT1_10Hz(10.0F),
											  mPsi__dPT1_5Hz(5.0F),
											  mPsi__dPT1_10Hz(10.0F),
											  mPhiOffset(ControlConfig::PHI_OFFSET),
								 	 	 	  mPhi__dOffset(0.0F),
											  mPsi__dOffset(0.0F),
											  mPhiFilter(EFilter::PHI_COMP),
											  mPhi__dFilter(EFilter::PHI__D_NONE),
											  mPsi__dFilter(EFilter::PSI__D_NONE),
											  mHighpassFlag(false),
											  mPhiHighpass(0.2F),
											  mPhi__dHighpass(0.2F),
											  mControlPhi(0.0F),
											  mControlPhi__d(0.0F),
											  mTime(0.0F)
{

}
void CFilterSystem::calculateValues(Float32 phi,
								    Float32 phi__d,
									Float32 psi__d)
{
	mPhi.mTime 			= mTime;
	mPhi.mEstimation 	= phi;
	mPhi.mComplementary	= mPhiCompFilter.calculateValues(phi, phi__d);

	mPhi__d.mTime		= mTime;
	mPhi__d.mEstimation = phi__d;
	mPhi__d.mPT1_5Hz	= mPhi__dPT1_5Hz.calculateOutput(phi__d);
	mPhi__d.mPT1_10Hz	= mPhi__dPT1_10Hz.calculateOutput(phi__d);

	mPsi__d.mTime		= mTime;
	mPsi__d.mEstimation = psi__d;
	mPsi__d.mPT1_5Hz	= mPsi__dPT1_5Hz.calculateOutput(psi__d);
	mPsi__d.mPT1_10Hz   = mPsi__dPT1_5Hz.calculateOutput(psi__d);

	mProxy.transmitPhi(mPhi, false);
	mProxy.transmitPhi__d(mPhi__d, false);
	mProxy.transmitPsi__d(mPsi__d, false);
	mTime += ControlConfig::Ta;
}
void CFilterSystem::setFilter(EFilter filter)
{
	switch(filter)
	{
	case EFilter::PHI_COMP:
	case EFilter::PHI_NONE:
		std::cout << "[*] Control-Comp: Setting phi-filter" << std::endl;
		mPhiFilter = filter;
		break;
	case EFilter::PHI__D_NONE:
	case EFilter::PHI__D_PT1_5HZ:
	case EFilter::PHI__D_PT1_10HZ:
		std::cout << "[*] Control-Comp: Setting phi__d-filter" << std::endl;
		mPhi__dFilter = filter;
		break;
	case EFilter::PSI__D_NONE:
	case EFilter::PSI__D_PT1_5HZ:
	case EFilter::PSI__D_PT1_10HZ:
		std::cout << "[*] Control-Comp: Setting psi__d-filter" << std::endl;
		mPsi__dFilter = filter;
		break;
	}
}
void CFilterSystem::calculateHighpass()
{
	if(mHighpassFlag)
	{
		mControlPhi 	= mPhiHighpass.calculateOutput(this->getFilteredPhi());
		mControlPhi__d 	= mPhi__dHighpass.calculateOutput(this->getFilteredPhi__d());
	}
	else
	{
		mControlPhi 	= this->getFilteredPhi() - mPhiOffset;
		mControlPhi__d  = this->getFilteredPhi__d() - mPhi__dOffset;
		mPhiHighpass.calculateOutput(mControlPhi);
		mPhi__dHighpass.calculateOutput(mControlPhi__d);
	}
}
void CFilterSystem::reset()
{
	mTime = 0.0F;
	new(&mPhiHighpass)CDT1(0.2F);
	new(&mPhi__dHighpass)CDT1(0.2F);
}
Float32 CFilterSystem::getFilteredPhi() const
{
	if(EFilter::PHI_COMP == mPhiFilter)
	{
		return mPhi.mComplementary;
	}
	if(EFilter::PHI_NONE == mPhiFilter)
	{
		return mPhi.mEstimation;
	}
	return 0.0F;
}
Float32 CFilterSystem::getFilteredPhi__d() const
{
	if(EFilter::PHI__D_NONE == mPhi__dFilter)
	{
		return mPhi__d.mEstimation;
	}
	if(EFilter::PHI__D_PT1_5HZ == mPhi__dFilter)
	{
		return mPhi__d.mPT1_5Hz;
	}
	if(EFilter::PHI__D_PT1_10HZ == mPhi__dFilter)
	{
		return mPhi__d.mPT1_10Hz;
	}
	return 0.0F;
}
Float32 CFilterSystem::getFilteredPsi__d() const
{
	if(EFilter::PSI__D_NONE == mPsi__dFilter)
	{
		return mPsi__d.mEstimation;
	}
	if(EFilter::PSI__D_PT1_5HZ == mPsi__dFilter)
	{
		return mPsi__d.mPT1_5Hz;
	}
	if(EFilter::PSI__D_PT1_10HZ == mPsi__dFilter)
	{
		return mPsi__d.mPT1_10Hz;
	}
	return 0.0F;
}
void CFilterSystem::setPhiOffset(Float32 offset)
{
	mPhiOffset    = offset;
}
void CFilterSystem::setPhi__dOffset(Float32 offset)
{
	mPhi__dOffset = offset;
}
void CFilterSystem::setPsi__dOffset(Float32 offset)
{
	mPsi__dOffset = offset;
}
Float32 CFilterSystem::getControlPhi() const
{
	return mControlPhi;
}
Float32 CFilterSystem::getControlPhi__d() const
{
	return mControlPhi__d;
}
Float32 CFilterSystem::getControlPsi__d() const
{
	return this->getFilteredPsi__d() - mPsi__dOffset;
}
void CFilterSystem::setHighpassFlag(bool flag)
{
	if(flag == true)
	{
		std::cout << "[*] Control-Comp: Enabling Highpass-Filters" << std::endl;
	}
	else
	{
		std::cout << "[*] Control-Comp: Disabling Highpass-Filters" << std::endl;
	}
	mHighpassFlag = flag;
}
