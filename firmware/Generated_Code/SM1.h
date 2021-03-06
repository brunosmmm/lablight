/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : SM1.h
**     Project     : ProcessorExpert
**     Processor   : MC9S08QG8CPB
**     Component   : SynchroMaster
**     Version     : Component 02.344, Driver 01.30, CPU db: 3.00.012
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2012-04-18, 17:50, # CodeGen: 34
**     Abstract    :
**         This component "SynchroMaster" implements MASTER part of synchronous
**         serial master-slave communication.
**     Settings    :
**         Synchro type                : MASTER
**
**         Serial channel              : SPI
**
**         Protocol
**             Init baud rate          : 1MHz
**             Clock edge              : falling
**             Width                   : 8 bits (always)
**             Empty character         : 0
**             Empty char. on input    : RECEIVED
**
**         Registers
**             Input buffer            : SPID      [$002D]
**             Output buffer           : SPID      [$002D]
**             Control register        : SPIC1     [$0028]
**             Mode register           : SPIC2     [$0029]
**             Baud setting reg.       : SPIBR     [$002A]
**
**
**
**         Used pins                   :
**         ----------------------------------------------------------
**              Function    | On package |    Name
**         ----------------------------------------------------------
**               Output     |     9      |  PTB3_KBIP7_MOSI_ADP7
**               Clock      |     10     |  PTB2_KBIP6_SPSCK_ADP6
**         ----------------------------------------------------------
**
**     Contents    :
**         RecvChar              - byte SM1_RecvChar(SM1_TComData *Chr);
**         SendChar              - byte SM1_SendChar(SM1_TComData Chr);
**         CharsInRxBuf          - byte SM1_CharsInRxBuf(word *Chr);
**         GetCharsInRxBuf       - word SM1_GetCharsInRxBuf(void);
**         GetCharsInTxBuf       - word SM1_GetCharsInTxBuf(void);
**         SetShiftClockPolarity - byte SM1_SetShiftClockPolarity(byte Edge);
**         SetIdleClockPolarity  - byte SM1_SetIdleClockPolarity(byte Level);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __SM1
#define __SM1

/* MODULE SM1. */

#include "Cpu.h"



#define SM1_EOF 0x00U                  /* Value of the empty character defined in the Empty character property. */

#ifndef __BWUserType_SM1_TComData
#define __BWUserType_SM1_TComData
  typedef byte SM1_TComData;           /* User type for communication. */
#endif

#ifndef __BWUserType_SM1_TError
#define __BWUserType_SM1_TError
  typedef union {
    byte err;
    struct {
      /*lint -save  -e46 Disable MISRA rule (6.4) checking. */
      bool OverRun  : 1;   /* OverRun error flag - the data overflow on the input has been detected. Both hardware detection (if supported) and software detection (when the value of Input buffer size property is 0) is used. */
      bool RxBufOvf : 1;   /* Rx buffer full error flag - the input circular buffer defined by the Input buffer size property has overrun. */
      bool FaultErr : 1;   /* Fault mode error flag - only if supported by hardware */
      /*lint -restore Enable MISRA rule (6.4) checking. */
    }errName;
  } SM1_TError;                        /* Error flags. For languages which don't support bit access is byte access only to error flags possible.  */
#endif




#define SM1_RecvChar(Chr) \
  ((byte) (SPIS_SPRF ? (((*(Chr)) = SPID), (byte)ERR_OK) : (byte)ERR_RXEMPTY))
/*
** ===================================================================
**     Method      :  SM1_RecvChar (component SynchroMaster)
**
**     Description :
**         If any data is received, this method returns one character,
**         otherwise it returns an error code (it does not wait for
**         data). 
**         For information about SW overrun behavior please see
**         <General info page>.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Chr             - A pointer to the received character
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK - The valid data is received.
**                           ERR_SPEED - This device does not work in
**                           the active speed mode.
**                           ERR_RXEMPTY - No data in receiver.
**                           ERR_OVERRUN - Overrun error was detected
**                           from the last char or block received. In
**                           polling mode, this error code is returned
**                           only when the hardware supports detection
**                           of the overrun error. If interrupt service
**                           is enabled, and input buffer allocated by
**                           the component is full, the component
**                           behaviour depends on <Input buffer size>
**                           property : if property is 0, last received
**                           data-word is preserved (and previous is
**                           overwritten), if property is greater than 0,
**                           new received data-word are ignored.
**                           ERR_FAULT - Fault error was detected from
**                           the last char or block received. In the
**                           polling mode the ERR_FAULT is return until
**                           the user clear the fault flag bit, but in
**                           the interrupt mode ERR_FAULT is returned
**                           only once after the fault error occured.
**                           This error is supported only on the CPUs
**                           supports the faul mode function - where
**                           <Fault mode> property is available.
** ===================================================================
*/

