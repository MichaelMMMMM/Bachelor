/**
 * @file	CProxy.cpp
 * @date	5.10.2016
 * @author	Michael Meindl
 */
#include "CProxy.h"
#include "AComponentBase.h"

volatile CProxy* CProxy::sInstance = nullptr;
CMutex CProxy::sAccessMutex{true, true};

CProxy& CProxy::getInstance()
{
	if(nullptr == sInstance)
	{
		sAccessMutex.take(true);
		if(nullptr == sInstance)
		{
			sInstance = new CProxy;
		}
	}
	return *const_cast<CProxy*>(sInstance);
}
CProxy::CProxy() : mCommPtr(nullptr),
				   mControlPtr(nullptr)
{

}
void CProxy::registerCommComponent(AComponentBase* commComp)
{
	mCommPtr = commComp;
}
void CProxy::registerControlComponent(AComponentBase* controlComp)
{
	mControlPtr = controlComp;
}
