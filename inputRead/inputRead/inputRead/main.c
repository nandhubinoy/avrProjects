/*
 * inputRead.c
 *
 * Created: 19-03-2026 20:56:17
 * Author : Nandhu Binoy
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>

#define IS_PIN_HIGH(reg, bit) (reg & (1 << bit))
int main(void)
{
	DDRD = DDRD & ~(1<<DDD3);
	DDRC = DDRC | (1<<DDC5);
    /* Replace with your application code */
    while (1) 
    {
	/*		if(PIND&(1<<PIND3))
			{
				PORTC = PORTC | (1<<PC5);
			}
			else
			{
				PORTC = PORTC & ~(1<<PC5);
			} */
			/*	if(PIND3)
				{
					PORTC = PORTC | (1<<PC5);
				}
				else
				{
					PORTC = PORTC & ~(1<<PC5);
				} */
			if(!IS_PIN_HIGH(PIND,PIND3))
				{
					PORTC = PORTC | (1<<PC5);
				}
				else
				{
					PORTC = PORTC & ~(1<<PC5);
				}
    }
}

