#ifndef _ROTENC_H
#define _ROTENC_H

#include "delay.h"
#include "595.h"
#include "ROTA.h"
#include "ROTB.h"
#include "ROTC.h"
#include "PWM1.h"
#include "FCONTROL.h"

#define ROTENC_SYS_OK     0x00
#define ROTENC_SYS_HWERR  0x01
#define ROTENC_SYS_REMCTL 0x02

void ROTENC_Init(void);

void ROTENC_Cycle(void);

byte ROTENC_TRANS(byte b);

void ROTENC_ResetCounters(void);

#endif
