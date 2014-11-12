#include "delay.h"

static dword curTimeUS = 0x00000000;
static dword curTimeMS = 0x00000000;

static byte timeOvr = 0;

#define DELAYMS

void INCR_Time(void)
{
#ifdef DELAYUS
	if (curTimeUS < 0xFFFFFFF5) curTimeUS+=10;
	else {
		curTimeMS++;
		curTimeUS = 0;
	}
#endif
#ifdef DELAYMS
	if (curTimeMS < 0xFFFFFFFF) curTimeMS++;
	else {
		curTimeMS = 0x00000000;
		timeOvr = 1;
	}
#endif
}
	
byte GET_TimeOvr(void)
{
	byte ovr = timeOvr;
	
	timeOvr = 0;
	
	return ovr;
	
}
	

dword GET_TimeUS(void)
{
	
	return curTimeUS;
	
}

dword GET_TimeMS(void)
{
	return curTimeMS;
	
}


void DELAY_Block_ms(dword ms)
{

	dword start = GET_TimeMS();
	
	while((start + ms) > GET_TimeMS());
	
}
