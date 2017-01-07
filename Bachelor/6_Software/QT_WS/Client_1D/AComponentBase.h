/**
 * @file	AComponentBase.h
 * @author	Michael Meindl
 * @date	5.10.2016
 */
#ifndef ACOMPONENTBASE_H
#define ACOMPONENTBASE_H
#include "TQueue.h"
#include "IRunnable.h"
#include "CProxy.h"

class AComponentBase : public IRunnable
{
public:
	virtual void run() = 0;
	virtual void init() = 0;
public:
	AComponentBase();
	AComponentBase(const AComponentBase&) = delete;
	AComponentBase& operator=(const AComponentBase&) = delete;
	virtual ~AComponentBase() = default;
protected:
    friend class CProxy;
    TQueue<12> mQueue;
	CProxy* mProxyPtr;
};

#endif
