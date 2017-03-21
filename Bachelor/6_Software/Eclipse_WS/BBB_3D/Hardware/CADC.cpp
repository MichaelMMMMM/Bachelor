/**
 * @author	Michael Meindl
 * @date	6.12.2016
 * @brief	Method definitions for CADC.
 */
#include "CADC.h"
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

CADC::CADC() : mADCFd(-1), mFirstRun(true), mRecentData{0U}
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
	//Select analog in channel 1
	channel_file = adcPath + "scan_elements/in_voltage1_en";
	ret = sysfsEcho(channel_file.c_str(), "1");
	if(ret < 0)
	{
		cerr << "(CADC::CADC) sysfsEcho to "  << channel_file << " failed! ret: " << ret << endl;
		exit(-1);
	}
	//Select analog in channel 2
	channel_file = adcPath + "scan_elements/in_voltage2_en";
	ret = sysfsEcho(channel_file.c_str(), "1");
	if(ret < 0)
	{
		cerr << "(CADC::CADC) sysfsEcho to " << channel_file << " failed! ret: " << ret << endl;
		exit(-1);
	}
	//Select analog in channel 3
	channel_file = adcPath + "scan_elements/in_voltage3_en";
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
	mADCFd = open("/dev/iio:device0", O_RDONLY);
	if(mADCFd < 0)
	{
		cerr << "(CADC::CADC) open() /dev/iio:device0 failed! ret: " << mADCFd << ", errno: " << errno << endl;
		exit(-1);
	}
}
CADC::~CADC()
{
	int ret = close(mADCFd);
	if(ret < 0)
	{
		cerr << "(CADC::~CADC) close() mADCFd failed! ret: " << ret << endl;
	}
}
bool CADC::fetchValue(CADCData& data)
{
	UInt16 values[4] = { 0U };
	int ret = read(mADCFd, &values, 4*sizeof(UInt16));
	if((ret < 0) || (ret < static_cast<int>(4*sizeof(UInt16))))
	{
		cerr << "(CADC::fetchValues) read() mADCFd failed! ret: " << ret << endl;
		return false;
	}

	data.mADC1Value = values[0];
	data.mADC2Value = values[1];
	data.mADC3Value = values[2];
	return true;
}
void CADC::reset()
{
	mFirstRun = true;
}
int CADC::sysfsEcho(const char* file, const char* string)
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
