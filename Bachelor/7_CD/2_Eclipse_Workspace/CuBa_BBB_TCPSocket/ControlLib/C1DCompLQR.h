/**
 * @file	C1DCompLQR.h
 * @author	Michael Meindl
 * @date	19.04.2017
 * @brief	Subsystem to handle the signal flow of Complementary-Filter->LQR->Saturation.
 */
#ifndef C1DCOMPLQR_H
#define C1DCOMPLQR_H
#include "TLinHierarchy.h"
#include "TActionHolder.h"
#include "TLQR.h"
#include "C1DCompFilter.h"
#include "TSaturation.h"
#include "TMatrix.h"

class C1DCompLQR
{
public:
	using InputType		= TRVector<3U>;
	using OutputType	= TRVector<1U>;
public:
	const OutputType& calcOutput(const InputType& input);
	const OutputType& getValue() const;
	const TRVector<3U>& getX() const;
	void setControllerActive(bool active);
	void updateConfig();
public:
	C1DCompLQR();
	C1DCompLQR(const C1DCompLQR&) = delete;
	C1DCompLQR& operator=(const C1DCompLQR&) = delete;
	~C1DCompLQR() = default;
private:
	OutputType mOutput;

	using Controller = TLQR<3U, 1U>;
	using Saturation = TSaturation<1U>;
	using ActionList = TYPELIST_3(C1DCompFilter, Controller, Saturation );
	TLinHierarchy<ActionList, TActionHolder> mSignalFlow;
};

#endif
