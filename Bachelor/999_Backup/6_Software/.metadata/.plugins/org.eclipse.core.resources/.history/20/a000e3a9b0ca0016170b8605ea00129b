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
bool CProxy::transmitSensorData(const CSensorData& data, bool waitForever)
{
	CMessage msg(data);
	return mCommPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::transmitPhi(const CPhi& data, bool waitForever)
{
	CMessage msg(data);
	return mCommPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::transmitPhi__d(const CPhi__d& data, bool waitForever)
{
	CMessage msg(data);
	return mCommPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::transmitPsi__d(const CPsi__d& data, bool waitForever)
{
	CMessage msg(data);
	return mCommPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::clientConnect(bool waitForever)
{
	CMessage msg(EEvent::CLIENT_CONNECT);
	mControlPtr->mQueue.pushBack(msg, waitForever);
	return mCommPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::clientDisconnect(bool waitForever)
{
	CMessage msg(EEvent::CLIENT_DISCONNECT);
	bool retVal = mControlPtr->mQueue.pushBack(msg, waitForever);
	return retVal && mCommPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::routeMATLABMessage(CMessage& msg, bool waitForever)
{
	return mControlPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::timerTick(bool waitForever)
{
	CMessage msg(EEvent::TIMER_TICK);
	return mControlPtr->mQueue.pushBack(msg, waitForever);
}
void CProxy::registerCommComponent(AComponentBase* commComp)
{
	mCommPtr = commComp;
}
void CProxy::registerControlComponent(AComponentBase* controlComp)
{
	mControlPtr = controlComp;
}
