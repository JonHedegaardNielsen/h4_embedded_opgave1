#include <avr/interrupt.h>
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include "../include/ProjectDefines.h"
// koden der kører når tiden løber ud
ISR(TIMER1_COMPA_vect) { PORTB ^= (1 << PB0); }

void setupTimer(uint32_t time) {
  // CTC mode
  TCCR1B |= (1 << WGM12);
  // 16MHz / 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);
  // tid
  OCR1A = time;
  // Interrupt når OCR1A nås
  TIMSK1 |= (1 << OCIE1A);
  sei();
}
