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
	SENSOR1DATA,
	SENSOR2DATA,
	SENSOR3DATA,
	SENSOR4DATA,
	SENSOR5DATA,
    SENSOR6DATA,
    ADCDATA
};

#endif