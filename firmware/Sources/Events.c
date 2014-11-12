/** ###################################################################
**     Filename  : Events.c
**     Project   : ProcessorExpert
**     Processor : MC9S08QG8CPB
**     Component : Events
**     Version   : Driver 01.02
**     Compiler  : CodeWarrior HCS08 C Compiler
**     Date/Time : 2011-11-04, 01:49, # CodeGen: 0
**     Abstract  :
**         This is user's event module.
**         Put your event handler code here.
**     Settings  :
**     Contents  :
**         No public methods
**
** ###################################################################*/
/* MODULE Events */


#include "Cpu.h"
#include "Events.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "delay.h"
/*
** ===================================================================
**     Event       :  TI1_OnInterrupt (module Events)
**
**     Component   :  TI1 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TI1_OnInterrupt(void)
{
  /* Write your code here ... */
	INCR_Time();

}

/*
** ===================================================================
**     Event       :  I2C1_OnReceiveData (module Events)
**
**     Component   :  I2C1 [InternalI2C]
**     Description :
**         This event is invoked when I2C finishes the reception of the
**         data successfully. This event is not available for the SLAVE
**         mode and if both RecvChar and RecvBlock are disabled. This
**         event is enabled only if interrupts/events are enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void I2C1_OnReceiveData(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  I2C1_OnTransmitData (module Events)
**
**     Component   :  I2C1 [InternalI2C]
**     Description :
**         This event is invoked when I2C finishes the transmission of
**         the data successfully. This event is not available for the
**         SLAVE mode and if both SendChar and SendBlock are disabled.
**         This event is enabled only if interrupts/events are enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void I2C1_OnTransmitData(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  I2C1_OnRxChar (module Events)
**
**     Component   :  I2C1 [InternalI2C]
**     Description :
**         Called when a correct character is received. This event is
**         not available for the MASTER mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void I2C1_OnRxChar(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  I2C1_OnTxChar (module Events)
**
**     Component   :  I2C1 [InternalI2C]
**     Description :
**         Called when a correct character is sent (placed to the
**         transmitter). This event is not available for the MASTER
**         mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void I2C1_OnTxChar(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  AD1_OnEnd (module Events)
**
**     Component   :  AD1 [ADC]
**     Description :
**         This event is called after the measurement (which consists
**         of <1 or more conversions>) is/are finished.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AD1_OnEnd(void)
{
  /* Write your code here ... */
}


/* END Events */

/*
** ###################################################################
**
**     This file was created by Processor Expert 5.1 [04.49]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