byte SM1_SendChar(SM1_TComData Chr);
/*
** ===================================================================
**     Method      :  SM1_SendChar (component SynchroMaster)
**
**     Description :
**         Sends one character to the channel.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Chr             - Character to send
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_DISABLED - Device is disabled (only if
**                           output DMA is supported and enabled)
**                           ERR_TXFULL - Transmitter is full
** ===================================================================
*/

byte SM1_CharsInRxBuf(word *Chr);
/*
** ===================================================================
**     Method      :  SM1_CharsInRxBuf (component SynchroMaster)
**
**     Description :
**         Returns the number of characters in the input buffer.
**         Note: If the Interrupt service is disabled, and the Ignore
**         empty character is set to yes, and a character has been
**         received, then this method returns 1 although it was an
**         empty character.
**         (deprecated method - Use the GetCharsInRxBuf method instead!)
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Chr             - A pointer to number of characters in the
**                           input buffer
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

#define SM1_GetCharsInRxBuf() \
((word) SPIS_SPRF)                     /* Return number of chars in the receive buffer */
/*
** ===================================================================
**     Method      :  SM1_GetCharsInRxBuf (component SynchroMaster)
**
**     Description :
**         Returns the number of characters in the input buffer.
**         Note: If the Interrupt service is disabled, and the Ignore
**         empty character is set to yes, and a character has been
**         received, then this method returns 1 although it was an
**         empty character.
**     Parameters  : None
**     Returns     :
**         ---             - Number of characters in the input buffer.
** ===================================================================
*/

#define SM1_GetCharsInTxBuf() \
(SPIS_SPTEF ? (word)0U : (word)1U)     /* Return number of chars in the transmit buffer */
/*
** ===================================================================
**     Method      :  SM1_GetCharsInTxBuf (component SynchroMaster)
**
**     Description :
**         Returns the number of characters in the output buffer.
**     Parameters  : None
**     Returns     :
**         ---             - Number of characters in the output buffer.
** ===================================================================
*/

byte SM1_SetShiftClockPolarity(byte Edge);
/*
** ===================================================================
**     Method      :  SM1_SetShiftClockPolarity (component SynchroMaster)
**
**     Description :
**         Sets the shift clock polarity at runtime. Output data will
**         be shifted on the selected edge polarity. The method will
**         disable communication (if enabled), change the shift clock
**         polarity end re-enable the communication (if it was enabled
**         before).
**     Parameters  :
**         NAME            - DESCRIPTION
**         Edge            - Edge polarity.
**                           0-falling edge
**                           1-rising edge
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_RANGE - Parameter out of range
**                           
**                           [ Version specific information neither for
**                           Freescale HC08 derivatives ] 
**                           [ERR_DISABLED] - Obsolete, this error code
**                           is not used.
** ===================================================================
*/

byte SM1_SetIdleClockPolarity(byte Level);
/*
** ===================================================================
**     Method      :  SM1_SetIdleClockPolarity (component SynchroMaster)
**
**     Description :
**         Sets the idle clock polarity at runtime. If the
**         communication does not run, the clock signal will have
**         required level. The method will disable communication (if
**         enabled), change the idle clock polarity end re-enable the
**         communication (if it was enabled before).
**     Parameters  :
**         NAME            - DESCRIPTION
**         Level           - Idle clock polarity:
**                           0-low
**                           1-high
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_RANGE - Parameter out of range
**                           
**                           [ Version specific information neither for
**                           Freescale HC08 derivatives ] 
**                           [ERR_DISABLED] - Obsolete, this error code
**                           is not used.
**                           
** ===================================================================
*/

void SM1_Init(void);
/*
** ===================================================================
**     Method      :  SM1_Init (component SynchroMaster)
**
**     Description :
**         Initializes the associated peripheral(s) and the component 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/


/* END SM1. */

#endif /* ifndef __SM1 */
/*
** ###################################################################
**
**     This file was created by Processor Expert 5.3 [05.01]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
