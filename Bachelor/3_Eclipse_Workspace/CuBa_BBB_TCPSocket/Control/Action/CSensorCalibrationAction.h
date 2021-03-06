/**
 * @file	CSensorCalibrationAction.h
 * @author	Michael Meindl
 * @date	5.4.2017
 * @brief	Action handler for the Sensor Calibration
 */
#ifndef CSENSORCALIBRATIONACTION_H
#define CSENSORCALIBRATIONACTION_H
#include "CControlActionBase.h"

class CSensorCalibrationAction : public CControlActionBase
{
public:
	void entrySensorCalibration();
	void exitSensorCalibration();
	void sampleSensorCalibration();
public:
	CSensorCalibrationAction();
	CSensorCalibrationAction(const CSensorCalibrationAction&) = delete;
	CSensorCalibrationAction& operator=(const CSensorCalibrationAction&) = delete;
	~CSensorCalibrationAction() = default;
private:
	Float32 mTime;
};

#endif
