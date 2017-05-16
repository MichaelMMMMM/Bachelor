/**
 * @file	CADCCalibrationAction.h
 * @author	Michael Meindl
 * @date	8.1.2017
 * @brief	Action handler class for the adc-calibration experiment.
 */
#ifndef CADCCALIBRATIONACTION_H
#define CADCCALIBRATIONACTION_H
#include "CControlActionBase.h"
#include "Global.h"

class CADCCalibrationAction : public CControlActionBase
{
public:
	void entryADCCalibration();
	void exitADCCalibration();
	void sampleADCCalibration();
	void setTorque(Float32 torque);
public:
	CADCCalibrationAction();
	CADCCalibrationAction(const CADCCalibrationAction&) = delete;
	CADCCalibrationAction& operator=(const CADCCalibrationAction&) = delete;
	~CADCCalibrationAction() = default;
private:
	Float32 mTime;
};

#endif
