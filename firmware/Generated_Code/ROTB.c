/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : ROTB.c
**     Project     : ProcessorExpert
**     Processor   : MC9S08QG8CPB
**     Component   : BitIO
**     Version     : Component 02.075, Driver 03.27, CPU db: 3.00.012
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2012-04-18, 17:50, # CodeGen: 34
**     Abstract    :
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This component is set to work in Input direction only.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings    :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       13            |  PTA3_KBIP3_SCL_ADP3
**             ----------------------------------------------------
**
**         Port name                   : PTA
**
**         Bit number (in port)        : 3
**         Bit mask of the port        : $0008
**
**         Initial direction           : Input (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : up
**
**         Port data register          : PTAD      [$0000]
**         Port control register       : PTADD     [$0001]
**
**         Optimization for            : speed
**     Contents    :
**         GetVal - bool ROTB_GetVal(void);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE ROTB. */

#include "ROTB.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"


/*
** ===================================================================
**     Method      :  ROTB_GetVal (component BitIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**         Note: This component is set to work in Input direction only.
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
/*
bool ROTB_GetVal(void)

**  This method is implemented as a macro. See ROTB.h file.  **
*/


/* END ROTB. */
/*
** ###################################################################
**
**     This file was created by Processor Expert 5.3 [05.01]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
