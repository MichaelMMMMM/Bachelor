/**
 * @file	CSensorData.cpp
 * @author	Michael Meindl
 * @date	07.02.2017
 * @brief	Method definitions for CSensorData.
 */
#include "CSensorData.h"
#include <iostream>
using namespace std;

CSensorData::CSensorData()
{

}
void CSensorData::display()
{
	cout << "Sensor 1 Data:   ";
	mSensor1Data.display();

	cout << "Sensor 2 Data:   ";
	mSensor2Data.display();

	cout << "Sensor 3 Data:   ";
	mSensor3Data.display();

	cout << "Sensor 4 Data:   ";
	mSensor4Data.display();

	cout << "Sensor 5 Data:   ";
	mSensor5Data.display();

	cout << "Sensor 6 Data:   ";
	mSensor6Data.display();

	cout << "ADC Data:        ";
	mADCData.display();
}
CSensorFloatData::CSensorFloatData() : mST1_A{0.0F},
									   mST2_A{0.0F},
									   mST3_A{0.0F},
									   mST4_A{0.0F},
									   mS1_W{0.0F},
									   mS2_W{0.0F},
									   mS3_W{0.0F},
									   mS4_W{0.0F},
									   mS5_W{0.0F},
									   mS6_W{0.0F},
									   mADC{0.0F}
{

}
