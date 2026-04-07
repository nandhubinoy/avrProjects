/*
 * phaseCrct_pwm.c
 *
 * Created: 04-04-2026 20:45:32
 * Author : Nandhu Binoy
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
void fastPWMInit()
{
	//1. PD6 as output
	DDRD |= (1<<DDD6);
	//2. phase correct PWM mode
	TCCR0A |= (1<<WGM00);
	TCCR0A &=~(1<<WGM01);
	TCCR0B &=~(1<<WGM02);
	
	//3. If using prescalar as 8
	TCCR0B &= ~(1<<CS02);
	TCCR0B |= (1<<CS01);
	TCCR0B &= ~(1<<CS00);
	
	//4. Set as non-inverting mode
	TCCR0A |= (1<<COM0A1);
	TCCR0A &= ~(1<<COM0A0);
	// CR0A to be loaded with 128
	OCR0A = 128;
}

int main(void)
{
    fastPWMInit();
	DDRD |= (1<<DDD0)|(1<<DDD1); // Made D0,D1 as output
	PORTD |=(1<<PORTD0);
	PORTD &=~(1<<PORTD1);
	
	//Set PINC1 as input
	PORTC &= ~(1<<PORTC1);
	int switchpresscount = 0;
    while (1) 
    {
		if(!(PINC & (1<<PINC1)))
		{
			_delay_ms(100);
					if(!(PINC & (1<<PINC1)))
					{
			switchpresscount++;
			switch (switchpresscount)
			{
				case 1: OCR0A = 0;
						break;
				case 2: OCR0A = 64;
						break;
				case 3: OCR0A = 128;
						break;
			    case 4: OCR0A = 255;
						break;
				default: switchpresscount = 0;
						
			}
					}
		}
		
    }
}

