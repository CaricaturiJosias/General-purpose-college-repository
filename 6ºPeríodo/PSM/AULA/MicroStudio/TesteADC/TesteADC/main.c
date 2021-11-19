/*
 * TesteADC.c
 *
 * Created: 11/11/2021 14:35:25
 * Author : Gabriel
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

void config(){
	ADMUX	= 0x60;
	ADCSRA	= 0x87; 
}

int main(void)
{
    config();
	DDRD	= 0xFF;
	PORTD	= 0xFF;
    DDRB	= 0xFF;
	PORTB	= 0xFF;
	
	while (1) 
    {
		_delay_us(10);
		ADCSRA	= 0xC7;
		while(ADSC == 1){}
		PORTD = ADCH;
	}
}

