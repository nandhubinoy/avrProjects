/*
 * timerINT.c
 *
 * Created: 07-04-2026 21:25:13
 * Author : Nandhu Binoy
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 16000000UL
volatile int count = 0;
ISR(TIMER0_OVF_vect)
{
	if(count>=976)
	{
		count = 0;
		PORTB|=(1<<PORTB1);
	}
	else
	{
		PORTB&=~(1<<PORTB1);
		count++;
	}
}
void timer0InterruptInit()
{
	//step 1: Set Global Interrupt Enable
	sei();
	
	//step 2: set Timer0 in normal mode, prescalar 64
	TCCR0A = 0b00000000;
	TCCR0B = 0b00000011;
	
	//step 3: 
	TIMSK0 |= (1<<TOIE0);
	
}

int main(void)
{
	//Make DDB1 & DDB2 as OUTPUT
	DDRB = 0b00000110;
	timer0InterruptInit();
    while (1) 
    {
		
		//Make DDB1 & DDB2 as OUTPUT
		PORTB |= (1<<PORTB2);
		//PORTB&=~(1<<PORTB1);
		
    }
}

