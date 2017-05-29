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
	RUN_EDGE_BALANCE,
	RUN_CORNER_BALANCE,
	SENSOR1DATA,
	SENSOR2DATA,
	SENSOR3DATA,
	SENSOR4DATA,
	SENSOR5DATA,
    SENSOR6DATA,
    ADCDATA,
	IN_BALANCE_AREA,
	IN_IDLE_AREA,
	COMPLQR_1D_DATA,
	PHIOBSLQR_1D_DATA,
	FULLOBSLQR_1D_DATA,
	COMPLQR_3D_PHI,
	COMPLQR_3D_UK,
	COMPLQR_3D_UR,
	COMPLQR_3D_TM,
	PHI_OFFSET,
	UK_OFFSET,
	UR_OFFSET,
    SELECT_1D_CONTROL,
	RELOAD_CONFIG
};

#endif