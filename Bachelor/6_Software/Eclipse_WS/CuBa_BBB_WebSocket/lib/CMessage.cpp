/**
 * @file	CMessage.cpp
 * @author	Michael Meindl
 * @date	08.02.2017
 * @brief	Method definitions for cpp.
 */
#include "CMessage.h"

CMessage::CMessage() : mEvent(EEvent::DEFAULT_IGNORE),
					   mData{0U}
{

}
CMessage::CMessage(EEvent event) : mEvent(event)
{

}
EEvent CMessage::getEvent() const
{
	return mEvent;
}
UInt8* CMessage::getDataPtr()
{
	return mData;
}
