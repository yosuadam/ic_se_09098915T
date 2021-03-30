/*
 * leon_irqs.c
 *
 *  Created on: Feb 28, 2013
 *      Author: user
 */
#include "leon3_types.h"

//Utilizad estos punteros para acceder a los registros
uint32_t * LEON3_ICLEAR = (uint32_t *) (0x80000000 + 0x20c);
uint32_t * LEON3_IMASK = (uint32_t *) (0x80000000 + 0x240);
uint32_t * LEON3_IFORCE = (uint32_t *) (0x80000000 + 0x208);

/** Pone a 1 el bit del irq_level indicado en el registro de forzado de irq,
 * forzando la interrupción del irq_level indicado.*/
uint8_t leon3_sparc_force_irq(uint8_t irq_level) {
	uint8_t error = 0;
	if (irq_level > 0 && irq_level < 16) {
		// COMPLETAR Poniendo a 1 SOLO el bit de LEON3_IFORCE correspondiente al irq_level
		// irq_level=0 bit menor peso
		// irq_level=15 bit mayor peso
		uint32_t mascara = 1;
		mascara = mascara << irq_level;
		//OK
		*LEON3_IFORCE |= mascara;
	} else
		error = 1;

	return error;

}

/** Pone a 1 el bit del irq_level indicado en el registro de mascara,
 * desenmascarando dicha interrupcion. irq_level(0-15).*/
uint8_t leon3_unmask_irq(uint8_t irq_level) {
	uint8_t error = 0;
	if (irq_level > 0 && irq_level < 16) {
		uint32_t bit = (1 << irq_level); // La mascara del bit a modificar
		*LEON3_ICLEAR = bit;	// clear any pending irq of that level

		// COMPLETAR Poniendo a 1 SOLO el bit de LEON3_IMASK correspondiente al irq_level
		// irq_level=0 bit menor peso
		// irq_level=15 bit mayor peso
		uint32_t mascara = 1;
		mascara = mascara << irq_level;
		//Puedes usar la máscara bit también
		*LEON3_IMASK |= mascara;

	} else
		error = 1;
	return error;

}

/** Pone a 0 el bit del irq_level indicado en el registro de mascara,
 * enmascarando dicha interrupción. irq_level(0-15)*/
uint8_t leon3_mask_irq(uint8_t irq_level) {
	uint8_t error = 0;
	if (irq_level > 0 && irq_level < 16) {

		// COMPLETAR Poniendo a 0 SOLO el bit de LEON3_IMASK correspondiente al irq_level 
		// irq_level=0 bit menor peso
		// irq_level=15 bit mayor peso
		uint32_t mascara = 1;
		mascara = mascara << irq_level;
		mascara = ~mascara;
		//OK
		*LEON3_IMASK &= mascara;
	} else
		error = 1;
	return error;

}
