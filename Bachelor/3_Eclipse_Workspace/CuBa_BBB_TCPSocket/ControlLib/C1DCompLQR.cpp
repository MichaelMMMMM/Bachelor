/**
 * @file	C1DCompLQR.h
 * @author	Michael Meindl
 * @date	19.04.2017
 * @brief	Method definitions for C1DCompLQR.
 */
#include "C1DCompLQR.h"

C1DCompLQR::C1DCompLQR()
{
	mSignalFlow.TLQR<3U, 1U>::init("config/Edge_Kd.csv");
	mSignalFlow.TSaturation<1U>::setMaximum(0.11F);
	mSignalFlow.TSaturation<1U>::setMinimum(-0.11F);
}
void C1DCompLQR::updateConfig()
{
	mSignalFlow.TLQR<3U, 1U>::init("config/Edge_Kd.csv");
}
const C1DCompLQR::OutputType& C1DCompLQR::calcOutput(const C1DCompLQR::InputType& input)
{
	mSignalFlow.calcOutput(input);
	mOutput = mSignalFlow.TSaturation<1U>::getValue();
	return mOutput;
}
const C1DCompLQR::OutputType& C1DCompLQR::getValue() const
{
	return mOutput;
}
const TRVector<3U>& C1DCompLQR::getX() const
{
	return mSignalFlow.C1DCompFilter::getValue();
}
void C1DCompLQR::setControllerActive(bool active)
{
	mSignalFlow.TSaturation<1U>::setMaximum(active ?  0.11F : 0.0F);
	mSignalFlow.TSaturation<1U>::setMinimum(active ? -0.11F : 0.0F);
}
