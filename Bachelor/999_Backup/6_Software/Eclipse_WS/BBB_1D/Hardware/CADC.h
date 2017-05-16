/**
 * @author	Michael Meindl
 * @date	6.12.2016
 * @brief	Hardware abstraction for the ADC.
 */
#ifndef CADC_H
#define CADC_H
#include "Global.h"

class CADC
{
public:
	bool fetchValue(UInt16& value);
public:
	CADC();
	~CADC();
private:
	int sysfsEcho(const char* file, const char* string);
private:
	int mADCFd;
};

#endif
