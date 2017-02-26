/**
 * @file	CLQRControl.cpp
 * @author	Michael Meindl
 * @date	10.1.2017
 * @brief	Method defintionsf or CLQRControl.
 */
#include "CLQRControl.h"
#include "ControlConfig.h"

CLQRControl::CLQRControl()
{

}
Float32 CLQRControl::calculateTorque(Float32 phi,
									 Float32 phi__d,
									 Float32 psi__d)
{
	return ControlConfig::K_PHI * phi +
		   ControlConfig::K_PHI__D * phi__d +
		   ControlConfig::K_PSI__D * psi__d;
}
