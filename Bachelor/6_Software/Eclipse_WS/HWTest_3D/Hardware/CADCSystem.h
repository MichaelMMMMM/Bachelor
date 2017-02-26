/**
 * @file	CADCSystem.h
 * @author	Michael Meindl
 * @date	19.02.2017
 * @brief	Using a switch and a single analog input to sample the three motor speeds.
 */
#ifndef CADCSYSTEM_H
#define CADCSYSTEM_H
#include "CSwitch.h"
#include "CADCData.h"

class CADCSystem
{
public:
	bool fetchValues(CADCData& data);
public:
	CADCSystem();
	CADCSystem(const CADCSystem&) = delete;
	CADCSystem& operator=(const CADCSystem&) = delete;
	~CADCSystem() = default;
private:
	int sysfsEcho(const char* file, const char* string);
private:
	CSwitch mSwitch;
	int     mADCFD;
};

#endif
