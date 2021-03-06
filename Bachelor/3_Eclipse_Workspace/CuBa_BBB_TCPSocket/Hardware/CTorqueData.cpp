/**
 * @file	CTorqueData.cpp
 * @author	Michael Meindl
 * @date	08.02.2017
 * @brief	Method definitions for CTorqueData.
 */
#include "CTorqueData.h"
#include <iostream>

CTorqueData::CTorqueData() : mTime(0.0F),
							 mTorque1(0.0F),
							 mTorque2(0.0F),
							 mTorque3(0.0F)
{

}
CTorqueData::CTorqueData(TRVector<3U> u) : mTime(0.0F),
										   mTorque1(u[1][1]),
										   mTorque2(u[2][1]),
										   mTorque3(u[3][1])
{

}
void CTorqueData::display()
{
	std::cout << "T_M1: " << mTorque1 <<
			    " T_M2: " << mTorque2 <<
				" T_M3: " << mTorque3 << std::endl;
}
