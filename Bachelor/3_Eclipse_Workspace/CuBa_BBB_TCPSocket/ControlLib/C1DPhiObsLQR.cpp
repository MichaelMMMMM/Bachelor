/**
 * @file	C1DPhiObsLQR.cpp
 * @author	Michael Meindl
 * @date	19.04.2017
 * @brief	Method definitions for C1DPhiObsLQR.h
 */
#include "C1DPhiObsLQR.h"

C1DPhiObsLQR::C1DPhiObsLQR()
{
	mSignalFlow.TLQR<3U, 1U>::init("config/Edge_Kd.csv");
	mSignalFlow.TObserver<3U, 2U, 1U>::init("config/Edge_Ad.csv",
											"config/Edge_Bd.csv",
											"config/Edge_Cd.csv",
											"config/Edge_Ld.csv");
	mSignalFlow.C1DCMat::init("config/Edge_Cd.csv");
}
void C1DPhiObsLQR::updateConfig()
{
	mSignalFlow.TLQR<3U, 1U>::init("config/Edge_Kd.csv");
	mSignalFlow.TObserver<3U, 2U, 1U>::init("config/Edge_Ad.csv",
											"config/Edge_Bd.csv",
											"config/Edge_Cd.csv",
											"config/Edge_Ld.csv");
	mSignalFlow.C1DCMat::init("config/Edge_Cd.csv");
}
const C1DPhiObsLQR::OutputType& C1DPhiObsLQR::calcOutput(const C1DPhiObsLQR::InputType& in)
{
	mSignalFlow.calcOutput(in);
	mOutput = mSignalFlow.TSaturation<1U>::getValue();
	return mOutput;
}
const C1DPhiObsLQR::OutputType& C1DPhiObsLQR::getValue() const
{
	return mOutput;
}
void C1DPhiObsLQR::setObserverX0(const TRVector<3U>& x0)
{
	mSignalFlow.TObserver<3U, 2U, 1U>::setX(x0);
}
void C1DPhiObsLQR::setObserverU(const TRVector<1U>& u)
{
	mSignalFlow.TObserver<3U, 2U, 1U>::setU(u);
}
void C1DPhiObsLQR::setControllerActive(bool active)
{
	mSignalFlow.TSaturation<1U>::setMaximum(active ?  0.11F : 0.0F);
	mSignalFlow.TSaturation<1U>::setMinimum(active ? -0.11F : 0.0F);
}
TRVector<3U> C1DPhiObsLQR::getX()
{
	return mSignalFlow.TObserver<3U, 2U, 1U>::getValue();
}
