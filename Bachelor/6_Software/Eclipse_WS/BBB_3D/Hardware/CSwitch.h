/**
 * @file	CSwitch.h
 * @author	Michael Meindl
 * @date	06.02.2017
 * @brief	Class to control the MAX4617 Analog-Switch.
 */
#ifndef CSWITCH_H
#define CSWITCH_H
#include "CGPIO.h"

class CSwitch
{
public:
	void selectX0();
	void selectX1();
	void selectX2();
	void selectX3();
	void selectX4();
	void selectX5();
	void selectX6();
	void selectX7();
public:
	CSwitch(const std::string& pinANr,
			const std::string& pinBNr,
			const std::string& pinCNr,
			const std::string& enablePinNr);
	CSwitch(const CSwitch&) = delete;
	CSwitch& operator=(const CSwitch&) = delete;
	~CSwitch() = default;
private:
	void enable();
	void disable();
private:
	CGPIO mPinA;
	CGPIO mPinB;
	CGPIO mPinC;
	CGPIO mEnablePin;
};

#endif
