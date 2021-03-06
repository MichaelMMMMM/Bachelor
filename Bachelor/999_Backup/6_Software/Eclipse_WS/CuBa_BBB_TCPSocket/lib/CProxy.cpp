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
bool CProxy::timerTick(bool waitForever)
{
	CMessage msg(EEvent::TIMER_TICK);
	return mControlPtr->mQueue.pushBack(msg, waitForever);
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
bool CProxy::transmitSensorData(UInt32 sensorIndex, Float32 time, CMPUData& data, bool waitForever)
{
	CMessage msg;
	switch(sensorIndex)
	{
	case 1U:
		msg = CMessage(EEvent::SENSOR1DATA, time);
		break;
	case 2U:
		msg = CMessage(EEvent::SENSOR2DATA, time);
		break;
	case 3U:
		msg = CMessage(EEvent::SENSOR3DATA, time);
		break;
	case 4U:
		msg = CMessage(EEvent::SENSOR4DATA, time);
		break;
	case 5U:
		msg = CMessage(EEvent::SENSOR5DATA, time);
		break;
	case 6U:
		msg = CMessage(EEvent::SENSOR6DATA, time);
		break;
	default:
		return false;
	}

	*reinterpret_cast<CMPUData*>(msg.getDataPtr()) = data;
	return mCommPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::transmitADCData(Float32 time, CADCData& data, bool waitForever)
{
	CMessage msg(EEvent::ADCDATA, time);
	*reinterpret_cast<CADCData*>(msg.getDataPtr()) = data;
	return mCommPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::transmit1DCompLQRData(Float32 time, TRVector<4U>& data, bool waitForever)
{
	CMessage msg(EEvent::COMPLQR_1D_DATA, time);
	Float32* ptr = reinterpret_cast<Float32*>(msg.getDataPtr());
	ptr[0] = data[1][1];
	ptr[1] = data[2][1];
	ptr[2] = data[3][1];
	ptr[3] = data[4][1];
	return mCommPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::transmit1DPhiObsLQRData(Float32 time, TRVector<4U>& data, bool waitForever)
{
	CMessage msg(EEvent::PHIOBSLQR_1D_DATA, time);
	Float32* ptr = reinterpret_cast<Float32*>(msg.getDataPtr());
	ptr[0] = data[1][1];
	ptr[1] = data[2][1];
	ptr[2] = data[3][1];
	ptr[3] = data[4][1];
	return mCommPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::transmit3DCompLQRPhi(Float32 time, TRVector<2U>& data, bool waitForever)
{
	CMessage msg(EEvent::COMPLQR_3D_PHI, time);
	Float32* ptr = reinterpret_cast<Float32*>(msg.getDataPtr());
	ptr[0] = data[1][1];
	ptr[1] = data[2][1];
	return mCommPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::transmit3DCompLQRUK(Float32 time, TRVector<3U>& data, bool waitForever)
{
	CMessage msg(EEvent::COMPLQR_3D_UK, time);
	Float32* ptr = reinterpret_cast<Float32*>(msg.getDataPtr());
	ptr[0] = data[1][1];
	ptr[1] = data[2][1];
	ptr[2] = data[3][1];
	return mCommPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::transmit3DCompLQRUR(Float32 time, TRVector<3U>& data, bool waitForever)
{
	CMessage msg(EEvent::COMPLQR_3D_UR, time);
	Float32* ptr = reinterpret_cast<Float32*>(msg.getDataPtr());
	ptr[0] = data[1][1];
	ptr[1] = data[2][1];
	ptr[2] = data[3][1];
	return mCommPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::transmit3DCompLQRTM(Float32 time, TRVector<3U>& data, bool waitForever)
{
	CMessage msg(EEvent::COMPLQR_3D_TM, time);
	Float32* ptr = reinterpret_cast<Float32*>(msg.getDataPtr());
	ptr[0] = data[1][1];
	ptr[1] = data[2][1];
	ptr[2] = data[3][1];
	return mCommPtr->mQueue.pushBack(msg, waitForever);
}
bool CProxy::transmit1DFullObsLQRData(Float32 time, TRVector<4U>& data, bool waitForever)
{
	CMessage msg(EEvent::FULLOBSLQR_1D_DATA, time);
	Float32* ptr = reinterpret_cast<Float32*>(msg.getDataPtr());
	ptr[0] = data[1][1];
	ptr[1] = data[2][1];
	ptr[2] = data[3][1];
	return mCommPtr->mQueue.pushBack(msg, waitForever);
}
