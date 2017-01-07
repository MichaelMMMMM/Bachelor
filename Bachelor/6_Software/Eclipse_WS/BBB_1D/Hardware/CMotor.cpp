/**
 * @author	Michael Meindl
 * @date	6.12.2016
 * @brief	Method definitions for CMotor.
 */
#include "CMotor.h"
#include <iostream>   // cout, cerr
#include <string>     // string, to_string
#include <cstdio>     // fprintf, perror
#include <cstring>    // strlen
#include <cerrno>     // errno
#include <unistd.h>   // open, close, read, write, access, F_OK
#include <fcntl.h>    // O_RDONLY
#include <cstdlib>
#include <string.h>
#include <sstream>

using namespace std;

CMotor::CMotor() : mDirectionPinFd(-1),
				   mEnablePinFd(-1),
				   mTorquePWMFd(-1)
{
	//Initialize the direction and enable pins
	mEnablePinFd 	= this->initGPIOPin(66);
	if(mEnablePinFd < 0)
	{
		cerr << "(CMotor::CMotor) Failed to initialize enable pin! ret: " << mEnablePinFd << endl;
		exit(-1);
	}
	mDirectionPinFd = this->initGPIOPin(67);
	if(mDirectionPinFd < 0)
	{
		cerr << "(CMotor::CMotor) Failed to initialize direction pin! ret: " << mDirectionPinFd << endl;
		exit(-1);
	}
	//Configure the pwm output for the torque signal
	mTorquePWMFd = this->initPWM();
	if(mTorquePWMFd < 0)
	{
		cerr << "(CMotor::CMotor) Failed to initialize torque pwm! ret: " << mTorquePWMFd << endl;
		exit(-1);
	}
}
CMotor::~CMotor()
{
	int ret = -1;
	ret = close(mDirectionPinFd);
	if(ret < 0)
	{
		cerr << "(CMotor::~CMotor) Failed to close Direction-Pin-FD" << endl;
	}

	ret = close(mEnablePinFd);
	if(ret < 0)
	{
		cerr << "(CMotor::~CMotor) Failed to close Enable-Pin-FD" << endl;
	}

	ret = close(mTorquePWMFd);
	if(ret < 0)
	{
		cerr << "(CMotor::~CMotor) Failed to close Torque-PWM-FD" << endl;
	}
}
bool CMotor::enableMotor()
{
	//Set the troque to zero
	this->setTorque(0.0F);

	int ret = write(mEnablePinFd, "1", strlen("1"));
	if( ret != strlen("1"))
	{
		cerr << "(CMotor::enableMotor) Failed to write() to Enable-Pin-FD! ret: " << ret << endl;
		return false;
	}
	return true;
}
bool CMotor::disableMotor()
{
	int ret = write(mEnablePinFd, "0", strlen("0"));
	if(ret != strlen("0"))
	{
		cerr << "(CMotor::disableMotor) Failed to write() to Enable-Pin-FD! ret: " << ret << endl;
		return false;
	}
	return true;
}
bool CMotor::setTorque(float torque)
{
	const char* directionPinValue = torque >= 0.0F ? "0" : "1";

	int ret = write(mDirectionPinFd, directionPinValue, strlen(directionPinValue));
	if(ret != static_cast<int>(strlen(directionPinValue)))
	{
		cerr << "(CMotor::setTorque) write() to Direction-Pin-FD failed! ret: " << ret << endl;
		return false;
	}

	//Calculate the magnitude of the torque and limit it to the maximum value
	torque = torque > 0.0F ? torque : -1.0F*torque;
	torque = torque > 0.07F ? 0.07F : torque;

	//Calculate the required duty-cycle
	float period = 20000000.0F;
	int dc = static_cast<int>(period*(torque*11.258F+0.1F));
	ostringstream oss;
	oss << dc;
	string dcStr = oss.str();
	const char* dcCStr = dcStr.c_str();

	ret = write(mTorquePWMFd, dcCStr, strlen(dcCStr));
	if(ret != static_cast<int>(strlen(dcCStr)))
	{
		cerr << "(CMotor::setTorque) write() to Torque-PWM-FD failed! ret: " << ret << endl;
		return false;
	}
	return true;
}
int CMotor::initPWM()
{
	string pwmPath = "/sys/class/pwm/pwmchip1/pwm1/";

	//Check wethehr the interface is active
	string period_file = pwmPath + "period";
	int ret = access(period_file.c_str(), F_OK);
	if(ret < 0)
	{
		ret = sysfsEcho("/sys/class/pwm/pwmchip1/export", "1");
		if(ret < 0)
		{
			cerr << "(CMotor::initPWM) sysfsEcho to export failed! ret: " << ret << endl;
			return -1;
		}
	}

	//Disable the pwm generator
	string enable_file = pwmPath + "enable";
	ret = sysfsEcho(enable_file.c_str(), "0");
	if(ret < 0)
	{
		cerr << "(CMotor::initPWM) sysfsEcho to " << enable_file << " failed! ret: " << ret << endl;
		return -2;
	}

	//Set polarity to normal
	string polarity_file = pwmPath + "polarity";
	ret = sysfsEcho(polarity_file.c_str(), "normal");
	if(ret < 0)
	{
		cerr << "(CMotor::initPWM) sysfsEcho to " << polarity_file << " failed! ret: " << ret << endl;
		return -3;
	}

	//Set frequency to 50Hz
	string frequency_file = pwmPath + "period";
	ret = sysfsEcho(frequency_file.c_str(), "20000000");
	if(ret < 0)
	{
		cerr << "(CMotor::initPWM) sysfsEcho to " << frequency_file << " failed! ret: " << ret << endl;
		return -4;
	}

	//Set Duty-Cycle to 0
	string dc_file = pwmPath + "duty_cycle";
	int dutyCycleFd = open(dc_file.c_str(), O_WRONLY);
	if(dutyCycleFd < 0)
	{
		cerr << "(CMotor::initPWM) open " << dc_file << " failed! ret: " << ret << endl;
		return -5;
	}

	ret = write(dutyCycleFd, "0", strlen("0"));
	if( (ret < 0) || (ret != strlen("0")))
	{
		cerr << "(CMotor::initPWM) write to " << dc_file << " failed! ret: " << ret << endl;
		return -6;
	}

	//Enable the pwm generator
	ret = sysfsEcho(enable_file.c_str(), "1");
	if(ret < 0)
	{
		cerr << "(CMotor::initPWM) sysfsEcho to " << enable_file << " failed! ret: " << ret << endl;
		return -7;
	}
	return dutyCycleFd;
}
int CMotor::initGPIOPin(UInt8 gpioNr)
{
	int ret = -1;

	ostringstream oss;
	oss << static_cast<UInt32>(gpioNr);
	string gpioStr = oss.str();

	string gpioPath = "/sys/class/gpio/gpio" + gpioStr;

	string valueFile = gpioPath + "/value";

	//Check whether the GPIO interface is up and running
	ret = access(valueFile.c_str(), F_OK);
	if(ret < 0)
	{
		//Try to activate the interface
		ret = sysfsEcho("/sys/class/gpio/export", gpioStr.c_str());
		if(ret < 0)
		{
			cerr << "(CMotor::initGPIOPin) sysfsEcho to " << valueFile << " failed! ret: " << ret << endl;
			return -1;
		}
	}

	string active_low_file = gpioPath + "/active_low";
	string direction_file  = gpioPath + "/direction";

	//Configure the pin as active high
	ret = sysfsEcho(active_low_file.c_str(), "0");
	if(ret < 0)
	{
		cerr << "(CMotor::initGPIOPin) sysfsEcho to " << active_low_file << " failed! ret: " << ret << endl;
		return -2;
	}

	//Configure the pin as output
	ret = sysfsEcho(direction_file.c_str(), "out");
	if(ret < 0)
	{
		cerr << "(CMotor::initGPIOPin) sysfsEcho to " << direction_file << " failed! ret: " << ret << endl;
		return -3;
	}

	//Set the output to low
	int pinFD = open(valueFile.c_str(), O_WRONLY);
	if(pinFD < 0)
	{
		cerr << "(CMotor::initGPIOPin) open() " << valueFile << " failed! ret: " << ret << endl;
		return -4;
	}

	ret = write(pinFD, "0", strlen("0"));
	if(ret < 0)
	{
		cerr << "(CMotor::initGPIOPin) write() to " << valueFile << " failed! ret: " << ret << endl;
		return -5;
	}

	return pinFD;
}
int CMotor::sysfsEcho(const char* file, const char* string)
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
