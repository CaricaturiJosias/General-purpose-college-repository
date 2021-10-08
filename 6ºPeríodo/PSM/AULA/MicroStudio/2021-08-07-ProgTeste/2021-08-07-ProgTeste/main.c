/*
 * 2021-08-07-ProgTeste.c
 *
 * Created: 07/08/2021 10:30:51
 * Author : Gabriel
 */ 

#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB = 0B00111111;
	DDRD = 0B11111100;
	/* Replace with your application code */
    while (1) 
    {
		PORTB = 0B00111111;
		PORTD = 0B11111100;
		_delay_ms(1000);
		PORTB = 0B00000000;
		PORTD = 0B00000000;
		_delay_ms(1000);
    }
}

