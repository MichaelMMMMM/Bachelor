/**
 * @file CBinarySemaphore.cpp
 * @author Michael Meindl
 * @date 24.9.2016
 * @brief Method definitions for a counting semaphore, which is simulated using a mutex.
 */
#include "CCountingSemaphore.h"
#include "Assertion.h"

CCountingSemaphore::CCountingSemaphore(bool isProcessShared, Int32 startingValue) : mCounter(startingValue)
{
	Int32 retVal;
	pthread_mutexattr_t mutexAttr;
	retVal = pthread_mutexattr_init(&mutexAttr);
	sAssertion(0 == retVal, "(CCoutingSemaphore::CCountingSemaphore()) : Failed to init Mutex-Attribute!", true);

	retVal = pthread_mutexattr_settype(&mutexAttr, PTHREAD_MUTEX_ERRORCHECK);
	sAssertion(0 == retVal, "(CCountingSemaphore::CCountingSemaphore()) : Failed to set Mutex-Type!", true);

	retVal = pthread_mutex_init(&mMutex, &mutexAttr);
	sAssertion(0 == retVal , "(CCountingSemaphore::CCountingSemaphore()) : Failed to init Mutex!", true);

	retVal = pthread_mutexattr_destroy(&mutexAttr);
	sAssertion(0 == retVal, "(CCountingSemaphore::CCountingSemaphore()) : Failed to destroy Mutex-Attribute!", true);

	pthread_condattr_t conditionAttr;
	retVal = pthread_condattr_init(&conditionAttr);
	sAssertion(0 == retVal, "(CCountingSemaphore::CCoutingSemaphore()) : Failed to init Condition-Attribute!", true);

	retVal = pthread_condattr_setpshared(&conditionAttr, isProcessShared ?
										 PTHREAD_PROCESS_SHARED : PTHREAD_PROCESS_PRIVATE);
	sAssertion(0 == retVal, "(CCoutingSmeaphore::CCoutingSemaphore()) : Failed to set Condition-Attribute!", true);

	pthread_cond_init(&mCondition, &conditionAttr);
	pthread_condattr_destroy(&conditionAttr);
}
CCountingSemaphore::~CCountingSemaphore()
{
	pthread_mutex_destroy(&mMutex);

	Int32 retVal = pthread_cond_destroy(&mCondition);
	sAssertion(0 == retVal, "(CCountingSemaphore::~CCountingSemaphore()) : Failed to destroy condition variable!", true);
}
bool CCountingSemaphore::take(bool waitForever)
{
	bool result = true;
	pthread_mutex_lock(&mMutex);
	if(0 < mCounter)
	{
		mCounter--;
	}
	else if(false == waitForever)
	{
		result = false;
	}
	else
	{
		while(0 == mCounter)
		{
			pthread_cond_wait(&mCondition, &mMutex);
		}
		mCounter--;
	}
	pthread_mutex_unlock(&mMutex);
	return result;
}
void CCountingSemaphore::give()
{
	pthread_mutex_lock(&mMutex);
	mCounter++;
	pthread_mutex_unlock(&mMutex);
	pthread_cond_signal(&mCondition);
}
