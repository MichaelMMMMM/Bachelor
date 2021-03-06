/**
 * @file	C1DControlSystem.h
 * @author	Michael Meindl
 * @date	19.04.2017
 * @brief	Class to handle the switching between the different control approaches for edge balancing.
 */
#ifndef C1DCONTROLSYSTEM_H
#define C1DCONTROLSYTSEM_H
#include "E1DControlSystem.h"
#include "C1DCompLQR.h"
#include "C1DPhiObsLQR.h"
#include "C1DFullObserverLQR.h"

class C1DControlSystem
{
public:
	using InputType		= TRVector<3U>;
	using OutputType	= TRVector<1U>;
public:
	const OutputType& calcOutput(const InputType& input);
	const OutputType& getValue() const;
	void setObserverX0();
	void setControlSystem(E1DControlSystem system);
	void activateControllers();
	void deactivateControllers();
	void updateConfig();
	TRVector<4U> getCompLQRData();
	TRVector<4U> getPhiObsLQRData();
	TRVector<4U> getFullObsLQRData();
public:
	C1DControlSystem();
	C1DControlSystem(const C1DControlSystem&) = delete;
	C1DControlSystem& operator=(const C1DControlSystem&) = delete;
	~C1DControlSystem() = default;
private:
	OutputType mOutput[3];

	E1DControlSystem mActiveSystem;

	C1DCompLQR   	   mCompLQR;
	C1DPhiObsLQR 	   mPhiObsLQR;
	C1DFullObserverLQR mFullObsLQR;
};

#endif
