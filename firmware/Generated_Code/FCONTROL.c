/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : FCONTROL.c
**     Project     : ProcessorExpert
**     Processor   : MC9S08QG8CPB
**     Component   : BitIO
**     Version     : Component 02.075, Driver 03.27, CPU db: 3.00.012
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2012-04-18, 17:50, # CodeGen: 34
**     Abstract    :
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This component is set to work in Output direction only.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings    :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       8             |  PTB4_MISO
**             ----------------------------------------------------
**
**         Port name                   : PTB
**
**         Bit number (in port)        : 4
**         Bit mask of the port        : $0010
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : PTBD      [$0002]
**         Port control register       : PTBDD     [$0003]
**
**         Optimization for            : speed
**     Contents    :
**         GetVal - bool FCONTROL_GetVal(void);
**         PutVal - void FCONTROL_PutVal(bool Val);
**         ClrVal - void FCONTROL_ClrVal(void);
**         SetVal - void FCONTROL_SetVal(void);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE FCONTROL. */

#include "FCONTROL.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"


/*
** ===================================================================
**     Method      :  FCONTROL_GetVal (component BitIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**         Note: This component is set to work in Output direction only.
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
/*
bool FCONTROL_GetVal(void)

**  This method is implemented as a macro. See FCONTROL.h file.  **
*/

/*
** ===================================================================
**     Method      :  FCONTROL_PutVal (component BitIO)
**
**     Description :
**         This method writes the new output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val             - Output value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
**     Returns     : Nothing
** ===================================================================
*/
void FCONTROL_PutVal(bool Val)
{
  if (Val) {
    setReg8Bits(PTBD, 0x10U);          /* PTBD4=0x01U */
  } else { /* !Val */
    clrReg8Bits(PTBD, 0x10U);          /* PTBD4=0x00U */
  } /* !Val */
}

/*
** ===================================================================
**     Method      :  FCONTROL_ClrVal (component BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void FCONTROL_ClrVal(void)

**  This method is implemented as a macro. See FCONTROL.h file.  **
*/

/*
** ===================================================================
**     Method      :  FCONTROL_SetVal (component BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void FCONTROL_SetVal(void)

**  This method is implemented as a macro. See FCONTROL.h file.  **
*/


/* END FCONTROL. */
/*
** ###################################################################
**
**     This file was created by Processor Expert 5.3 [05.01]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
