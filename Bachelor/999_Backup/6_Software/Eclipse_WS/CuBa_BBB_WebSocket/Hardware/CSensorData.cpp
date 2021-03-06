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
