/**
 * @file	CMPUData.cpp
 * @author	Michael Meindl
 * @date	06.02.2017
 * @brief	Method definitions for CMPUData.
 */
#include "CMPUData.h"
#include <iostream>
#include <cstdlib>
using namespace std;

CMPUData::CMPUData() : mTime(0.0F),
                       mA_x(0), mA_y(0), mA_z(0),
					   mW_x(0), mW_y(0), mW_z(0)
{

}
void CMPUData::display()
{
	cout << " A_x: " << mA_x << " A_y: " << mA_y << " A_z: " << mA_z <<
			" W_x: " << mW_x << " W_y: " << mW_y << " W_z: " << mW_z << std::endl;
}
