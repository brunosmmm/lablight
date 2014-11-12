/** ###################################################################
**     Filename  : ProcessorExpert.c
**     Project   : ProcessorExpert
**     Processor : MC9S08QG8CPB
**     Version   : Driver 01.12
**     Compiler  : CodeWarrior HCS08 C Compiler
**     Date/Time : 2011-11-04, 01:49, # CodeGen: 0
**     Abstract  :
**         Main module.
**         This module contains user's application code.
**     Settings  :
**     Contents  :
**         No public methods
**
** ###################################################################*/
/* MODULE ProcessorExpert */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "SM1.h"
#include "FCONTROL.h"
#include "LATCH.h"
#include "ROTA.h"
#include "ROTB.h"
#include "ROTC.h"
#include "PWM1.h"
#include "TI1.h"
#include "I2C1.h"
#include "AD1.h"
#include "COP1.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "595.h"
#include "delay.h"
#include "RotEnc.h"

void main(void)
{
  /* Write your local variable definition here */
byte test = 0;
	
	
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */
  
  //FCONTROL_SetVal();
  

  
  ROTENC_Init();
  
  for(;;)
  {
	  
	  if (GET_TimeOvr())
	  {
		  ROTENC_ResetCounters();
	  }
	  
	  ROTENC_Cycle();
	  
	  //HC595_SendByteAndLatch(ROTENC_TRANS(test++));
	  
	  //DELAY_Block_ms(100);
	  
  }

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END ProcessorExpert */
/*
** ###################################################################
**
**     This file was created by Processor Expert 5.1 [04.49]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
