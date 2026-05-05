/*
 * lcdInterface.c
 *
 * Created: 22-04-2026 21:58:24
 * Author : Nandhu Binoy
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

int main(void)
{
	lcd_init();
	lcd_set_cursor(0, 0);
	lcd_print("Hi there!");

	//lcd_set_cursor(1, 0);
	//lcd_print("It works! ");


	while (1)
	{
		float a=25.45;
		
		lcd_set_cursor(1, 0);
		lcd_print_float(a);

	}
}
