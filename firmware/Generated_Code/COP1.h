/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : COP1.h
**     Project     : ProcessorExpert
**     Processor   : MC9S08QG8CPB
**     Component   : Init_COP
**     Version     : Component 01.056, Driver 01.14, CPU db: 3.00.012
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2012-04-18, 17:50, # CodeGen: 34
**     Abstract    :
**          This file implements the Computer Operating Properly (COPFree)
**          module initialization according to the Peripheral 
**          Initialization Component settings, and defines interrupt service 
**          routines prototypes.
**          The computer operating properly (COP) module contains a free-running 
**          counter that generates a reset if allowed to overflow. The COP module
**          helps software recover from runaway code. Prevent a COP reset by 
**          clearing the COP counter periodically.
**     Settings    :
**          Component name                                 : COP1
**          Device                                         : COPFree
**          Settings 
**            Clock setting 
**              Clock select                               : Internal clock
**              Time-out period prescaler                  : 256 cycles
**              Time-out period                            : 256 ms
**          Initialization 
**            Call Init method                             : yes
**            Enable COP                                   : no
**     Contents    :
**         Init - void COP1_Init(void);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
#ifndef __COP1
#define __COP1
/* MODULE COP1. */
/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PE_Timer.h"
/* Include inherited components */
#include "Cpu.h"


void COP1_Init(void);
/*
** ===================================================================
**     Method      :  COP1_Init (component Init_COP)
**
**     Description :
**         This method initializes registers of the COP module
**         according to this Peripheral Initialization Component settings.
**         Call this method in the user code to initialize the
**         module. By default, the method is called by PE
**         automatically; see "Call Init method" property of the
**         component for more details.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END COP1. */
#endif /* ifndef __COP1 */
/*
** ###################################################################
**
**     This file was created by Processor Expert 5.3 [05.01]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
