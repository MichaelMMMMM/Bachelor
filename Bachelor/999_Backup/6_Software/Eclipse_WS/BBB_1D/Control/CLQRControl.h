/**
 * @file	CLQRControl.h
 * @author	Michael Meindl
 * @date	10.1.2017
 * @brief	Class for the lqr-controller.
 */
#ifndef CLQRCONTROL_H
#define CLQRCONTROL_H
#include "ControlConfig.h"

class CLQRControl
{
public:
	Float32 calculateTorque(Float32 phi, Float32 phi__d, Float32 psi__d);
public:
	CLQRControl();
	CLQRControl(const CLQRControl&) = delete;
	CLQRControl& operator=(const CLQRControl&) = delete;
	~CLQRControl() = default;
};

#endif
