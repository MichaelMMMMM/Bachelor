/**
 * @file	CSensorCalibration.h
 * @author	Michael Meindl
 * @date	5.1.2017
 * @brief	Class definition for the state which handles sensor calibration.
 */
#ifndef CSENSORCALIBRATION_H
#define CSENSORCALIBRATION_H
#include "AState.h"
#include "CSensorCalibrationAction.h"

class CSensorCalibration : public AState
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
