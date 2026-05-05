/*
 * externalINT.c
 *
 * Created: 09-04-2026 20:59:30
 * Author : Nandhu Binoy
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

void externalINT_Init()
{
	//step1: Enable Global buffer
	sei();
	//step2: Configure EIMSK for INT0
	EIMSK |= (1<<INT0);
	//step3: Configure EICRA for rising edge
	EICRA |= ((1<<ISC00)|(1<<ISC01));
	
}
ISR(INT0_vect)
{
	PORTB ^= (1<<PORTB5);
}
int main(void)
{
	// Directional Data Buffer should be input for INT0
	DDRD &= ~(1<<DDD2);
	// Directional Data Buffer should be output for LED
	DDRB |= (1<<DDB5);
	PORTB &= ~(1<<PORTB5);
	externalINT_Init();
    while (1) 
    {
				
    }
}


#if 0
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

#define	LED PB5
/*ISR for external interrupt INT0*/
ISR(INT0_vect)
{
	//toggle led function
	PORTB ^= (1 << LED);
}
/*external Interrupt INT0 configuration*/
void external_interrupt_config()
{
	//step 1: PD2 config as input for External Interrupt
	DDRD &= ~(1 << DDD2);
	//step 2: enabling INT0
	EIMSK |= (1 << INT0);
	//step 3: configuring the interrupt trigger : rising edge
	EICRA |= ((1 << ISC01) | (1 << ISC00));
	//step 4: enabling sei() - global interrupt enable
	sei();
}
/*gpio configurations*/
void gpio_init()
{
	DDRB |= (1 << DDB5);
}
int main(void)
{
	//calling gpio initialization / configuration function
	gpio_init();
	//calling external interrupt configuration function
	external_interrupt_config();
	
	while (1)
	{
		
	}
}

#endif


