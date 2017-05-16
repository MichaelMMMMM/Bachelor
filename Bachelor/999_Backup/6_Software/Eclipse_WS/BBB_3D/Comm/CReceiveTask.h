/**
 * @file	CReceiveTask.h
 * @author	Michael Meindl
 * @date	28.9.2016
 * @file	CReceiveTask.h
 */
#ifndef CRECEIVETASK_H
#define CRECEIVETASK_H
#include "IRunnable.h"
#include "CBinarySemaphore.h"
#include "CProxy.h"
#include "CServer.h"

class CReceiveTask : public IRunnable
{
public:
	/**
	 * Dummy method to satisfy the interface.
	 */
	void init() override;
	/**
	 * Waits for Rx-Messages on the connection, calls the proxy if the client disconnected.
	 */
	void run() override;
	/**
	 * param[in] waitForever	Specifies whether the caller wants to be blocked.
	 * return					Specifies whether the task was paused successfully.
	 */
	bool pause(bool waitForever);
	/**
	 * param[in] waitForever	Specifies whether the caller wants to be blocked.
	 * return 					Specifies whether the task was resumed successfully.
	 */
	bool resume(bool waitForever);
public:
	CReceiveTask(CServer& server);
	CReceiveTask(const CReceiveTask&) = delete;
	CReceiveTask& operator=(const CReceiveTask&) = delete;
	~CReceiveTask() = default;
private:
	CServer& mServer;
	CBinarySemaphore mRunningSem;
	CProxy* mProxyPtr;
};

#endif
