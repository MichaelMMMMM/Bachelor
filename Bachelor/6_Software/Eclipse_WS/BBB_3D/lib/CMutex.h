/*
 * @file CBinarySemaphore.h
 * @author Michael Meindl
 * @date 18.9.2016
 * @brief Class definition for a mutex.
 */
#ifndef CMUTEX_H
#define CMUTEX_H
#include "Global.h"
#include <pthread.h>

class CMutex
{
public:
	bool take(bool waitForever);
	void give();
public:
	CMutex(bool isFull = true, bool isProcessShared = false);
	CMutex(const CMutex&) = delete;
	CMutex& operator=(const CMutex&) = delete;
	~CMutex();
private:
	pthread_mutex_t mMutex;
};


#endif
