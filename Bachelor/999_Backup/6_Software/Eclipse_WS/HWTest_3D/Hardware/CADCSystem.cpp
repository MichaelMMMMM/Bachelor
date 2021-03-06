/**
 * @file	CADCSystem.cpp
 * @author	Michael Meindl
 * @date	19.02.2017
 * @brief	Method definitions for CADCSystem.
 */
#include "CADCSystem.h"
#include <iostream>   // cout, cerr
#include <string>     // string, to_string
#include <cstdio>     // fprintf, perror
#include <cstring>    // strlen
#include <cerrno>     // errno
#include <unistd.h>   // open, close, read, write, access, F_OK
#include <fcntl.h>    // O_RDONLY
#include <cstdlib>
#include <string.h>
using namespace std;

CADCSystem::CADCSystem() : mSwitch("49", "48", "7", "26"), mADCFD(-1)
{
	string adcPath = "/sys/bus/iio/devices/iio:device0/";

	//Disable the buffered readout for configuration
	string enable_file = adcPath + "buffer/enable";
	int ret = sysfsEcho(enable_file.c_str(), "0");
	if(ret < 0)
	{
		cerr << "(CADC::CADC) sysfsEcho to " << enable_file << " failed! ret: " << ret << endl;
		exit(-1);
	}

	//Select analog in channel 0
	string channel_file = adcPath + "scan_elements/in_voltage0_en";
	ret = sysfsEcho(channel_file.c_str(), "1");
	if(ret < 0)
	{
		cerr << "(CADC::CADC) sysfsEcho to " << channel_file << " failed! ret: " << ret << endl;
		exit(-1);
	}

	//Enable the buffered readout
	ret = sysfsEcho(enable_file.c_str(), "1");
	if(ret < 0)
	{
		cerr << "(CADC::CADC) sysfsEcho to " << enable_file << " failed! ret: " << ret << endl;
		exit(-1);
	}

	//Open the buffer to read the values
	mADCFD = open("/dev/iio:device0", O_RDONLY);
	if(mADCFD < 0)
	{
		cerr << "(CADC::CADC) open() /dev/iio:device0 failed! ret: " << mADCFD << ", errno: " << errno << endl;
		exit(-1);
	}
}
bool CADCSystem::fetchValues(CADCData& data)
{

	mSwitch.selectX1();
	//usleep(10000);
	int ret = read(mADCFD, &data.mADC1Value, sizeof(UInt16));
	if((ret < 0) || (ret < static_cast<int>(sizeof(UInt16))))
	{
		cerr << "(CADC::fetchValues) read() mADCFD failed! ret: " << ret << endl;
		return false;
	}
	mSwitch.selectX2();
	//usleep(10000);
	ret = read(mADCFD, &data.mADC2Value, sizeof(UInt16));
	if((ret < 0) || (ret < static_cast<int>(sizeof(UInt16))))
	{
		cerr << "(CADC::fetchValues) read() mADCFD failed! ret: " << ret << endl;
		return false;
	}
	mSwitch.selectX3();
	//usleep(10000);
	ret = read(mADCFD, &data.mADC3Value, sizeof(UInt16));
	if((ret < 0) || (ret < static_cast<int>(sizeof(UInt16))))
	{
		cerr << "(CADC::fetchValues) read() mADCFD failed! ret: " << ret << endl;
		return false;
	}
	return true;
}
int CADCSystem::sysfsEcho(const char* file, const char* string)
{
	// Control function parameters
	if (file == 0 || string == 0) {
		fprintf(stderr, "Invalid parameters.\n");
		return -1;
	}

	// Open the sysfs-entry
	int fd;
	fd = open(file, O_WRONLY);
	if (fd < 0) {
		perror("open");
		return -2;
	}

	// Write into the sysfs entry
	int ret;
	ret = write(fd, string, strlen(string));
	if (ret < 0)
	{
		perror("write");
		std::cout << "Errno: " << errno <<", string: " << string
				  << ", strlen: " << strlen(string) << std::endl;
		return -3;
	}
	else if (ret < (int)strlen(string))
	{
		return -4;
	}


	// Close the sysfs-entry
	close(fd);

	return 0;
}
