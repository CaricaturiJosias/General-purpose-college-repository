#include "../../../common/hal.h"
#include <avr/io.h>
#define F_CPU	16000000	
#include <util/delay.h>

void InitHAL(){
	DDRB = (1<<5); // LED1 como saida (B5)
}

void LED1(boolean s){
	if (s)
		PORTB = (1<<5);
	else
		PORTB = (0<<5);
}

void Pausa1s(){
	_delay_ms(100);
}