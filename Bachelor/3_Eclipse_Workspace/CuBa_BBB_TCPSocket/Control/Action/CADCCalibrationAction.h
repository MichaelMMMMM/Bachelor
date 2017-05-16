/**
 * @file	CADCCalibrationAction.h
 * @author	Michael Meindl
 * @date	5.4.2017
 * @brief	Class definition for the ADC-Calibration-Actionhandler.
 */
#ifndef CADCCALIBRATIONACTION_H
#define CADCCALIBRATIONACTION_H
#include "CControlActionBase.h"

class CADCCalibrationAction : public CControlActionBase
{
public:
	void entryADCCalibration();
	void exitADCCalibration();
	void sampleADCCalibration();
public:
	CADCCalibrationAction();
	CADCCalibrationAction(const CADCCalibrationAction&) = delete;
	CADCCalibrationAction& operator=(const CADCCalibrationAction&) = delete;
	~CADCCalibrationAction() = default;
private:
	Float32 mTime;
};


#endif
