#include "CSPI.h"
#include <iostream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>


CSPI::CSPI() : mMemoryFD(-1), mRegisterPtr(nullptr)
{
	mMemoryFD = open("/dev/mem", O_RDWR);
	sAssertion(mMemoryFD <= 0, "(CSPI::CSPI) Failed to open /dev/mem", true);
	mRegisterPtr = reinterpret_cast<UInt8*>(mmap(0, sMCSPI_MEM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, mMemoryFD, sMCSPI_START_ADDR));
	sAssertion(mRegisterPtr != MAP_FAILED, "(SPI::CSPI) Failed to mmap", true);
}
CSPI::~CSPI()
{

}
void CSPI::writeRegister(const UInt32 regOffset, const UInt32 value)
{

}
