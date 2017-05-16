/*
 * @file CBinarySemaphore.h
 * @author Michael Meindl
 * @date 18.9.2016
 * @brief Class definition for a couting semaphore, which is sumulated using a mutex.
 */
#ifndef CCOUNTINGSEMAPHORE_H
#define CCOUNTINGSEMAPHORE_H
#include "Global.h"
#include <pthread.h>

class CCountingSemaphore
{
public:
	bool take(bool waitForever);
	void give();
public:
	CCountingSemaphore(bool isProcessShared, Int32 startingValue);
	CCountingSemaphore() = delete;
	CCountingSemaphore(const CCountingSemaphore&) = delete;
	~CCountingSemaphore();
private:
	pthread_mutex_t mMutex;
	pthread_cond_t mCondition;
	Int32 mCounter;
};

#endif
