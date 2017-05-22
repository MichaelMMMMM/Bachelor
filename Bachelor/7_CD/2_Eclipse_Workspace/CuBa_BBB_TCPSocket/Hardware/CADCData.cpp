/**
 * @file	CADCData.cpp
 * @author	Michael Meindl
 * @date	08.02.2017
 * @brief	Method defintions for CADCData.
 */
#include "CADCData.h"
#include <iostream>

CADCData::CADCData() : mTime(0.0F),
					   mADC1Value(0U),
					   mADC2Value(0U),
					   mADC3Value(0U),
					   mPadding(0U)
{

}
void CADCData::display()
{
	std::cout << "ADC1: "  << mADC1Value <<
				 " ADC2: " << mADC2Value <<
				 " ADC3: " << mADC3Value << std::endl;
}
