/**
 * @file	CMessage.cpp
 * @author	Michael Meindl
 * @date	08.02.2017
 * @brief	Method definitions for cpp.
 */
#include "CMessage.h"

CMessage::CMessage() : mEvent(EEvent::DEFAULT_IGNORE),
                       mTime(0.0F),
                       mData{0U}
{

}
CMessage::CMessage(EEvent event) : mEvent(event), mTime(0.0F)
{

}
CMessage::CMessage(EEvent event, Float32 time) : mEvent(event), mTime(time)
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
void CMessage::setTime(Float32 time)
{
    mTime = time;
}
Float32 CMessage::getTime()
{
    return mTime;
}
