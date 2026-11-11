#include <avr/interrupt.h>
#include <stdint.h>
#include <string.h>
#define F_CPU 16000000UL
#define BAUD 9600
#define UBRR_VALUE ((F_CPU / (16UL * BAUD)) - 1)
#include <avr/io.h>
#include <util/delay.h>
#include "../include/ProjectDefines.h"

static Function_Pointer_With_One_CharPointer_Parameter Callback_Function_Pointer = NULL;
 
void SetupUARTFunctionCallbackPointer(Function_Pointer_With_One_CharPointer_Parameter 
                                      Function_To_Callback)
{
	Callback_Function_Pointer = Function_To_Callback;
}
void uart_init(void) {
  UBRR0H = (uint8_t)(UBRR_VALUE >> 8);
  UBRR0L = (uint8_t)UBRR_VALUE;

  UCSR0B = (1 << TXEN0) | (1 << RXEN0);
  UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void uart_putchar(char c) {
  while (!(UCSR0A & (1 << UDRE0)))
    ;
  UDR0 = c;
}

void uart_puts(const char *s) {
  while (*s)
    uart_putchar(*s++);
}

char uart_getchar(void) {
  // interrupt når nogen skriver
  while (!(UCSR0A & (1 << RXC0))) {
  }
  return UDR0;
}
