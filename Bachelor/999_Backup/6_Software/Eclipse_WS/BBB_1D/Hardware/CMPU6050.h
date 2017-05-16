
/**
 * @author	Michael Meindl
 * @date	6.12.2016
 * @brief	Hardware abstraction of the MPU6050 drivers.
 */
#ifndef CMPU6050_H
#define CMPU6050_H
#include "SMPU6050Data.h"

class CMPU6050
{
public:
	bool fetchValues(SMPU6050Data& data);
public:
	CMPU6050(UInt8 deviceNr);
private:
	int echo(const char* file, const char* string);
	int read_int32(int fd, Int32& value);
private:
	int mAccelXFd;
	int mAccelYFd;
	int mAccelZFd;
	int mAnglVelXFd;
	int mAnglVelYFd;
	int mAnglVelZFd;
};

#endif
