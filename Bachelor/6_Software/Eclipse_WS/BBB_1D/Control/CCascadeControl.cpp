/**
 * @file	CCascadeControl.cpp
 * @author	Michael Meindl
 * @date	10.1.2017
 * @brief	Method definitiosn for CCascadeControl.
 */
#include "CCascadeControl.h"

Float32 CCascadeControl::calculateTorque(Float32 phi,
										 Float32 phi__d,
										 Float32 psi__d)
{
	float uLQR  = phi * ControlConfig::K_PHI +
				  phi__d * ControlConfig::K_PHI__D +
				  psi__d * ControlConfig::K_PSI__D;
	float uCasc = psi__d * ControlConfig::F_PSI__D * ControlConfig::V_PSI__D;
	return uLQR + uCasc;
}
