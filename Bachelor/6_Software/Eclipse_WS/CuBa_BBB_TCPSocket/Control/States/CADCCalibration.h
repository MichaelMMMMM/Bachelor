/**
 * @file	CADCCalibration.h
 * @author	Michael Meindl
 * @date	5.4.2017
 * @brief	Defining the substate for the adc calibration.
 */
#ifndef CADCCALIBRATION_H
#define CADCCALIBRATION_H
#include "TSubState.h"
#include "CADCCalibrationAction.h"

using CADCCalibration = TSubState<EEvent::RUN_ADC_CALIBRATION, CADCCalibrationAction>;

#endif
