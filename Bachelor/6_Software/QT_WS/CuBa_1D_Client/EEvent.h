/**
 * @file	EEvent.h
 * @author	Michael Meindl
 * @date	4.10.2016
 */
#ifndef EEVENT_H
#define EEVENT_H
#include "Global.h"

enum class EEvent : UInt32
{
	INGORE 					= 0,
    INIT 					= 1,
	EXIT 					= 2,
	TIMER_TICK 				= 3,
	RUN_SENSOR_MEASUREMENT  = 4,
	RUN_ADC_MEASUREMENT     = 5,
	RUN_CPSI_IDENTIFICATION = 6,
	RUN_CPHI_IDENTIFICATION = 7,
	RUN_CONTROL_TEST		= 8,
	RUN_JUMP_TEST			= 9,
	RUN_CUBA				= 10,
	SET_TORQUE				= 12,
	SET_BALANCE_FLAG		= 13,
	SET_FILTER				= 14,
	SET_PHI_OFFSET			= 15,
	SET_PHI__D_OFFSET		= 16,
	SET_PSI__D_OFFSET		= 17,
	JUMP					= 18,
	IN_BALANCE_AREA			= 19,
	IN_IDLE_AREA			= 20,
	RESTING					= 21,
	MOVING					= 22,
	BRAKING_FINISHED		= 23,
	TX_SENSOR_DATA			= 24,
	TX_PHI_DATA				= 25,
	TX_PHI__D_DATA			= 26,
	TX_PSI__D_DATA			= 27,
	CLIENT_CONNECT			= 28,
	CLIENT_DISCONNECT		= 29,
	JUMP_VELOCITY_REACHED	= 30,
	SET_P_JUMP_VELOCITY		= 31,
    SET_N_JUMP_VELOCITY		= 32,
    SET_HIGHPASS_FLAG       = 33,
    SET_LQR_FLAG            = 34,
    SET_OBS_FLAG            = 35
};

#endif
