/*
 * adc.c
 *
 * Created: 01-05-2026 20:26:11
 *  Author: Nandhu Binoy
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include "adc.h"

void adcInit()
{
	//Step1: Make 1.1V as Aref and ADC0 as Input for ADC
	ADMUX |=  (1<<REFS0);	// (1<<REFS1) |
	//ADMUX &= ~(1<<REFS1) ;
	//ADMUX &= ~(1<<MUX3) & ~(1<<MUX2) & ~(1<<MUX1) & ~(1<<MUX0);
	
	// Step 2: Enable ADC and set Prescaler to 128
	ADCSRA |= (1 << ADEN);
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	
}
uint16_t adcRead(uint8_t channel)
{
	//channel&=(0x07);
	// Better to set MUX or select the channels in the read(),
	//because channel is provided by the user.
	//ADMUX &= (0xF8)|channel;
	ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);
	ADCSRA|=(1<<ADSC);	// Start conversion
	while(ADCSRA&(1<<ADSC));
	return ADC;
#if 0
	// Clear lower 4 bits (MUX) and keep upper 4 bits (REFS/ADLAR)
	ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);
	
	ADCSRA |= (1 << ADSC);           // Start conversion
	while(ADCSRA & (1 << ADSC));     // Wait for hardware to clear ADSC
	return ADC;                      // Return 10-bit result
#endif

	/*
	while(!(ADCSRA&(1<<ADSC)))
	{
		return ADC;
	}
	*/
	
}
