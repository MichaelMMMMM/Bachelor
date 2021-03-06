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
#include "CStateData.h"
#include "TMatrix.h"

class AComponentBase;

class CProxy
{
public:
	static CProxy& getInstance();
	void registerCommComponent(AComponentBase* commComponent);
	void registerControlComponent(AComponentBase* controlComponent);

	bool clientConnect(bool waitForever);
	bool clientDisconnect(bool waitForever);
	bool routeClientMessage(CMessage& msg, bool waitForever);
	bool timerTick(bool waitForever);
	bool transmitSensorData(EEvent event, CMPUData& data, bool waitForever);
	bool transmitADCData(CADCData& data, bool waitForever);
	bool transmitTorqueData(CTorqueData& data, bool waitForever);
	bool transmitGData(const CGData& data, bool waitForever);
	bool transmitUKData(const CUKData& data, bool waitForever);
	bool transmitURData(const CURData& data, bool waitForever);
	bool transmitLQRData1D(const TRVector<4U>& data, bool waitForever);
	bool transmitLQGData1D(const TRVector<4U>& data, bool waitForever);
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
