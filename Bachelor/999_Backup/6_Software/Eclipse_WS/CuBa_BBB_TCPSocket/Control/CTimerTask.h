/**
 * @file	CTimerTask.h
 * @author	Michael Meindl
 * @date	28.9.2016
 * @brief	Class definition for the timer task.
 */
#ifndef CTIMERTASK_H
#define CTIMERTASK_H
#include "IRunnable.h"
#include "CBinarySemaphore.h"
#include "CProxy.h"

class CTimerTask : public IRunnable
{
public:
	void init() override;
	void run() override;
	bool pause(bool waitForever);
	bool resume(bool waitForever);
	void setPeriodMS(Int32 period);
public:
	CTimerTask();
	CTimerTask(const CTimerTask&) = delete;
	CTimerTask& operator=(const CTimerTask&) = delete;
	~CTimerTask() = default;
private:
	CBinarySemaphore mRunningSem;
	CProxy* 		 mProxyPtr;
	Int32			 mPeriodMS;
};

#endif
