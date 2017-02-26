/**
 * @file	CSensorCalibration.h
 * @author	Michael Meindl
 * @date	08.02.2017
 * @brief	State-Class to handle the Calibration-Experiment for the sensors.
 */
#ifndef CSENSORCALIBRATION_H
#define CSENSORCALIBRATION_H
#include "AState.h"
#include "CSensorCalibrationAction.h"

class CSensorCalibration : AState
{
public:
	bool dispatch(CMessage& msg) override;
	bool tryEntry(CMessage& msg, AState*& statePtr) override;
	void onEntry() override;
	void onExit() override;
public:
	CSensorCalibration() = default;
	CSensorCalibration(const CSensorCalibration&) = delete;
	CSensorCalibration& operator=(const CSensorCalibration&) = delete;
	~CSensorCalibration() = default;
private:
	CSensorCalibrationAction mAction;
};

#endif
