/**
 * @file	CLQR.h
 * @author	Michael Meindl
 * @date	16.02.2017
 * @brief	Class to calculate the LQR-Controller.
 */
#ifndef CLQR_H
#define CLQR_H
#include "CStateData.h"
#include "CTorqueData.h"
#include "TMatrix.h"

class CLQR
{
public:
	using InputType  = TRVector<9U>;
	using OutputType = TRVector<3U>;
public:
	const OutputType& calcOutput(const InputType& input);
	const OutputType& getValue();
public:
	CLQR() = default;
	CLQR(const CLQR&) = delete;
	CLQR& operator=(const CLQR&) = delete;
	~CLQR() = default;
private:
	OutputType mOutput;

	static constexpr Float32 sF_TM1[] = { 0.061636198237490, 1.268673454163169F, -1.330309652400662F,
										 -1.038461672469759F, 0.142786616339576F, -0.089449973363467F,
										 -0.001712517289793F, -0.000009027223007F, -0.000027765354051F };
	static constexpr Float32 sF_TM2[] = { -1.251558081385752F, -0.043030339808257F, 1.294588421194026F,
										  0.078296125807485F, -0.982376762765626F, -0.090296791946150F,
										  -0.000886985856257F, -0.000997181248815F, -0.000104462418571F };
	static constexpr Float32 sF_TM3[] = { 0.740409795511710F,  -0.726411416278305F  -0.013998379233414F,
										  -0.152502805407330F,  -0.053774310039450F,  -0.516957065956842F,
										  0.000291741057800F,   0.001550779892705F,   0.001066379995972F};
};

#endif
