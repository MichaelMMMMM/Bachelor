/**
 * @file	CCascadeControl.h
 * @author	Michael Meindl
 * @date	10.1.2017
 * @brief	Class to calculate the cascade-controller.
 */
#ifndef CCASCADECONTROL_H
#define CCASCADECONTROL_H
#include "ControlConfig.h"

class CCascadeControl
{
public:
	Float32 calculateTorque(Float32 phi,
							Float32 phi__d,
							Float32 psi__d);
public:
	CCascadeControl() = default;
	CCascadeControl(const CCascadeControl&) = delete;
	CCascadeControl& operator=(const CCascadeControl&) = delete;
	~CCascadeControl() = default;
};

#endif
