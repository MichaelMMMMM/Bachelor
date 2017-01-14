/**
 * @file	ControlConfig.h
 * @author	Michael Meindl
 * @date	5.1.2017
 * @brief	Definition of general constants.
 */
#ifndef CONTROLCONFIG_H
#define CONTROLCONFIG_H
#include "Global.h"

namespace ControlConfig
{
	constexpr Float32 Ta 					= 0.02F;
	constexpr Float32 CompAlpha 			= 0.98F;
	constexpr Float32 R_S1					= 0.14F;
	constexpr Float32 R_S2					= 0.061F;
	constexpr Float32 SensorAlpha			= R_S1/R_S2;
	constexpr Float32 Phi1__d_P1			= -0.00013265F;
	constexpr Float32 Phi1__d_P2			= 120.2720F;
	constexpr Float32 Phi2__d_P1			= -0.00013265F;
	constexpr Float32 Phi2__d_P2			= -78.732F;
	constexpr Float32 Psi__d_P1				= -0.1533F;
	constexpr Float32 Psi__d_P2				= 312.4F;
	constexpr Float32 X1__dd_P1				= -0.0005974F;
	constexpr Float32 X1__dd_P2				= 0.4844F;
	constexpr Float32 X2__dd_P1				= -0.0005982F;
	constexpr Float32 X2__dd_P2				= 0.5574F;
	constexpr Float32 Y1__dd_P1				= -0.0005947F;
	constexpr Float32 Y1__dd_P2				= -0.06525F;
	constexpr Float32 Y2__dd_P1				= -0.0005974F;
	constexpr Float32 Y2__dd_P2				= -0.04301F;
	constexpr Float32 PHI_BALANCE_MAX		= 0.15F;
	constexpr Float32 K_PHI					= 1.143F;
	constexpr Float32 K_PHI__D				= 0.1498F;
	constexpr Float32 K_PSI__D				= 0.0004F;
	constexpr Float32 F_PSI__D				= -0.2F;
	constexpr Float32 V_PSI__D				= -0.0036F;
	constexpr Float32 PHI_OFFSET			= 0.13F;
}

#endif
