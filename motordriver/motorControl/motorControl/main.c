/*
 * motorControl.c
 *
 * Created: 19-03-2026 20:25:20
 * Author : Nandhu Binoy
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	DDRD = DDRD | (1<<DDD1) | (1<<DDD2);
    while (1) 
    {
		PORTD = PORTD | (1<<PD1);
		PORTD = PORTD & ~(1<<PD2);
		_delay_ms(5000);
		
		PORTD = PORTD & ~(1<<PD1);
		PORTD = PORTD | (1<<PD2);
		_delay_ms(5000);
    }
}

