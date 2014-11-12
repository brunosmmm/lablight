#ifndef _DELAY_H
#define _DELAY_H

#include "TI1.h"

void INCR_Time(void);

dword GET_TimeMS(void);

dword GET_TimeUS(void);

void DELAY_Block_ms(dword ms);

byte GET_TimeOvr(void);

#endif
