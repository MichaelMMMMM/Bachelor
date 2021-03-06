#ifndef CADC_H
#define CADC_H
#include "Global.h"

class CADCMMap
{
public:
	bool readADCValues(UInt16& adc1, UInt16& adc2, UInt16& adc3, bool wait);
private:
	UInt32 readRegister(const UInt32 addrOffset);
	void writeRegister(const UInt32 addrOffset, const UInt32 value);
public:
	CADCMMap();
	CADCMMap(const CADCMMap&) = delete;
	CADCMMap& operator=(const CADCMMap&) = delete;
	~CADCMMap();
private:
	int mMemoryFD;
	UInt8* mAddrPtr;

	static constexpr UInt32 sSTART_ADDR					= 0x44E0D000U;
	static constexpr UInt32 sEND_ADDR					= 0x44E0F000U;
	static constexpr UInt32 sMEM_SIZE					= sEND_ADDR - sSTART_ADDR;

	static constexpr UInt32 sIDMask						= 0b011110000000000000000U;
	static constexpr UInt32 sValueMask					= 0b111111111111U;
	static constexpr UInt32	sChannel1ID					= 0b00000U;
	static constexpr UInt32 sChannel2ID					= 0b00001U;
	static constexpr UInt32	sChannel3ID					= 0b00010U;

	static constexpr UInt32 sREVISION_Offset 			= 0x00U;
	static constexpr UInt32 sSYSCONFIG_Offset			= 0x10U;
	static constexpr UInt32 sIRQSTATUS_RAW_Offset		= 0x24U;
	static constexpr UInt32 sIRQSTATUS_Offset			= 0x28U;
	static constexpr UInt32 sIRQENABLE_SET_Offset		= 0x2CU;
	static constexpr UInt32 sIREQENABLE_CLR_Offset		= 0x30U;
	static constexpr UInt32 sIRQWAKEUP_Offset			= 0x34U;
	static constexpr UInt32 sDMAENABLE_SET_Offset		= 0x38U;
	static constexpr UInt32 sDMAENABLE_CLR_Offset		= 0x3CU;
	static constexpr UInt32 sCTRL_Offset				= 0x40U;
	static constexpr UInt32 sADCSTAT_Offset				= 0x44U;
	static constexpr UInt32 sADCRANGE_Offset			= 0x48U;
	static constexpr UInt32 sADC_CLKDIV_Offset			= 0x4CU;
	static constexpr UInt32 sADC_MISC_Offset			= 0x50U;
	static constexpr UInt32 sSTEPENABLE_Offset			= 0x54U;
	static constexpr UInt32 sIDLECONFIG_Offset			= 0x58U;
	static constexpr UInt32 sTS_CHARGE_STEPCONFIG_Offset= 0x5CU;
	static constexpr UInt32 sTS_CHARGE_DELAY_Offset		= 0x60U;
	static constexpr UInt32 sSTEPCONFIG1_Offset			= 0x64U;
	static constexpr UInt32 sSTEPDELAY1_Offset			= 0x68U;
	static constexpr UInt32 sSTEPCONFIG2_Offset			= 0x6CU;
	static constexpr UInt32 sSTEPDELAY2_Offset			= 0x70U;
	static constexpr UInt32 sSTEPCONFIG3_Offset			= 0x74U;
	static constexpr UInt32 sSTEPDELAY3_Offset			= 0x78U;
	static constexpr UInt32 sSTEPCONFIG4_Offset			= 0x7CU;
	static constexpr UInt32 sSTEPDELAY4_Offset			= 0x80U;
	static constexpr UInt32 sSTEPCONFIG5_Offset			= 0x84U;
	static constexpr UInt32 sSTEPDELAY5_Offset			= 0x88U;
	static constexpr UInt32 sSTEPCOFNIG6_Offset			= 0x8CU;
	static constexpr UInt32 sSTEPDELAY6_Offset			= 0x90U;
	static constexpr UInt32 sSTEPCOFNIG7_Offset			= 0x94U;
	static constexpr UInt32 sSTEPDELAY7_Offset			= 0x98U;
	static constexpr UInt32 sSTEPCOFNIG8_Offset			= 0x9CU;
	static constexpr UInt32 sSTEPDELAY8_Offset			= 0xA0U;
	static constexpr UInt32 sSTEPCONFIG9_Offset			= 0xA4U;
	static constexpr UInt32 sSTEPDELAY9_Offset			= 0xA8U;
	static constexpr UInt32 sSTEPCONFIG10_Offset		= 0xACU;
	static constexpr UInt32 sSTEPDELAY10_Offset			= 0xB0U;
	static constexpr UInt32 sSTEPCOFNIG11_Offset		= 0xB4U;
	static constexpr UInt32 sSTEPDELAY11_Offset			= 0xB8U;
	static constexpr UInt32 sSTEPCONFIG12_Offset		= 0xBCU;
	static constexpr UInt32 sSTEPDELAY12_Offset			= 0xC0U;
	static constexpr UInt32 sSTEPCOFNIG13_Offset		= 0xC4U;
	static constexpr UInt32 sSTEPDELAY13_Offset			= 0xC8U;
	static constexpr UInt32 sSTEPCONFIG14_Offset		= 0xCCU;
	static constexpr UInt32 sSTEPDELAY14_Offset			= 0xD0U;
	static constexpr UInt32 sSTEPCONFIG15_Offset		= 0xD4U;
	static constexpr UInt32 sSTEPDELAY15_Offset			= 0xD8U;
	static constexpr UInt32 sSTEPCOFNIG16_Offset		= 0xDCU;
	static constexpr UInt32 sSTEPDELAY16_Offset			= 0xE0U;
	static constexpr UInt32 sFIFO0COUNT_Offset			= 0xE4U;
	static constexpr UInt32 sFIFO0THRESHOLD_Offset		= 0xE8U;
	static constexpr UInt32 sDMA0REQ_Offset				= 0xECU;
	static constexpr UInt32 sFIFO1COUNT_Offset			= 0xF0U;
	static constexpr UInt32 sFIFO1THRESHOLD_Offset		= 0xF4U;
	static constexpr UInt32 sDMA1REQ_Offset				= 0xF8U;
	static constexpr UInt32 sFIFO0DATA_Offset			= 0x100U;
	static constexpr UInt32 sFIFO1DATA_Offset			= 0x200U;
};

#endif
