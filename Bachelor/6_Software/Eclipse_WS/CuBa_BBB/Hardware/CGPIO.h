/**
 * @file	CGPIO.h
 * @author	Michael Meindl
 * @date	30.01.2016
 * @brief	Class to handle the GPIO-Outputs.
 */
#ifndef CGPIO_H
#define CGPIO_H
#include "Global.h"
#include <string>

class CGPIO
{
public:
	bool setHigh();
	bool setLow();
public:
	CGPIO(const std::string& gpioNr);
	CGPIO(const CGPIO&) = delete;
	CGPIO& operator=(const CGPIO&) = delete;
	~CGPIO() = default;
private:
	int mValueFD;
};

#endif
