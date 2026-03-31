/*
 * trafficLight.c
 *
 * Created: 22-03-2026 15:40:10
 * Author : Nandhu Binoy
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

		void STOP()
		{
			PORTB |= (1<<PORTB1);
			PORTB &= ~(1<<PORTB2);
			PORTB &= ~(1<<PORTB3);
		}
		void WAIT()
		{
			PORTB |= (1<<PORTB2);
			PORTB &= ~(1<<PORTB1);
			PORTB &= ~(1<<PORTB3);
		}
		void PRCEED()
		{
			PORTB |= (1<<PORTB3);
			PORTB &= ~(1<<PORTB1);
			PORTB &= ~(1<<PORTB2);
		}

int main(void)
{
	//Make GPIO pins as Output
	DDRB = DDRB | (1<<DDB1) | (1<<DDB2) | (1<<DDB3);
    /* Replace with your application code */
    while (1) 
    {
		STOP();
		_delay_ms(5000);
		WAIT();
		_delay_ms(2000);
		PRCEED();
		_delay_ms(5000);
    }
	return 0;
}

