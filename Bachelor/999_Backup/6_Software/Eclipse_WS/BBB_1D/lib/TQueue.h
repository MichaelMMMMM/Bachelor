/**
 * @file TQueue.h
 * @author Michael Meindl
 * @date 24.9.2016
 * @brief File containing a template class implementing a queue for communication
 */
#ifndef TQUEUE_H
#define TQUEUE_H
#include "Global.h"
#include "CCountingSemaphore.h"
#include "CMutex.h"
#include "CMessage.h"

template<const Int32 size>
class TQueue
{
public:
	/**
	 * Method to add a message to the back of the queue.
	 * \param[in] msg 			Specifies the message which shall be pushed to the back of the queue.
	 * \param[in] waitForever	Specifies whether the thread shall be blocked until the message can be pushed.
	 * \return 					Returns true if the message was pushed successfully.
	 */
	bool pushBack(const CMessage& msg, bool waitForever);
	/**
	 * Method to add a message to the front of the queue.
	 * \param[in] msg 			Specifies the message which shall be pushed to the front of the queue.
	 * \param[in] waitForever	Specifies whether the thread shall be blocked until the message can be pushed.
	 * \return 					Returns true if the message was pushed successfully.
	 */
	//bool pushFront(const CMessage& msg, bool waitForever);
	/**
	 * Method to get a message from the front of the queue.
	 * \param[out] msg 			On success the popped message will be placed in the reference instance.
	 * \param[in] waitForever 	Specifies whether the thread shall be blocked until a message can the popped.
	 * \return 					Returns true if the message was popped successfully.
	 */
	bool popFront(CMessage& msg, bool waitForever);
public:
	TQueue();
	TQueue(const TQueue<size>&) = delete;
	TQueue<size>& operator=(const TQueue<size>&) = delete;
	~TQueue() = default;
private:
	static constexpr Int32 sSize = size;
	CCountingSemaphore mReadSem;
	CCountingSemaphore mWriteSem;
	CMutex mAccessMutex;
	CMessage mQueue[sSize];
	Int32 mHeadIndex;
	Int32 mTailIndex;
};

template<const Int32 size>
TQueue<size>::TQueue() : mReadSem(true, 0),
						 mWriteSem(true, sSize),
						 mAccessMutex(true, true),
						 mQueue{},
						 mHeadIndex(0),
						 mTailIndex(0)
{

}
template<const Int32 size>
bool TQueue<size>::pushBack(const CMessage& msg, bool waitForever)
{
	bool success = true;
	if(false == mWriteSem.take(waitForever))
	{
		success = false;
	}
	else if(false == mAccessMutex.take(waitForever))
	{
		mWriteSem.give();
		success = false;
	}
	else
	{
		mQueue[mTailIndex] = msg;
		mTailIndex = (mTailIndex == (size - 1)) ? 0 : (mTailIndex + 1);
		success = true;
		mReadSem.give();
		mAccessMutex.give();
	}
	return success;

}
/*
template<const Int32 size>
bool TQueue<size>::pushFront(const CMessage& msg, bool waitForever)
{
	bool success = true;
	if(false == mReadSem.take(waitForever))
	{
		success = false;
	}
	else if(false == mAccessMutex.take(waitForever))
	{
		success = false;
	}
	else
	{
		mHeadIndex = (mHeadIndex == 0) ? (sSize - 1) : (mHeadIndex - 1);
		mQueue[mHeadIndex] = msg;
		success = true;
		mReadSem.give();
		mAccessMutex.give();
	}
	return success;
}
*/
template<const Int32 size>
bool TQueue<size>::popFront(CMessage& msg, bool waitForever)
{
	bool success = true;
	if(false == mReadSem.take(waitForever))
	{
		success = false;
	}
	else if(false == mAccessMutex.take(waitForever))
	{
		mReadSem.give();
		success = false;
	}
	else
	{
		msg = mQueue[mHeadIndex];
		mHeadIndex = (mHeadIndex == (sSize - 1)) ? 0 : (mHeadIndex + 1);
		success = true;
		mWriteSem.give();
		mAccessMutex.give();
	}
	return success;
}
#endif
