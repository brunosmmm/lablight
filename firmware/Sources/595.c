#include "595.h"


void HC595_SendByte(byte b, byte wait)
{
	
	(void)SM1_SendChar(b);
	
	if (wait)
	{
		while (SM1_GetCharsInTxBuf());
		
	}
	
}

void HC595_Latch()
{
	
	LATCH_SetVal();
	
	asm nop;
	asm nop;
	asm nop;
	asm nop;
	asm nop;
	asm nop;
	asm nop;
	
	LATCH_ClrVal();
	
}

void HC595_SendByteAndLatch(byte b)
{
	
	HC595_SendByte(b,1);
	
	HC595_Latch();
	
}


void HC595_Clear(void)
{
	
	HC595_SendByteAndLatch(0x00);
}
