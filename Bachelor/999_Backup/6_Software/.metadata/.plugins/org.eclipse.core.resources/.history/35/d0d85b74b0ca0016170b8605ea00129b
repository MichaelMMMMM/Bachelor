/**
 * @file	CProxy.h
 * @author	Michael Meindl
 * @date	5.10.2016
 */
#ifndef CPROXY_H
#define CPROXY_H
#include "CMessage.h"
#include "CMutex.h"
#include "CSensorData.h"
#include "CPhi.h"
#include "CPhi__d.h"
#include "CPsi__d.h"

class AComponentBase;

class CProxy
{
public:
	static CProxy& getInstance();
	void registerCommComponent(AComponentBase* commComponent);
	void registerControlComponent(AComponentBase* controlComponent);

	bool transmitSensorData(const CSensorData& data, bool waitForever);
	bool transmitPhi(const CPhi& data, bool waitForever);
	bool transmitPhi__d(const CPhi__d& data, bool waitForever);
	bool transmitPsi__d(const CPsi__d& data, bool waitForever);
	bool clientConnect(bool waitForever);
	bool clientDisconnect(bool waitForever);
	bool routeMATLABMessage(CMessage& msg, bool waitForever);
	bool timerTick(bool waitForever);
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
