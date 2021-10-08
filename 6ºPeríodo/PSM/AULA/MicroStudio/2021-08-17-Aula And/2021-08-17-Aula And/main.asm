;
; 2021-08-17-Aula And.asm
;
; Created: 17/08/2021 11:02:28
; Author : Gabriel
;


; Replace with your application code
config:
	CBI		DDRB, 3
	CBI		DDRB, 4
	SBI		DDRB, 5
volta:
	SBIC	PINB, 3
	rjmp 	Reset	;Se PB3 = 1 -> vai para RESET
	SBIC	PINB, 4
	rjmp 	Reset	;Se PB4 = 1 -> vai para RESET
	SBI		PORTB,5
	rjmp	volta
Reset: 
	CBI		PORTB, 5
	rjmp PB3
    