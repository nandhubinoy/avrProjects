/*
 * motorControl.c
 *
 * Created: 19-03-2026 20:25:20
 * Author : Nandhu Binoy
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
// rotate a dc motor in colckwise and anticlockwise fro the given delay

int main(void)
{
	DDRD = DDRD | (1<<DDD1) | (1<<DDD2);
    while (1) 
    {
		PORTD = PORTD | (1<<PD1);
		PORTD = PORTD & ~(1<<PD2);
		_delay_ms(10000);
		
		PORTD = PORTD & ~(1<<PD1);
		PORTD = PORTD | (1<<PD2);
		_delay_ms(10000);
    }
}

