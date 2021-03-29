#ifndef LEON3_UART_H_
#define LEON3_UART_H_
#include "leon3_types.h"
int8_t leon3_putchar(char c);
int8_t esperarVacio(); //Espera hasta que el buffer se vacíe
#endif /* LEON3_UART_H_*/

char leon3_getchar();
uint8_t leon3_UART_TF_IS_EMPTY();
void leon3_UART_RX_ENABLE();
void leon3_UART_RX_IRQ_ENABLE();
void leon3_UART_ConfigRXTXLoop(uint8_t set_rxtxloop);
