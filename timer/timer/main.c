/*
 * timer.c
 *
 * Created: 26-03-2026 20:29:44
 * Author : Nandhu Binoy
 */ 

#define F_CPU 16000000
#include <avr/io.h>
/*
void delay1sec()
{
	// Step 1: set the initial value to TCNT0
	TCNT0 = 0;
	// Step 2: Since Timer0, set TCCRA0 and TCCRB0 registers Mode selection
	TCCR0A &= ~(1<<WGM00);
	TCCR0A &= ~(1<<WGM01);
	//TCCR0A &= ~(1<<WGM02);
	TCCR0B &= ~(1<<WGM02);
	// Step 3: Pre-scaling
	TCCR0B |= (1<<CS00);
	TCCR0B &= ~(1<<CS01);
	TCCR0B &= ~(1<<CS02);
	// Step 4: Overflow flag reset
	for (int i = 0; i<62500; i++)
	{
		while(!(TIFR0& (1<<TOV0)));
		{
			TIFR0 |= (1<<TOV0);
		}
	}
}
 */

void delay1sec()
{
	// Step 1: Mode selection (Normal Mode)
	// WGM00 and WGM01 are in TCCR0A, WGM02 is in TCCR0B
	TCCR0A &= ~((1<<WGM00) | (1<<WGM01));
	TCCR0B &= ~(1<<WGM02);

	// Step 2: Pre-scaling (Set to 1024 for a 16MHz clock)
	// 16MHz / 1024 = 15,625 ticks per second
	TCCR0B |= (1<<CS02) | (1<<CS00);
	TCCR0B &= ~(1<<CS01);

	// Step 3: Timing Loop
	// 15,625 total ticks / 256 (8-bit timer) = ~61 overflows
	for (int i = 0; i < 61; i++)
	{
		TCNT0 = 0; // Reset counter
		while(!(TIFR0 & (1<<TOV0))); // WAIT for overflow (Note the '&')
		TIFR0 |= (1<<TOV0);          // Clear the flag by writing 1
	}
}
int main(void)
{
    /* Replace with your application code */
	// set DB2 pin as output
	DDRB |= (1<<DDB2);
	// set PORTB2 initially 0
	PORTB &= ~(1<<PORTB2);

    while (1) 
    {
		PORTB ^= (1<<PORTB2);
		delay1sec();
    }
}

