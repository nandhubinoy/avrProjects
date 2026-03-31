/*
 * fast_pwm.c
 *
 * Created: 31-03-2026 20:59:59
 * Author : Nandhu Binoy
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
void fastPWMInit()
{
	//1. PD6 as output
	DDRD |= (1<<DDD6);
	//2. Fast PWM mode
	TCCR0A |= (1<<WGM00) | (1<<WGM01);
	TCCR0B &= ~(1<<WGM02);
	//3. If using prescalar as 64
	TCCR0B &= (1<<CS02);
	TCCR0B |= (1<<CS00)|(1<<CS01);
	//4. Set as non-inverting mode
	TCCR0A |= (1<<COM0A1);
	TCCR0A &= ~(1<<COM0A0);
	// CR0A to be loaded with 128
	OCR0A = 0;
}

int main(void)
{
    fastPWMInit();
    while (1) 
    {
		for (int i = 0; i<255; i++)
		{
			OCR0A = i;
			_delay_ms(10);
		}
    }
}

