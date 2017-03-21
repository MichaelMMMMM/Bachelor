#include <iostream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "Global.h"
#include "CADC.h"

#define GPIO2_START_ADDR 0x481AC000
#define GPIO2_END_ADDR	 0x481AE000
#define GPIO2_SIZE (GPIO2_END_ADDR - GPIO2_START_ADDR)

#define GPIO_SETDATAOUT 	0x65
#define GPIO_CLEARDATAOUT 	0x64
#define LED (1<<2)

void gpioTest();
void adcTest();

int main()
{
	adcTest();
}
void adcTest()
{
	CADC adc;
}
void gpioTest()
{
	int fd = open("/dev/mem", O_RDWR);
	volatile void* gpio_addr = mmap(0, GPIO2_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, GPIO2_START_ADDR);

	volatile unsigned int* gpio_setdataout_addr    = (unsigned int*)gpio_addr + GPIO_SETDATAOUT;
	volatile unsigned int* gpio_cleardataout_addr = (unsigned int*)gpio_addr + GPIO_CLEARDATAOUT;

	while(true)
	{
		*gpio_setdataout_addr  = LED;
		*gpio_cleardataout_addr = LED;
	}
}
