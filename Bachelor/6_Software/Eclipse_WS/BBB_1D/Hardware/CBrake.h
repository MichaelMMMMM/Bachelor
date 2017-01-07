/**
 * @author	Michael Meindl
 * @date	6.12.2016
 * @brief	Hardware abstraction for the servo brake.
 */
#ifndef CBRAKE_H
#define CBRAKE_H

class CBrake
{
public:
	bool openBrake();
	bool closeBrake();
public:
	CBrake();
	~CBrake();
private:
	int sysfsEcho(const char* file, const char* string);
private:
	int mServoPWMFd;
};

#endif
