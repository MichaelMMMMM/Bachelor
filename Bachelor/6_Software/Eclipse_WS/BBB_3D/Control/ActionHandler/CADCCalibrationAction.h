/**
 * @file	CADCCalibrationAction.h
 * @author	Michael Meindl
 * @date	08.02.2017
 * @brief	Action handler for the ADC-Calibration-Expirement.
 */
#ifndef CADCCALIBRATIONACTION_H
#define CADCCALIBRATIONACTION_H
#include "CControlActionBase.h"
#include "CTorqueData.h"

class CADCCalibrationAction : public CControlActionBase
{
public:
	void sampleADCCalibration();
	void setTorques(CTorqueData& data);
	void entryADCCalibration();
	void exitADCCalibration();
public:
	CADCCalibrationAction();
	CADCCalibrationAction(const CADCCalibrationAction&) = delete;
	CADCCalibrationAction& operator=(const CADCCalibrationAction&) = delete;
	~CADCCalibrationAction() = default;
private:
	Float32 mTime;
};

#endif
