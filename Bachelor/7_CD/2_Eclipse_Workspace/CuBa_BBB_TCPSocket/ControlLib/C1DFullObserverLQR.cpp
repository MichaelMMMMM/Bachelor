/**
 * @file	C1DFullObserverLQR.cpp
 * @author	Michael Meindl
 * @date	01.05.2017
 * @brief	Method definitions for C1DFullObserverLQR.
 */
#include "C1DFullObserverLQR.h"

C1DFullObserverLQR::C1DFullObserverLQR()
{
	mSignalFlow.TObserver<3U, 3U, 1U>::init("config/Edge_Afull.csv",
											"config/Edge_Bfull.csv",
											"config/Edge_Cfull.csv",
											"config/Edge_Lfull.csv");
	mSignalFlow.TLQR<3U, 1U>::init("config/Edge_Kd.csv");
}
const C1DFullObserverLQR::OutputType& C1DFullObserverLQR::calcOutput(const C1DFullObserverLQR::InputType& in)
{
	mSignalFlow.calcOutput(in);
	mOutput = mSignalFlow.TSaturation<1U>::getValue();
	return mOutput;
}
const C1DFullObserverLQR::OutputType& C1DFullObserverLQR::getValue() const
{
	return mOutput;
}
void C1DFullObserverLQR::updateConfig()
{
	mSignalFlow.TObserver<3U, 3U, 1U>::init("config/Edge_Afull.csv",
											"config/Edge_Bfull.csv",
											"config/Edge_Cfull.csv",
											"config/Edge_Lfull.csv");
	mSignalFlow.TLQR<3U, 1U>::init("config/Edge_Kd.csv");
}
TRVector<3U> C1DFullObserverLQR::getX()
{
	return mSignalFlow.TObserver<3U, 3U, 1U>::getValue();
}
void C1DFullObserverLQR::setObserverU(TRVector<1U> u)
{
	mSignalFlow.TObserver<3U, 3U, 1U>::setU(u);
}
void C1DFullObserverLQR::setObserverX0(TRVector<3U> x0)
{
	mSignalFlow.TObserver<3U, 3U, 1U>::setX(x0);
}
void C1DFullObserverLQR::setControllerActive(bool active)
{
	mSignalFlow.TSaturation<1U>::setMaximum(active ?  0.11F : 0.0F);
	mSignalFlow.TSaturation<1U>::setMinimum(active ? -0.11F : 0.0F);
}
