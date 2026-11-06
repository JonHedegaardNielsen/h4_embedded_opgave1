#include "include/ProjectDefines.h"
#include <avr/interrupt.h>
#include <stdint.h>
#define BAUD 9600
#define UBRR_VALUE ((F_CPU / (16UL * BAUD)) - 1)
#include <avr/io.h>
#include "include/uart.h"
#include <util/delay.h>

#include "include/timer.h"

int main(void) {
  DDRB |= (1 << PB0);
  setupTimer(15624);
  uart1_init();

  while (1) {
    char c = uart_getchar();
    // c = c ^ 0x20;
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'){
        c ^= 0x20;
    }
    if (c) {
      uart_puts(&c);
    }
  }
}
