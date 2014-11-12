#ifndef _595_H
#define _595_H

#include "SM1.h"
#include "LATCH.h"
#include "PE_Types.h"


//REGISTRADOR C/ LATCH E TRI-STATE 74LS595


void HC595_SendByte(byte b, byte wait);

void HC595_Latch(void);

void HC595_SendByteAndLatch(byte b);

void HC595_Clear(void);





#endif
