#include "leon3_bprint.h"

int8_t leon3_print_string(char* str){
	int8_t error=0;
	int i =0;
	while ((str[i] !='\0') && (error == 0)){
		error += leon3_putchar(str[i]);
		i++;
	}
	return (error);
}


int8_t leon3_print_uint8(uint8_t i){
	int8_t error=0;
	uint8_t aux;
	int8_t first_digit=0;
	aux=100;

	if(i==0)
		leon3_putchar('0');
	else{
		while(aux&&(!error)){
			uint8_t digit;

			digit=i/aux;
			i-=aux*digit;
			aux=aux/10;
			if(first_digit||digit){
				error=leon3_putchar('0'+digit);
				first_digit=1;
			}
		}
	}
	return error;
}

int8_t leon3_print_uint32(uint32_t i){
	int8_t error=0;
	int8_t first_digit=0;
	uint32_t aux;

	aux=1000000000;

	if(i==0)
		leon3_putchar('0');
	else{
		while(aux&&(!error)){
			uint8_t digit;
			digit=i/aux;
			i-=aux*digit;
			aux=aux/10;
			if(first_digit||digit){
				error=leon3_putchar('0'+digit);
				first_digit=1;
			}
		}
	}
	return error;
}
