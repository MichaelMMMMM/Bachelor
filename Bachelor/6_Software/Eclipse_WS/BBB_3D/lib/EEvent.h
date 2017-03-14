/**
 * @file	EEvent.h
 * @author	Michael Meindl
 * @date	08.02.2017
 * @brief	Enumeration for the events.
 */
#ifndef EEVENT_H
#define EEVENT_H
#include "Global.h"

enum class EEvent : UInt32
{
	DEFAULT_IGNORE,
	INIT,
	EXIT,
	CLIENT_CONNECT,
	CLIENT_DISCONNECT,
	TIMER_TICK,
	RUN_SENSOR_CALIBRATION,
	RUN_ADC_CALIBRATION,
	RUN_CONTROL,
	RUN_EDGE_BALANCE,
	SENSOR_1_DATA,
	SENSOR_2_DATA,
	SENSOR_3_DATA,
	SENSOR_4_DATA,
	SENSOR_5_DATA,
	SENSOR_6_DATA,
	ADC_DATA,
	TORQUE_DATA,
	G_DATA,
	UK_DATA,
	UR_DATA,
	COMPFILTER_ACTIVE_FLAG,
	OFFSETCORRECTION_ACTIVE_FLAG
};

#endif
