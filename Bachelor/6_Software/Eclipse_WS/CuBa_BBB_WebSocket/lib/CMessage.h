/**
 * @file	CMessage.h
 * @author	Michael Meindl
 * @date	08.02.2016
 * @brief	Data Abstraction for message objects.
 */
#ifndef CMESSAGE_H
#define CMESSAGE_H
#include "Global.h"
#include "EEvent.h"

class CMessage
{
public:
	EEvent getEvent() const;
	UInt8* getDataPtr();
public:
	CMessage();
	CMessage(EEvent event);
	CMessage(const CMessage&) = default;
	CMessage& operator=(const CMessage&) = default;
	~CMessage() = default;
private:
	static constexpr UInt32 sDataFieldSize = 16U;
	EEvent mEvent;
	UInt8 mData[16];
};

#endif
