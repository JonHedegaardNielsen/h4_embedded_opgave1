#include "../include/ProjectDefines.h"
#ifndef UART_H
#define UART_H
void uart_init(void);
void uart_putchar(char c);
void uart_puts(const char *s);
char uart_getchar(void);
extern void SetupUARTFunctionCallbackPointer(Function_Pointer_With_One_CharPointer_Parameter
                                             Function_To_Callback);
 
#endif
