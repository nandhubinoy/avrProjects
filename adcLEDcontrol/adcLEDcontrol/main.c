/*
 * adcLEDcontrol.c
 *
 * Created: 30-04-2026 20:26:04
 * Author : Nandhu Binoy
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include "adc.h"
#include <util/delay.h>


int main(void)
{
	adcInit();
	float digitalValue;
	
	//Make D0-D4 pins as 'Output'
	DDRD = DDRD | (0x01 << DDD0) | (0x01 << DDD1) | (0x01 << DDD2)
		| (0x01 << DDD3) | (0x01 << DDD4);
	//PORTD |= (1<<PORTD0)|(1<<PORTD1)|(1<<PORTD2)|(1<<PORTD3)|(1<<PORTD4);

   while (1)
   {
	   uint16_t val = adcRead(0); // ADC0 (PC0) ????????? ?????

	   //PORTD &= ~0x1F; // ????? LED-??? ????? ??? ??????? (Sticky ???????????)

	   if (val < 200)       PORTD |= (1 << PORTD4);
	   else if (val < 400)  PORTD |= (1 << PORTD1);
	   else if (val < 600)  PORTD |= (1 << PORTD2);
	   else if (val < 800)  PORTD |= (1 << PORTD3);
	   else                 PORTD |= (1 << PORTD4);
	   
	   _delay_ms(50);
   }
	return 0;
}

