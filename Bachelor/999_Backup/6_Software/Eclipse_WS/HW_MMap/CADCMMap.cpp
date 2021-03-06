#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>

#include "CADCMMap.h"
#include "Global.h"

CADCMMap::CADCMMap() : mMemoryFD(-1), mAddrPtr(nullptr)
{
	mMemoryFD = open("/dev/mem", O_RDWR);
	sAssertion(mMemoryFD >= 0, "(CSPI::CSPI) Failed to open /dev/mem", true);
	mAddrPtr = reinterpret_cast<UInt8*>(mmap(0, sMEM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, mMemoryFD, sSTART_ADDR));
	//sAssertion(reinterpret_cast<void*>(mAddrPtr) != MAP_FAILED, "(SPI::CSPI) Failed to mmap", true);

	this->writeRegister(sCTRL_Offset, 0U);

	UInt32 test = cBIT26 | cBIT4 | cBIT0;
	this->writeRegister(sSTEPCONFIG1_Offset, cBIT26);
	this->writeRegister(sSTEPCONFIG2_Offset, cBIT26 | cBIT19);
	this->writeRegister(sSTEPCONFIG3_Offset, cBIT26 | cBIT20);
	//this->writeRegister(sSTEPENABLE_Offset, cBIT3 | cBIT2 | cBIT1);

	this->writeRegister(sCTRL_Offset, cBIT2 | cBIT1 |cBIT0);
}
CADCMMap::~CADCMMap()
{

}
void CADCMMap::writeRegister(const UInt32 addrOffset, const UInt32 value)
{
	*reinterpret_cast<UInt32*>(mAddrPtr + addrOffset) = value;
}
UInt32 CADCMMap::readRegister(const UInt32 addrOffset)
{
	return *reinterpret_cast<UInt32*>(mAddrPtr + addrOffset);
}
bool CADCMMap::readADCValues(UInt16& adc1, UInt16& adc2, UInt16& adc3, bool wait)
{

	this->writeRegister(sSTEPENABLE_Offset, cBIT3 | cBIT2 | cBIT1);
	bool finished = false;
	do
	{
		UInt32 fifo1Count = this->readRegister(sFIFO1COUNT_Offset);
		UInt32 ctrl = this->readRegister(sCTRL_Offset);
		UInt32 config1 = this->readRegister(sSTEPCONFIG1_Offset);
		UInt32 config2 = this->readRegister(sSTEPCONFIG2_Offset);
		UInt32 config3 = this->readRegister(sSTEPCONFIG3_Offset);
		UInt32 stepEnable = this->readRegister(sSTEPENABLE_Offset);
		if(fifo1Count >= 3U)
		{
			finished = true;
			for(UInt32 i = 0U; i < 3U; i++)
			{
				UInt16 value = this->readRegister(sFIFO1DATA_Offset);
				UInt16 id    = ( value & sIDMask) >> 16U;
				value 		 = ( value & sValueMask);
				switch(i)
				{
				case 0:
					adc1 = value;
					break;
				case 1:
					adc2 = value;
					break;
				case 2:
					adc3 = value;
					break;
				default:
					break;
				}
			}
		}
	}while( (finished == false) && (wait == true));
	return finished;
}
