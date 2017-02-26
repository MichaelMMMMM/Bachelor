/**
 * @file	CADCData.cpp
 * @author	Michael Meindl
 * @date	08.02.2017
 * @brief	Method defintions for CADCData.
 */
#include "CADCData.h"
#include <iostream>
#include <iomanip>
using namespace std;

CADCData::CADCData() : mTime(0.0F),
					   mADC1Value(0U),
					   mADC2Value(0U),
					   mADC3Value(0U),
					   mPadding(0U)
{

}
void CADCData::display()
{
	std::cout << setw(8) << " ADC1: " << setw(8) << mADC1Value <<
			     setw(8) << " ADC2: " << setw(8) << mADC2Value <<
				 setw(8) << " ADC3: " << setw(8) << mADC3Value << std::endl;
}
