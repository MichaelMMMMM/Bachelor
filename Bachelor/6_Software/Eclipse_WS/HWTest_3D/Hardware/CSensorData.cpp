/**
 * @file	CSensorData.cpp
 * @author	Michael Meindl
 * @date	07.02.2017
 * @brief	Method definitions for CSensorData.
 */
#include "CSensorData.h"
#include <iostream>
#include <iomanip>
using namespace std;

CSensorData::CSensorData()
{

}
void CSensorData::display()
{
	cout << setw(18) << "Sensor 1 Data: ";
	mSensor1Data.display();

	cout << setw(18) << "Sensor 2 Data: ";
	mSensor2Data.display();

	cout << setw(18) << "Sensor 3 Data: ";
	mSensor3Data.display();

	cout << setw(18) << "Sensor 4 Data: ";
	mSensor4Data.display();

	cout << setw(18) << "Sensor 5 Data: ";
	mSensor5Data.display();

	cout << setw(18) << "Sensor 6 Data: ";
	mSensor6Data.display();

	cout << setw(18) << "ADC Data: ";
	mADCData.display();
}
