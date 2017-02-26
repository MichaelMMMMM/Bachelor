/**
 * @file	CMPUData.cpp
 * @author	Michael Meindl
 * @date	06.02.2017
 * @brief	Method definitions for CMPUData.
 */
#include "CMPUData.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

CMPUData::CMPUData() : mTime(0.0F),
					   mA_x(0), mA_y(0), mA_z(0),
					   mW_x(0), mW_y(0), mW_z(0)
{

}
void CMPUData::display()
{
	cout << setw(8) << " A_x: " << setw(8) << mA_x <<
			setw(8) << " A_y: " << setw(8) << mA_y <<
			setw(8) << " A_z: " << setw(8) << mA_z <<
			setw(8) << " W_x: " << setw(8) << mW_x <<
			setw(8) << " W_y: " << setw(8) << mW_y <<
			setw(8) << " W_z: " << setw(8) << mW_z << std::endl;
}
