/**
 * @file	CMessage.h
 * @author	Michael Meindl
 * @date	4.10.2016
 */
#ifndef CMESSAGE_H
#define CMESSAGE_H
#include "Global.h"
#include "EEvent.h"
#include "CSensorData.h"
#include "CPhi.h"
#include "CPhi__d.h"
#include "CPsi__d.h"
#include "EFilter.h"

class CMessage
{
public:
    EEvent getEvent() const;
    UInt8* getDataPtr();
	EFilter getFilter() const;
public:
	CMessage();
	CMessage(const CSensorData& data);
	CMessage(const CPhi& data);
	CMessage(const CPhi__d& data);
	CMessage(const CPsi__d& data);
	CMessage(EEvent event);
	CMessage(const CMessage&) = default;
	CMessage& operator=(const CMessage&) = default;
	~CMessage() = default;
private:
	static constexpr Int32 sDataSize = 20;
	EEvent mEvent;
	UInt8 mData[sDataSize];
};

#endif
