/**
 * @author	Michael Meindl
 * @date	6.12.2016
 * @brief	Method definition for CBrake.
 */
#include "CBrake.h"
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

#define CLOSE_DUTY_CYCLE "1500000"		//7.3%
#define OPEN_DUTY_CYCLE "2100000"		//9.5%

CBrake::CBrake()
{
	string pwmPath = "/sys/class/pwm/pwmchip1/pwm0/";

	//Check wethehr the interface is active
	string period_file = pwmPath + "period";
	int ret = access(period_file.c_str(), F_OK);
	if(ret < 0)
	{
		ret = sysfsEcho("/sys/class/pwm/pwmchip1/export", "0");
		if(ret < 0)
		{
			cerr << "(CBrake::initPWM) sysfsEcho to export failed! ret: " << ret << endl;
		}
	}

	//Disable the pwm generator
	string enable_file = pwmPath + "enable";
	ret = sysfsEcho(enable_file.c_str(), "0");
	if(ret < 0)
	{
		cerr << "(CBrake::initPWM) sysfsEcho to " << enable_file << " failed! ret: " << ret << endl;
	}

	//Set polarity to normal
	string polarity_file = pwmPath + "polarity";
	ret = sysfsEcho(polarity_file.c_str(), "normal");
	if(ret < 0)
	{
		cerr << "(CBrake::initPWM) sysfsEcho to " << polarity_file << " failed! ret: " << ret << endl;
	}

	//Set frequency to 50Hz
	string frequency_file = pwmPath + "period";
	ret = sysfsEcho(frequency_file.c_str(), "20000000");
	if(ret < 0)
	{
		cerr << "(CBrake::initPWM) sysfsEcho to " << frequency_file << " failed! ret: " << ret << endl;
	}

	//Set Duty-Cycle to 0
	string dc_file = pwmPath + "duty_cycle";
	mServoPWMFd = open(dc_file.c_str(), O_WRONLY);
	if(mServoPWMFd < 0)
	{
		cerr << "(CBrake::initPWM) open " << dc_file << " failed! ret: " << ret << endl;
	}

	ret = write(mServoPWMFd, "0", strlen("0"));
	if( (ret < 0) || (ret != strlen("0")))
	{
		cerr << "(CBrake::initPWM) write to " << dc_file << " failed! ret: " << ret << endl;
	}

	//Enable the pwm generator
	ret = sysfsEcho(enable_file.c_str(), "1");
	if(ret < 0)
	{
		cerr << "(CBrake::initPWM) sysfsEcho to " << enable_file << " failed! ret: " << ret << endl;
	}
}
CBrake::~CBrake()
{
	int ret = close(mServoPWMFd);
	if(ret < 0)
	{
		cerr << "(CBrake::~CBrake) close() failed! ret: " << ret << endl;
	}
}
bool CBrake::openBrake()
{
	int ret = write(mServoPWMFd, OPEN_DUTY_CYCLE, strlen(OPEN_DUTY_CYCLE));
	if(ret != static_cast<int>(strlen(OPEN_DUTY_CYCLE)))
	{
		cerr << "(CBrake::openBrake) write() to Servo-PWM-FD failed! ret : " << ret << endl;
		return false;
	}
	return true;
}
bool CBrake::closeBrake()
{
	int ret = write(mServoPWMFd, CLOSE_DUTY_CYCLE, strlen(CLOSE_DUTY_CYCLE));
	if(ret != static_cast<int>(strlen(CLOSE_DUTY_CYCLE)))
	{
		cerr << "(CBrake::closeBrake) write() to Servo-PWM-FD failed! ret: " << ret << endl;
		return false;
	}
	return true;
}
int CBrake::sysfsEcho(const char* file, const char* string)
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
