/**
 * @file	CSwitch.cpp
 * @author	Michael Meindl
 * @date	06.02.2017
 * @brief	Method definitions for CSwitch.
 */
#include "CSwitch.h"

CSwitch::CSwitch(const std::string& pinANr,
				 const std::string& pinBNr,
				 const std::string& pinCNr,
				 const std::string& enablePinNr) : mPinA(pinANr),
				 	 	 	 	 	 	 	 	   mPinB(pinBNr),
												   mPinC(pinCNr),
												   mEnablePin(enablePinNr)
{
	this->disable();
}
void CSwitch::enable()
{
	mEnablePin.setLow();
}
void CSwitch::disable()
{
	mEnablePin.setHigh();
}
void CSwitch::selectX0()
{
	this->disable();
	mPinA.setLow();
	mPinB.setLow();
	mPinC.setLow();
	this->enable();
}
void CSwitch::selectX1()
{
	this->disable();
	mPinA.setHigh();
	mPinB.setLow();
	mPinC.setLow();
	this->enable();
}
void CSwitch::selectX2()
{
	this->disable();
	mPinA.setLow();
	mPinB.setHigh();
	mPinC.setLow();
	this->enable();
}
void CSwitch::selectX3()
{
	this->disable();
	mPinA.setHigh();
	mPinB.setHigh();
	mPinC.setLow();
	this->enable();
}
void CSwitch::selectX4()
{
	this->disable();
	mPinA.setLow();
	mPinB.setLow();
	mPinC.setHigh();
	this->enable();
}
void CSwitch::selectX5()
{
	this->disable();
	mPinA.setHigh();
	mPinB.setLow();
	mPinC.setHigh();
	this->enable();
}
void CSwitch::selectX6()
{
	this->disable();
	mPinA.setLow();
	mPinB.setHigh();
	mPinC.setHigh();
	this->enable();
}
void CSwitch::selectX7()
{
	this->disable();
	mPinA.setHigh();
	mPinB.setHigh();
	mPinC.setHigh();
	this->enable();
}
