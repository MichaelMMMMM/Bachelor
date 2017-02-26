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

class CLQR
{
public:
	using InputType = CStateData;
	using OutputType = CTorqueData;
public:
	const CTorqueData& calcOutput(const CStateData& input);
	const CTorqueData& getValue();
public:
	CLQR() = default;
	CLQR(const CLQR&) = delete;
	CLQR& operator=(const CLQR&) = delete;
	~CLQR() = default;
private:
	CTorqueData mOutput;

	static constexpr Float32 sF_TM1[] = { -0.02042,0.20906,-0.18864,-0.25793,0.13133,0.078654,-0.00030575,-0.00024813,-0.00024176} ;
	static constexpr Float32 sF_TM2[] = { -0.20933,0.019967,0.18936,0.13125,-0.2602,0.077989,-0.00026467,-0.00032244,-0.00025847 };
	static constexpr Float32 sF_TM3[] = { 0.14031,-0.14089,0.0005785,0.078698,0.077933,-0.096015,0.00034973,0.00034954,0.00030658 };
//	static constexpr Float32 sF_TM1[] = { 0.2960F, 1.3239F, -1.6198F, -1.9050F, 1.3401F, 0.3554F, -0.0164F, 0.0071F, 0.0051F };
//	static constexpr Float32 sF_TM2[] = { -0.5690F, 0.4589F, 0.1101F, -0.2037F, -0.3368F, 0.3313F, -0.0118F, 0.0009F, 0.0065F };
//	static constexpr Float32 sF_TM3[] = { 0.4861F, -0.0302F, -0.4559F, -0.3257F, 0.5911F, -0.1604F, -0.0060F, 0.0077F, 0.0035F };
//	static constexpr Float32 sF_TM1[] = { 0.011858,0.33513,-0.34699,-0.43267,0.25546,0.1106,-0.0017011,0.00028842,0.00025907};
//	static constexpr Float32 sF_TM2[] = { -0.26236,-0.0024053,0.26476,0.1899,-0.33244,0.086043,-9.3551e-05,-0.00069157,-0.00013653 };
//	static constexpr Float32 sF_TM3[] = {0.15702,-0.18508,0.028058,0.12034,0.067188,-0.11521,0.00082799,0.00047858,0.00018741};
};

#endif
