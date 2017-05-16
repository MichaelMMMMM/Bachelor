/**
 * @author	Michael  Meindl
 * @date	6.12.2016
 * @brief	Method definitions for the class CMPU6050.
 */
#include "CMPU6050.h"
#include <iostream>   // cerr
#include <cstdio>     // fprintf
#include <cstdlib>    // strtol
#include <string>     // string, to_string
#include <cstring>    // strlen
#include <unistd.h>   // write
#include <fcntl.h>    //

using namespace std;

CMPU6050::CMPU6050(UInt8 deviceNr) : mAccelXFd(-1),
								   mAccelYFd(-1),
								   mAccelZFd(-1),
								   mAnglVelXFd(-1),
								   mAnglVelYFd(-1),
								   mAnglVelZFd(-1)
{
	int ret = -1;

	//Path for the iio-device
	string iioPath = deviceNr == 1 ?
			"/sys/bus/iio/devices/iio:device1" :
			"/sys/bus/iio/devices/iio:device2";
	//Path for the sampling frequency file
	string sampling_frequency = iioPath + "/sampling_frequency";

	//Check whether the interface for the MPU is up and running
	ret = access(sampling_frequency.c_str(), F_OK);
	if(ret < 0)
	{
		cerr << "(CMPU6050::CMPU6050) access() " << sampling_frequency << " failed! ret: " << ret << endl;
	}

	//Filenames for the need attributes
	string enable			= iioPath + "/buffer/enable";
	string in_accel_x_en	= iioPath + "/scan_elements/in_accel_x_en";
	string in_accel_y_en	= iioPath + "/scan_elements/in_accel_y_en";
	string in_accel_z_en	= iioPath + "/scan_elements/in_accel_z_en";
	string in_anglvel_x_en 	= iioPath + "/scan_elements/in_anglvel_x_en";
	string in_anglvel_y_en  = iioPath + "/scan_elements/in_anglvel_y_en";
	string in_anglvel_z_en	= iioPath + "/scan_elements/in_anglvel_z_en";

	//Disable buffered readout for configuration
	ret = echo(enable.c_str(), "0");
	if(ret < 0)
	{
		cerr << "(CMPU6050::CMPU6050) Echo to " << enable << "failed! ret: " << ret << endl;
		exit(-1);
	}

	//Configure sampling frequency
	ret = echo(sampling_frequency.c_str(), "500");
	if(ret < 0)
	{
		cerr << "(CMPU6050::CMPU6050) Echo to " << sampling_frequency << " failed! ret: " << ret << endl;
		exit(-1);
	}

	//Acceleration values
	ret = echo(in_accel_x_en.c_str(), "1");		//Enable reading the X-Acceleration
	if(ret < 0)
	{
		cerr << "(CMPU6050::CMPU6050) Echo to " << in_accel_x_en << " failed! ret: " << ret << endl;
		exit(-1);
	}

	ret = echo(in_accel_y_en.c_str(), "1");		//Enable reading the Y-Acceleration
	if(ret < 0)
	{
		cerr << "(CMPU6050::CMPU6050) Echo to " << in_accel_y_en << " failed! ret: " << ret << endl;
		exit(-1);
	}

	ret = echo(in_accel_z_en.c_str(), "0");		//Enable reading the Z-Acceleration
	if(ret < 0)
	{
		cerr << "(CMPU6050::CMPU6050) Echo to " << in_accel_z_en << " failed! ret: " << ret << endl;
		exit(-1);
	}

	//Angular velocity values
	ret = echo(in_anglvel_x_en.c_str(), "0"); 	//Disable reading the X-Angular-Velocity
	if(ret < 0)
	{
		cerr << "(CMPU6050::CMPU6050) Echo to " << in_anglvel_x_en << " failed! ret: " << ret << endl;
		exit(-1);
	}

	ret = echo(in_anglvel_y_en.c_str(), "0"); 	//Disable reading the Y-Angular-Velocity
	if(ret < 0)
	{
		cerr << "(CMPU6050::CMPU6050) Echo to " << in_anglvel_y_en << " failed! ret: " << ret << endl;
		exit(-1);
	}

	ret = echo(in_anglvel_z_en.c_str(), "1"); 	//Enable reading the Z-Angular-Velocity
	if(ret < 0)
	{
		cerr << "(CMPU6050::CMPU6050) Echo to " << in_anglvel_z_en << " failed! ret: " << ret << endl;
		exit(-1);
	}


	ret = echo(enable.c_str(), "1");
	if(ret < 0)
	{
		cerr << "(CMPU6050::CMPU6050) Echo to " << enable << " failed! ret: " << ret << endl;
		exit(-1);
	}
	//Preopen the sysfs entries

	string in_accel_x_raw		= iioPath + "/in_accel_x_raw";
	string in_accel_y_raw		= iioPath + "/in_accel_y_raw";
	string in_anglvel_z_raw		= iioPath + "/in_anglvel_z_raw";

	ret = open(in_accel_x_raw.c_str(), O_RDONLY);
	if(ret < 0)
	{
		cerr << "(CMPU6050::CMPU6050) Open " << in_accel_x_raw << " failed! ret: " << ret << endl;
		exit(-1);
	}
	else
	{
		mAccelXFd = ret;
	}

	ret = open(in_accel_y_raw.c_str(), O_RDONLY);
	if(ret < 0)
	{
		cerr << "(CMPU6050::CMPU6050)  Open " << in_accel_y_raw << " failed! ret: " << ret << endl;
		exit(-1);
	}
	else
	{
		mAccelYFd = ret;
	}

	ret = open(in_anglvel_z_raw.c_str(), O_RDONLY);
	if(ret < 0)
	{
		cerr << "(CMPU6050::CMPU6050)  Open " << in_anglvel_z_raw << " failed! ret: " << ret << endl;
		exit(-1);
	}
	else
	{
		mAnglVelZFd = ret;
	}
}
bool CMPU6050::fetchValues(SMPU6050Data& data)
{
	int ret 	= -1;
	Int32 value	= 0;

	ret = read_int32(mAccelXFd, value);
	if(ret < 0)
	{
		cerr << "(CMPU6050::fetchValues) Read from AccelX failed! ret: " << ret << endl;
		return false;
	}
	else
	{
		data.mX__dd = static_cast<Int16>(value);
	}

	ret = read_int32(mAccelYFd, value);
	if(ret < 0)
	{
		cerr << "(CMPU6050::fetchValues) Read from the AccelY failed! ret: " << ret << endl;
		return false;
	}
	else
	{
		data.mY__dd = static_cast<Int16>(value);
	}

	ret = read_int32(mAnglVelZFd, value);
	if(ret < 0)
	{
		cerr << "(CMPU6050::fetchValues) Read from the AnglVelZ failed! ret: " << ret << endl;
		return false;
	}
	else
	{
		data.mPhi__d = static_cast<Int16>(value);
	}
	return true;
}
int CMPU6050::read_int32(int fd, Int32& value)
{
	// Control function parameters
	if (   fd  < 0) { cerr << "Parameter 'fd' < 0"     << endl; return -1; }

	int ret;

	// Reset file position to prevent errors
	ret = lseek(fd, 0, SEEK_SET);
	if (ret < 0)
	{
		perror("lseek");
		return -4;
	}

	// Try to read a value from the AIN channel
	char buf[32];
	ret = read(fd, buf, 32);
	if (ret < 0)
	{
		perror("read");
		return -3;
	}

	// Search for a carriage return
	char* end = 0;
	end = strchr(buf, 0xA);
	if (end == 0)
	{
		fprintf(stderr, "Invalid output!\n");
		return -4;
	}

	// Convert the string into an integer
	value = (int32_t) strtol(buf, &end, 10);

	return 0;
}
int CMPU6050::echo(const char* file, const char* string)
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
