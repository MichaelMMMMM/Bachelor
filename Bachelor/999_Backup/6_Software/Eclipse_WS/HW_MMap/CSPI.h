#ifndef CSPI_H
#define CSPI_H
#include "Global.h"

class CSPI
{
private:
	void writeRegister(const UInt32 regOffset, const UInt32 value);
public:
	CSPI();
	CSPI(const CSPI&) = delete;
	CSPI& operator=(const CSPI&) = delete;
	~CSPI();
private:
	int mMemoryFD;
	UInt8* mRegisterPtr;

	static constexpr UInt32 sMCSPI_START_ADDR		= 0x48030000U;
	static constexpr UInt32 sMCSPI_END_ADDR			= 0x48031000U;
	static constexpr UInt32 sMCSPI_MEM_SIZE			= sMCSPI_END_ADDR - sMCSPI_START_ADDR;

	static constexpr UInt32 sMCSPI_REVISION_Offset 	= 0x00U;
	static constexpr UInt32 sMCSPI_SYSCONFIG_Offset = 0x110U;
	static constexpr UInt32 sMCSPI_SYSSTATUS_Offset = 0x114U;
	static constexpr UInt32 sMCSPI_IRQSTATUS_Offset = 0x118U;
	static constexpr UInt32 sMCSPI_IRQENABLE_Offset = 0x11CU;
	static constexpr UInt32 sMCSPI_SYST_Offset		= 0x124U;
	static constexpr UInt32 sMCSPI_MODULCTRL_Offset = 0x128U;
	static constexpr UInt32 sMCSPI_CH0CONF_Offset	= 0x12CU;
	static constexpr UInt32 sMCSPI_CH0STAT_Offset	= 0x130U;
	static constexpr UInt32 sMCSPI_CH0CTRL_Offset	= 0x134U;
	static constexpr UInt32 sMCSPI_TX0_Offset		= 0x138U;
	static constexpr UInt32 sMCSPI_RX0_Offset		= 0x13CU;
	static constexpr UInt32 sMCSPI_CH1CONF_Offset	= 0x140U;
	static constexpr UInt32 sMCSPI_CH1STAT_Offset	= 0x144U;
	static constexpr UInt32 sMCSPI_CH1CTRL_Offset	= 0x148U;
	static constexpr UInt32 sMCSPI_TX1_Offset		= 0x14CU;
	static constexpr UInt32 sMCSPI_RX1_Offset		= 0x150U;
	static constexpr UInt32 sMCSPI_CH2CONF_Offset	= 0x154U;
	static constexpr UInt32 sMCSPI_CH2STAT_Offset	= 0x158U;
	static constexpr UInt32 sMCSPI_CH2CTRL_Offset	= 0x15CU;
	static constexpr UInt32 sMCSPI_TX2_Offset		= 0x160U;
	static constexpr UInt32 sMCSPI_RX2_Offset		= 0x164U;
	static constexpr UInt32 sMCSPI_CH3CONF_Offset	= 0x168U;
	static constexpr UInt32 sMCSPI_CH3STAT_Offset	= 0x16CU;
	static constexpr UInt32 sMCSPI_CH3CTRL_Offset	= 0x170U;
	static constexpr UInt32 sMCSPI_TX3_Offset		= 0x174U;
	static constexpr UInt32 sMCSPI_RX3_Offset		= 0x178U;
	static constexpr UInt32 sMCSPI_XFERLEVEL_Offset = 0x17CU;
	static constexpr UInt32 sMCSPI_DAFTX_Offset		= 0x180U;
	static constexpr UInt32 sMCSPI_DAFRX_Offset		= 0x184U;
};
#endif
