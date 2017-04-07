/**
 * @file	CSensorCalibration.h
 * @author	Michael Meindl
 * @date	5.4.2017
 * @brief	Definition of the Substate class for the Sensor-Calibration.
 */
#ifndef CSENSORCALIBRATION_H
#define CSENSORCALIBRATION_H
#include "TSubState.h"
#include "CSensorCalibrationAction.h"

using CSensorCalibration = TSubState<EEvent::RUN_SENSOR_CALIBRATION, CSensorCalibrationAction>;

#endif
