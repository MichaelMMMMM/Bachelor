#ifndef ASTATE_H
#define ASTATE_H
#include "EEvent.h"
#include "CMessage.h"

class AState
{
public:
	virtual bool dispatch(CMessage& msg) = 0;
	virtual bool tryEntry(CMessage& msg, AState*& statePtr) = 0;
	virtual void onEntry() = 0;
	virtual void onExit() = 0;
public:
	AState() = default;
	AState(const AState&) = delete;
	AState& operator=(const AState&) = delete;
	virtual ~AState() = default;
protected:
	static CMessage sInternalQueue;
	static UInt32 sQueueSize;
};

#endif
