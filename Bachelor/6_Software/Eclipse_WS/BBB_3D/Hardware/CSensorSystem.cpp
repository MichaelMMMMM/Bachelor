/**
 * @file	CSensorSystem.cpp
 * @author	Michael Meindl
 * @date	07.02.2017
 * @brief	Method definitions for CSensorSystem.
 */
#include "CSensorSystem.h"

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
	bool ret = mADC.fetchValue(data.mADCData);

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

	return ret;
}
