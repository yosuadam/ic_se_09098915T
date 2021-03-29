//AUTORES: JOSE ANGEL ROMERO DE AVILA LOPEZ, JORGE GARCIA GARCIA, YOSUA MARTINEZ SANCHEZ

#include "leon3_uart.h"
#include "leon3_bprint.h"
#include "leon3_hw_irqs.h"
#include "leon3_ev_handling.h"
void hw_irq_vector_0x11_handler(void) {
	leon3_print_string("handler hw irq vector 0x11\n");
}

void hw_irq_vector_0x82_handler(void) {
	leon3_print_string("ERROR DIVISION POR 0\n");
}

int main() {
	//Instalar como manejador del trap 0x83 la rutina
	// que habilita las interrupciones
	leon3_install_handler(0x83, leon3_trap_handler_enable_irqs);
	//Instalar el manejador del trap que 0x83 la rutina
	// que deshabilita las interrupciones
	leon3_install_handler(0x84, leon3_trap_handler_disable_irqs);
	//Deshabilitar las interrupciones
	leon3_sys_call_disable_irqs();
	//Instalar la función hw_irq_vector_0x11_handler como
	// manejador de la interrupción de nivel 1
	//COMPLETAR
	leon3_install_handler(0x82, hw_irq_vector_0x82_handler);
	leon3_install_handler(0x11, hw_irq_vector_0x11_handler);
	//
	//Desenmascarar la interrupcion de nivel 1 (correspondiente
	//al vector 17, es decir el vector 0x11)
	leon3_unmask_irq(1);
	//Habilitar las interrupciones
	//EJERCICIO_6
	//leon3_sys_call_disable_irqs();
	leon3_sys_call_enable_irqs();
	//Fuerza la interrupción
	//EJERCICIO_5
	//leon3_mask_irq(1);
	leon3_sparc_force_irq(1);

	uint8_t i;
	uint8_t j;
	for (i = 10; i > 0; i--)
		j = j / (i - 9);

	return 0;
}

