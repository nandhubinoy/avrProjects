/*
 * ledblink.c
 *
 * Created: 18-03-2026 22:59:40
 * Author : Nandhu Binoy
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#if 0
int main(void)
{
	//DDRD = 0b00111111; // making Data Directional Register as output
	DDRD = DDRD | (0x01 << DDD0) | (0x01 << DDD1) | (0x01 << DDD2)
	| (0x01 << DDD3) | (0x01 << DDD4) | (0x01 << DDD5);
	/* Replace with your application code */
	while (1)
	{
		PORTD = PORTD | (1<<PD0) | (1<<PD2);
		_delay_ms(1000);
		PORTD = PORTD & ~(1<<PD0) & ~(1<<PD2);
		//PORTD = PORTD | (1<<PD1) |  (1<<PD3);
		_delay_ms(1000);
	}
}
#endif

int main()
{
	DDRB |= (1<<DDB5);
	while(1)
	{
		PORTB |= (1<<PORTB5);
		//_delay_ms(1000);
		//PORTB &= ~(1<<PORTB5);
		//_delay_ms(1000);
	}
	return 0;
}

