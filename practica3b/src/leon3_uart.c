#include "leon3_uart.h"
//! LEON3 UART A Transmit FIFO is FULL
#define LEON3_UART_TFF (0x200)

//Estructura de datos que permite acceder a los registros de la
//UART de LEON3
struct UART_regs
{
	/** \brief UART Data Register */
	volatile uint32_t Data; /* 0x80000100 */
	/** \brief UART Status Register */
	volatile uint32_t Status; /* 0x80000104 */
	/** \brief UART Control Register */
	volatile uint32_t Ctrl; /* 0x80000108 */
	/** \brief UART Scaler Register */
	volatile uint32_t Scaler; /* 0x8000010C */
};
struct UART_regs * pLEON3_UART_REGS= (struct UART_regs *)0x80000100;

int8_t leon3_putchar (char c) {
	uint32_t write_timeout=0;
	while((LEON3_UART_TFF & pLEON3_UART_REGS->Status) &&(write_timeout < 0xAAAAA)){
			write_timeout++;
	} //Esperar hasta que TFF es 0
	if(write_timeout < 0xAAAAA)
		pLEON3_UART_REGS->Data = c;
	return (write_timeout == 0xAAAAA);
}

 char leon3_getchar () {
	return pLEON3_UART_REGS->Data ;
}

uint8_t leon3_UART_TF_IS_EMPTY () {
	return pLEON3_UART_REGS->Status ;
}

void leon3_UART_RX_ENABLE(){
	//TODO
}

void leon3_UART_RX_IRQ_ENABLE(){
	//TODO
}

void leon3_UART_ConfigRXTXLoop(uint8_t set_rxtxloop){

}

int8_t esperarVacio (){
	  uint32_t write_timeout=0;
	  while ((LEON3_UART_TFF & pLEON3_UART_REGS->Status)){
		  write_timeout++;
	  }
	  return write_timeout;
}


