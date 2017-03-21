/**
 * @file	CSensorSystem.cpp
 * @author	Michael Meindl
 * @date	07.02.2017
 * @brief	Method definitions for CSensorSystem.
 */
#include "CSensorSystem.h"
#include <sys/time.h>
#include <iostream>

CSensorSystem::CSensorSystem() : mSwitch("47", "46", "27", "65")
{
	mSwitch.selectX1();
	mMPU.init();
	mSwitch.selectX2();
	mMPU.init();
	mSwitch.selectX3();
	mMPU.init();
	mSwitch.selectX4();
	mMPU.init();
	mSwitch.selectX5();
	mMPU.init();
	mSwitch.selectX6();
	mMPU.init();
}
bool CSensorSystem::readSensorData(CSensorData& data)
{

	struct timeval timebegin, timeend, oa_tb, oa_te;
	long seconds, useconds;
	long adc_seconds, adc_useconds;
	long oa_seconds, oa_useconds;

	gettimeofday(&oa_tb, (struct timezone*)0);
	bool ret = mADC.fetchValue(data.mADCData);
	gettimeofday(&timeend, (struct timezone*)0);
	adc_seconds = timeend.tv_sec - oa_tb.tv_sec;
	adc_useconds = timeend.tv_usec - oa_tb.tv_usec;
	if(adc_useconds < 0)
	{
		adc_useconds += 1000000;
		adc_seconds--;
	}

	gettimeofday(&timebegin, (struct timezone*)0);
	mSwitch.selectX1();
	ret = mMPU.readSensorData(data.mSensor1Data) && ret;
	mSwitch.selectX2();
	ret = mMPU.readSensorData(data.mSensor2Data) && ret;
	mSwitch.selectX3();
	ret = mMPU.readSensorData(data.mSensor3Data) && ret;
	mSwitch.selectX4();
	ret = mMPU.readSensorData(data.mSensor4Data) && ret;
	mSwitch.selectX5();
	ret = mMPU.readSensorData(data.mSensor5Data) && ret;
	mSwitch.selectX6();
	ret = mMPU.readSensorData(data.mSensor6Data) && ret;
	gettimeofday(&oa_te, (struct timezone*)0);
	seconds = oa_te.tv_sec - timebegin.tv_sec;
	useconds = oa_te.tv_usec - timebegin.tv_usec;
	if(useconds < 0)
	{
		useconds += 1000000;
		seconds--;
	}

	oa_seconds = oa_te.tv_sec - oa_tb.tv_sec;
	oa_useconds = oa_te.tv_usec - oa_tb.tv_usec;
	if(oa_useconds < 0)
	{
		oa_useconds += 1000000;
		oa_seconds--;
	}

	std::cerr << " ADC-useconds: " << adc_useconds;
	std::cerr << " MPU-useconds: " << useconds;
	std::cerr << " OA-useconds: " << oa_useconds << std::endl;

	return ret;
}
