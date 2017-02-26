/**
 * @file	CADCCalibration.h
 * @author	Michael Meindl
 * @date	9.1.2017
 * @brief	State class for the adc-calibration experiment.
 */
#ifndef CADCCALIBRATION_H
#define CADCCALIBRATION_H
#include "AState.h"
#include "CADCCalibrationAction.h"

class CADCCalibration : public AState
{
public:
	bool dispatch(CMessage& msg);
	bool tryEntry(CMessage& msg, AState*& statePtr) override;
	void onEntry() override;
	void onExit() override;
public:
	CADCCalibration();
	CADCCalibration(const CADCCalibration&) = delete;
	CADCCalibration& operator=(const CADCCalibration&) = delete;
	~CADCCalibration() = default;
private:
	CADCCalibrationAction mAction;
};


#endif
