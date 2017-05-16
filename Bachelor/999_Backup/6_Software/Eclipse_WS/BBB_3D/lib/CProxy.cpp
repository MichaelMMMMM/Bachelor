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
bool CProxy::clientConnect(bool waitForever)
{
	CMessage msg(EEvent::CLIENT_CONNECT);
	return mCommPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::clientDisconnect(bool waitForever)
{
	CMessage msg(EEvent::CLIENT_DISCONNECT);
	bool retVal = mControlPtr->mQueue.pushBack(msg, waitForever);
	return mCommPtr->mQueue.pushBack(msg, waitForever) && retVal;
}
bool CProxy::routeClientMessage(CMessage& msg, bool waitForever)
{
	return mControlPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::timerTick(bool waitForever)
{
	CMessage msg(EEvent::TIMER_TICK);
	return mControlPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::transmitSensorData(EEvent event, CMPUData& data, bool waitForever)
{
	CMessage msg(event);
	*reinterpret_cast<CMPUData*>(msg.getDataPtr()) = data;
	return mCommPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::transmitADCData(CADCData& data, bool waitForever)
{
	CMessage msg(EEvent::ADC_DATA);
	*reinterpret_cast<CADCData*>(msg.getDataPtr()) = data;
	return mCommPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::transmitTorqueData(CTorqueData& data, bool waitForever)
{
	CMessage msg(EEvent::TORQUE_DATA);
	*reinterpret_cast<CTorqueData*>(msg.getDataPtr()) = data;
	return mCommPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::transmitGData(const CGData& data, bool waitForever)
{
	CMessage msg(EEvent::G_DATA);
	*reinterpret_cast<CGData*>(msg.getDataPtr()) = data;
	return mCommPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::transmitUKData(const CUKData& data, bool waitForever)
{
	CMessage msg(EEvent::UK_DATA);
	*reinterpret_cast<CUKData*>(msg.getDataPtr()) = data;
	return mCommPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::transmitURData(const CURData& data, bool waitForever)
{
	CMessage msg(EEvent::UR_DATA);
	*reinterpret_cast<CURData*>(msg.getDataPtr()) = data;
	return mCommPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::transmitLQRData1D(const TRVector<4U>& data, bool waitForever)
{
	CMessage msg(EEvent::LQR_DATA_1D);
	*reinterpret_cast<TRVector<4U>*>(msg.getDataPtr()) = data;
	return mCommPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::transmitLQGData1D(const TRVector<4U>& data, bool waitForever)
{
	CMessage msg(EEvent::LQG_DATA_1D);
	*reinterpret_cast<TRVector<4U>*>(msg.getDataPtr()) = data;
	return mCommPtr->mQueue.pushBack(msg, waitForever);
}
