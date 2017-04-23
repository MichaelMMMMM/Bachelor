/**
 * @file	E1DControlSystem.h
 * @author	Michael Meindl
 * @date	19.04.2017
 * @brief	Enumeration to hold the different Control-Systems for Edge-Balancing.
 */
#ifndef E1DCONTROLSYSTEM_H
#define E1DCONTROLSYSTEM_H
#include "Global.h"

enum class E1DControlSystem : UInt32
{
	COMP_LQR 		= 0U,
	PHI_OBS_LQR 	= 1U,
	OFFSET_OBS_LQR 	= 2U
};

#endif
