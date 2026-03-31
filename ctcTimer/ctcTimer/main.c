/*
 * ctcTimer.c
 *
 * Created: 29-03-2026 15:53:44
 * Author : Nandhu Binoy
 */ 
#define F_CPU 16000000
#include <avr/io.h>
void delay1sec()
{
	for(int i = 0; i<61; i++)
	{
		while(!(TIFR0 & (1<<TOV0)));
			TIFR0 |= (1<<TOV0);
	}
}
void timerInit()
{
	TCNT0 = 0;				// Load initial value 
	TCCR0A &= ~(1<<WGM01);	// WAVEFORM mode generation
	TCCR0A &= ~(1<<WGM00);
	TCCR0B &= ~(1<<WGM02);
	// Clock select
	TCCR0B |= (1<<CS00) | (1<<CS02);
	TCCR0B &= ~(1<<CS01);
	
}
void ctc_timerInit()
{
		TCNT0 = 0;				// Load initial value
		TCCR0A &= ~(1<<WGM01);	// WAVEFORM mode generation
		TCCR0A &= ~(1<<WGM00);
		TCCR0B &= ~(1<<WGM02);
		// Clock select
		TCCR0B |= (1<<CS00) | (1<<CS02);
		TCCR0B &= ~(1<<CS01);
}
void pinInit()
{
	DDRB |= (1<<DDB2);		// Set the DDR
	PORTB &= ~(1<<PORTB2);	// Set initially zero
}

int main(void)
{
	pinInit();
	//timerInit();
	ctc_timerInit();
    /* Replace with your application code */
    while (1) 
    {
		PORTB ^= (1 << PB2);
		delay1sec();
    }
}

