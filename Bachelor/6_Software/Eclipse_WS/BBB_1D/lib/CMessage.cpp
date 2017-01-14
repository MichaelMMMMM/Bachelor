/**
 * @file	CMessage.cpp
 * @author	Michael Meindl
 * @date	4.10.2016
 */
#include "CMessage.h"

CMessage::CMessage() : mEvent(EEvent::INGORE),
					   mData{0U}
{

}
CMessage::CMessage(EEvent event) : mEvent(event),
								   mData{0U}
{

}
CMessage::CMessage(const CSensorData& data) : mEvent(EEvent::TX_SENSOR_DATA),
											  mData{0U}
{
	*reinterpret_cast<CSensorData*>(mData) = data;
}
CMessage::CMessage(const CPhi& data) : mEvent(EEvent::TX_PHI_DATA),
									   mData{0U}
{
	*reinterpret_cast<CPhi*>(mData) = data;
}
CMessage::CMessage(const CPhi__d& data) : mEvent(EEvent::TX_PHI__D_DATA),
										  mData{0U}
{
	*reinterpret_cast<CPhi__d*>(mData) = data;
}
CMessage::CMessage(const CPsi__d& data) : mEvent(EEvent::TX_PSI__D_DATA),
										  mData{0U}
{
	*reinterpret_cast<CPsi__d*>(mData) = data;
}
EEvent CMessage::getEvent() const
{
	return mEvent;
}
Float32 CMessage::getTorque() const
{
	return *reinterpret_cast<const Float32*>(mData);
}
EFilter CMessage::getFilter() const
{
	return *reinterpret_cast<const EFilter*>(mData);
}
UInt8* CMessage::getDataPtr()
{
	return mData;
}
