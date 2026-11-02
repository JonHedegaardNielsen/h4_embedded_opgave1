#include <avr/interrupt.h>
#include <stdint.h>
#include <string.h>
#define F_CPU 16000000UL
#define BAUD 9600
#define UBRR_VALUE ((F_CPU / (16UL * BAUD)) - 1)
#include <avr/io.h>
#include <util/delay.h>

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
  if ((UCSR0A & (1 << RXC0))) {
    return UDR0;
  }
  return 0;
}

// koden der kører når tiden løber ud
ISR(TIMER1_COMPA_vect) { PORTB ^= (1 << PB0); }

void setupTimer(uint32_t time) {
  //   // CTC mode
  TCCR1B |= (1 << WGM12);
  //   // 16MHz / 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);
  //   // tid
  OCR1A = time;
  // Interrupt når OCR1A nås
  TIMSK1 |= (1 << OCIE1A);
  sei();
}

int main(void) {
  DDRB |= (1 << PB0);
  setupTimer(15624);
  uart_init();

  while (1) {
    char c = uart_getchar();
    if (c >= 'a' && c <= 'z'){
      c = c - ('a' - 'A');
    }
    else if (c >= 'A' && c <= 'Z'){
      c = c + ('a' - 'A');
    }
    if (c) {
      uart_puts(&c);
    }
  }
}
