#include "CADC.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "Global.h"

CADC::CADC() : mMemoryFD(-1), mAddrPtr(nullptr)
{
	mMemoryFD = open("/dev/mem", O_RDWR);
	sAssertion(mMemoryFD >= 0, "(CSPI::CSPI) Failed to open /dev/mem", true);
	mAddrPtr = reinterpret_cast<UInt8*>(mmap(0, sMEM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, mMemoryFD, sSTART_ADDR));
	//sAssertion(reinterpret_cast<void*>(mAddrPtr) != MAP_FAILED, "(SPI::CSPI) Failed to mmap", true);

	UInt32 stepConfig = *reinterpret_cast<UInt32*>(mAddrPtr + sSTEPENABLE_Offset);
	std::cout << stepConfig << std::endl;
	UInt32 step1config = *reinterpret_cast<UInt32*>(mAddrPtr + sSTEPCONFIG1_Offset);
	UInt32 step1delay  = *reinterpret_cast<UInt32*>(mAddrPtr + sSTEPDELAY1_Offset);
	UInt32 step2config = *reinterpret_cast<UInt32*>(mAddrPtr + sSTEPCONFIG2_Offset);
	UInt32 step2delay  = *reinterpret_cast<UInt32*>(mAddrPtr + sSTEPDELAY2_Offset);
	UInt32 step3config = *reinterpret_cast<UInt32*>(mAddrPtr + sSTEPCONFIG3_Offset);
	UInt32 step3delay  = *reinterpret_cast<UInt32*>(mAddrPtr + sSTEPDELAY3_Offset);

	std::cout << step3delay << std::endl;

	UInt32 data;
	UInt32 fifoCount;
	UInt32 adcData[3];
	while(true)
	{
		fifoCount = (*reinterpret_cast<UInt32*>(mAddrPtr + sFIFO1COUNT_Offset)) & 0b01111111U;
		for(UInt32 i = 0; i < 3 ; i++)
		{
			fifoCount = (*reinterpret_cast<UInt32*>(mAddrPtr + sFIFO1COUNT_Offset)) &
						0b01111111U;
			if(fifoCount > 0U)
			{
				data = (*reinterpret_cast<UInt32*>(mAddrPtr + sFIFO1DATA_Offset)) &
						0b0111111111111U;

				std::cout << data << std::endl;
			}
		}

	}
}
CADC::~CADC()
{

}
