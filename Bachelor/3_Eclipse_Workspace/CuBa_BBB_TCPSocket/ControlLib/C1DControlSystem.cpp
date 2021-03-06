/**
 * @file	C1DControlSystem.cpp
 * @author	Michael Meindl
 * @date	19.04.2017
 * @brief	Method definitions for C1DControlSystem.
 */
#include "C1DControlSystem.h"

C1DControlSystem::C1DControlSystem() : mActiveSystem(E1DControlSystem::COMP_LQR)
{

}
void C1DControlSystem::updateConfig()
{
	mCompLQR.updateConfig();
	mPhiObsLQR.updateConfig();
	mFullObsLQR.updateConfig();
}
const C1DControlSystem::OutputType& C1DControlSystem::calcOutput(const C1DControlSystem::InputType& input)
{
	mCompLQR.calcOutput(input);
	mPhiObsLQR.calcOutput(input);
	mFullObsLQR.calcOutput(input);

	mOutput[0] = mCompLQR.getValue();
	mOutput[1] = mPhiObsLQR.getValue();
	mOutput[2] = mFullObsLQR.getValue();

	auto u = mOutput[static_cast<UInt32>(mActiveSystem)];
	mPhiObsLQR.setObserverU(u);
	mFullObsLQR.setObserverU(u);

	return mOutput[static_cast<UInt32>(mActiveSystem)];
}
const C1DControlSystem::OutputType& C1DControlSystem::getValue() const
{
	return mOutput[static_cast<UInt32>(mActiveSystem)];
}
void C1DControlSystem::setObserverX0()
{
	auto x0 = mCompLQR.getX();
	mPhiObsLQR.setObserverX0(x0);
	mFullObsLQR.setObserverX0(x0);
}
void C1DControlSystem::setControlSystem(E1DControlSystem system)
{
	mActiveSystem = system;
}
void C1DControlSystem::activateControllers()
{
	mCompLQR.setControllerActive(true);
	mPhiObsLQR.setControllerActive(true);
	mFullObsLQR.setControllerActive(true);
}
void C1DControlSystem::deactivateControllers()
{
	mCompLQR.setControllerActive(false);
	mPhiObsLQR.setControllerActive(false);
	mFullObsLQR.setControllerActive(false);
}
TRVector<4U> C1DControlSystem::getCompLQRData()
{
	TRVector<4U> ret;
	auto x = mCompLQR.getX();
	auto u = mCompLQR.getValue();
	ret[1][1] = x[1][1];
	ret[2][1] = x[2][1];
	ret[3][1] = x[3][1];
	ret[4][1] = u[1][1];
	return ret;
}
TRVector<4U> C1DControlSystem::getPhiObsLQRData()
{
	TRVector<4U> ret;
	auto x = mPhiObsLQR.getX();
	auto u = mPhiObsLQR.getValue();
	ret[1][1] = x[1][1];
	ret[2][1] = x[2][1];
	ret[3][1] = x[3][1];
	ret[4][1] = u[1][1];
	return ret;
}
TRVector<4U> C1DControlSystem::getFullObsLQRData()
{
	TRVector<4U> ret;
	auto x = mFullObsLQR.getX();
	auto u = mFullObsLQR.getValue();
	ret[1][1] = x[1][1];
	ret[2][1] = x[2][1];
	ret[3][1] = x[3][1];
	ret[4][1] = u[1][1];
	return ret;
}
