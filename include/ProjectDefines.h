#include <avr/io.h>

#ifndef PROJECTDEFINES_H_
#define PROJECTDEFINES_H_

#if defined (_AVR_IOM168_H_) || defined (_AVR_IOM328P_H_)
#define USR0_Vect_Num USART_RX_vect

#endif

#if defined (_AVR_IOM2560_H_) || defined (_AVR_ATMEGA328PB_H_INCLUDED)
#define USR0_Vect_Num USART0_RX_vect 

#endif

#if defined(_AVR_IOM2560_H_) || defined (_AVR_ATMEGA328PB_H_INCLUDED)
#define GreenLedBit		1
#define YellowLedBit	2
#define RedLedBit		3
#endif
typedef void (*Function_Pointer_With_One_CharPointer_Parameter)(char *);
#define F_CPU 16000000UL

#endif /* PROJECTDEFINES_H_ */
