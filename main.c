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
  setupTimer(15624);
  uart_init();

  while (1) {
    char c = uart_getchar();
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'){
        c ^= 0x20;
    }
    uart_putchar(c);
  }
}
