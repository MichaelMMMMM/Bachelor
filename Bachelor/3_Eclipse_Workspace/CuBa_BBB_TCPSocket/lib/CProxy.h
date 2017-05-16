/**
 * @file	CProxy.h
 * @author	Michael Meindl
 * @date	5.10.2016
 */
#ifndef CPROXY_H
#define CPROXY_H
#include "CMessage.h"
#include "CMutex.h"
#include "CMPUData.h"
#include "CADCData.h"
#include "CTorqueData.h"
#include "TMatrix.h"

class AComponentBase;

class CProxy
{
public:
	static CProxy& getInstance();
	void registerCommComponent(AComponentBase* commComponent);
	void registerControlComponent(AComponentBase* controlComponent);

	bool timerTick(bool waitForever);
	bool clientConnect(bool waitForever);
	bool clientDisconnect(bool waitForever);
	bool routeClientMessage(CMessage& msg, bool waitForever);
	bool transmitSensorData(UInt32 sensorIndex, Float32 time, CMPUData& data, bool waitForever);
	bool transmitADCData(Float32 time, CADCData& data, bool waitForever);
	bool transmit1DCompLQRData(Float32 time, TRVector<4U>& data, bool waitForever);
	bool transmit1DPhiObsLQRData(Float32 time, TRVector<4U>& data, bool waitForever);
	bool transmit1DFullObsLQRData(Float32 time, TRVector<4U>& data, bool waitForever);
	bool transmit3DCompLQRPhi(Float32 time, TRVector<2U>& data, bool waitForever);
	bool transmit3DCompLQRUK(Float32 time, TRVector<3U>& data, bool waitForever);
	bool transmit3DCompLQRUR(Float32 time, TRVector<3U>& data, bool waitForever);
	bool transmit3DCompLQRTM(Float32 time, TRVector<3U>& data, bool waitForever);
private:
	CProxy();
	CProxy(const CProxy&) = delete;
	CProxy& operator=(const CProxy&) = delete;
	~CProxy() = default;
private:
	static volatile CProxy* sInstance;
	static CMutex sAccessMutex;
	AComponentBase* mCommPtr;
	AComponentBase* mControlPtr;
};

#endif
