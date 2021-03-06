#include "Global.h"
#include <iostream>
#include "CMotor.h"
#include "CMPU9250.h"
#include "CSwitch.h"
#include "CSensorSystem.h"
#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <sys/time.h>
#include "CADC.h"
#include "CHardware.h"
#include "CADCSystem.h"

static void motorTest();
static void mpuTest();
static void switchTest();
static void multipleMPUTest();
static void multipleSensorTimeTest();
static void sensorSystemTest();
static void adcTest();
static void torqueTest();
static void adcSystemTest();

int main()
{
	motorTest();
	//mpuTest();
	//switchTest();
	//multipleMPUTest();
	//multipleSensorTimeTest();
	//sensorSystemTest();
	//adcTest();
	//torqueTest();
	//adcSystemTest();
	return 0;
}
void adcSystemTest()
{
	CADCSystem adc;
	CADCData data;

	while(true)
	{
		adc.fetchValues(data);
		data.display();
		usleep(200000);
	}
}
void torqueTest()
{
	CHardware hw;

	hw.disableMotor();

	CTorqueData torque;
	torque.mTorque1 = 0.00F;
	torque.mTorque2 = 0.00F;
	torque.mTorque3 = 0.007F;

	hw.enableMotor();
	hw.setTorque(torque);
	hw.disableMotor();
}
void adcTest()
{
	CADC adc;
	CADCData data;

	struct timeval timebegin, timeend;
	long seconds, useconds;




	int i = 0;
	while(true)
	{
		usleep(10000);
		gettimeofday(&timebegin, (struct timezone*)0);
		if(adc.fetchValue(data))
		{
			//data.display();
		}
		else
		{
			std::cout << "ADC-Read failed!" << std::endl;
		}

		gettimeofday(&timeend, (struct timezone*)0);
		seconds = timeend.tv_sec - timebegin.tv_sec;
		useconds = timeend.tv_usec - timebegin.tv_usec;
		if(useconds < 0)
		{
			useconds += 1000000;
			seconds--;
		}
		//std::cerr << "seconds: " << seconds << " useconds: " << useconds << std::endl;
	}


}
void sensorSystemTest()
{
	CSensorSystem sensorSystem;
	CSensorData data;

	struct timeval timebegin, timeend;
	long seconds, useconds;

	gettimeofday(&timebegin, (struct timezone*)0);

	while(true)
	{
		gettimeofday(&timebegin, (struct timezone*)0);
		//std::cout << "-------------------------------------------------------------" <<
		//		     "-------------------------------------------------------------" << std::endl;
		sensorSystem.readSensorData(data);
		gettimeofday(&timeend, (struct timezone*)0);
		seconds = timeend.tv_sec - timebegin.tv_sec;
		useconds = timeend.tv_usec - timebegin.tv_usec;
		if(useconds < 0)
		{
			useconds += 1000000;
			seconds--;
		}
		//std::cerr << " Overall-useconds: " << useconds << std::endl;
		//data.display();
		usleep(10000);
	}
	gettimeofday(&timeend, (struct timezone*)0);
	seconds = timeend.tv_sec - timebegin.tv_sec;
	useconds = timeend.tv_usec - timebegin.tv_usec;
	if(useconds < 0)
	{
		useconds += 1000000;
		seconds--;
	}
	std::cerr << "seconds: " << seconds << " useconds: " << useconds << std::endl;
}
void multipleSensorTimeTest()
{
	CSwitch mySwitch("47", "46", "27", "65");

	CMPU9250 mpu;
	//Init
	mySwitch.selectX1();
	mpu.init();
	mySwitch.selectX2();
	mpu.init();
	mySwitch.selectX3();
	mpu.init();
	mySwitch.selectX4();
	mpu.init();
	mySwitch.selectX5();
	mpu.init();
	mySwitch.selectX6();
	mpu.init();
	CMPUData sensorData;

	struct timeval timebegin, timeend;
	long seconds, useconds;

	gettimeofday(&timebegin, (struct timezone*)0);

	for(int i = 0; i < 100000; i++)
	{
		gettimeofday(&timebegin, (struct timezone*)0);
		mySwitch.selectX1();
		if(false == mpu.readSensorData(sensorData))
		{
			std::cout << "MPU1 Error" << std::endl;
		}
		mySwitch.selectX2();
		if(false == mpu.readSensorData(sensorData))
		{
			std::cout << "MPU2 Error" << std::endl;
		}
		mySwitch.selectX3();
		if(false == mpu.readSensorData(sensorData))
		{
			std::cout << "MPU3 Error" << std::endl;
		}
		mySwitch.selectX4();
		if(false == mpu.readSensorData(sensorData))
		{
			std::cout << "MPU4 Error" << std::endl;
		}
		mySwitch.selectX5();
		if(false == mpu.readSensorData(sensorData))
		{
			std::cout << "MPU5 Error" << std::endl;
		}
		mySwitch.selectX6();
		if(false == mpu.readSensorData(sensorData))
		{
			std::cout << "MPU6 Error" << std::endl;
		}
		gettimeofday(&timeend, (struct timezone*)0);
		seconds = timeend.tv_sec - timebegin.tv_sec;
		useconds = timeend.tv_usec - timebegin.tv_usec;
		if(useconds < 0)
		{
			useconds += 1000000;
			seconds--;
		}
		std::cout <<" MPU1-useconds: " << useconds << std::endl;
	}

	gettimeofday(&timeend, (struct timezone*)0);
	seconds = timeend.tv_sec - timebegin.tv_sec;
	useconds = timeend.tv_usec - timebegin.tv_usec;
	if(useconds < 0)
	{
		useconds += 1000000;
		seconds--;
	}
	std::cout << "seconds: " << seconds << " useconds: " << useconds << std::endl;
}
void multipleMPUTest()
{
	CSwitch mySwitch("47", "46", "27", "65");

	CMPU9250 mpu;
	//Init
	mySwitch.selectX1();
	mpu.init();
	mySwitch.selectX2();
	mpu.init();
	mySwitch.selectX3();
	mpu.init();
	mySwitch.selectX4();
	mpu.init();
	mySwitch.selectX5();
	mpu.init();
	mySwitch.selectX6();
	mpu.init();
	CMPUData sensorData;



	while(true)
	{
		std::cout << "-----------------------------------------------------" << std::endl;
		mySwitch.selectX1();
		if(mpu.readSensorData(sensorData))
		{
			sensorData.display();
		}
		else
		{
			std::cout << "MPU1 Error" << std::endl;
		}
		mySwitch.selectX2();
		if(mpu.readSensorData(sensorData))
		{
			sensorData.display();
		}
		else
		{
			std::cout << "MPU2 Error" << std::endl;
		}
		mySwitch.selectX3();
		if(mpu.readSensorData(sensorData))
		{
			sensorData.display();
		}
		else
		{
			std::cout << "MPU3 Error" << std::endl;
		}
		mySwitch.selectX4();
		if(mpu.readSensorData(sensorData))
		{
			sensorData.display();
		}
		else
		{
			std::cout << "MPU4 Error" << std::endl;
		}
		mySwitch.selectX5();
		if(mpu.readSensorData(sensorData))
		{
			sensorData.display();
		}
		else
		{
			std::cout << "MPU5 Error" << std::endl;
		}
		mySwitch.selectX6();
		if(mpu.readSensorData(sensorData))
		{
			sensorData.display();
		}
		else
		{
			std::cout << "MPU6 Error" << std::endl;
		}
		usleep(500000);
	}
}
void switchTest()
{
	CSwitch mySwitch("47", "46", "27", "65");

	struct timeval timebegin, timeend;
	long seconds, useconds;

	gettimeofday(&timebegin, (struct timezone*)0);

	for(int i = 0; i < 1000000; i++)
	{
		mySwitch.selectX0();
		mySwitch.selectX1();
		mySwitch.selectX2();
		mySwitch.selectX3();
		mySwitch.selectX4();
		mySwitch.selectX5();
		//mySwitch.selectX6();
		//mySwitch.selectX7();
	}

	gettimeofday(&timeend, (struct timezone*)0);
	seconds = timeend.tv_sec - timebegin.tv_sec;
	useconds = timeend.tv_usec - timebegin.tv_usec;
	if(useconds < 0)
	{
		useconds += 1000000;
		seconds--;
	}
	std::cout << "seconds: " << seconds << " useconds: " << useconds << std::endl;
}
void mpuTest()
{
	CMPU9250 mpu;
	mpu.init();
	CMPUData sensorData;

	struct timeval timebegin, timeend;
	long seconds, useconds;

	gettimeofday(&timebegin, (struct timezone*)0);

	for(int i = 0; i < 10000; i++)
	{
		if(false == mpu.readSensorData(sensorData))
		{
			std::cout << "Read failed!" << std::endl;
		}
	}

	gettimeofday(&timeend, (struct timezone*)0);
	seconds = timeend.tv_sec - timebegin.tv_sec;
	useconds = timeend.tv_usec - timebegin.tv_usec;
	if(useconds < 0)
	{
		useconds += 1000000;
		seconds--;
	}
	std::cout << "seconds: " << seconds << " useconds: " << useconds << std::endl;

//	while(true)
//	{
//		usleep(100000);
//		if(mpu.readSensorData(sensorData))
//		{
//			sensorData.display();
//		}
//		else
//		{
//			std::cout << "Failed to read MPU" << std::endl;
//		}
//	}
}

void motorTest()
{
	CMotor motor1("4", "0", "67", "66");
	CMotor motor2("4", "1", "68", "69");
	CMotor motor3("1", "0", "44", "45");

	motor1.enableMotor();
	motor1.setTorque(0.01F);
	motor1.setTorque(0.0F);
	motor1.disableMotor();

	motor2.enableMotor();
	motor2.setTorque(0.01F);
	motor2.setTorque(0.0F);
	motor2.disableMotor();

	motor3.enableMotor();
	motor3.setTorque(0.01F);
	motor3.setTorque(0.0F);
	motor3.disableMotor();
}

