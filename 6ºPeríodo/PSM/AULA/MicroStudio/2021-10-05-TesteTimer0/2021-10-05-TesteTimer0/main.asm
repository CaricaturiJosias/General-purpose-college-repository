;
; 2021-10-05-TesteTimer0.asm
;
; Created: 05/10/2021 10:29:46
; Author : Gabriel
;


; Replace with your application code
start:
	ldi		R16, 0X00	;modo normal, mov/std/out
	out		TCCR0A, R16

	ldi		R16, 240	;contador iniciando com 240
	out		TCNT0, R16

	ldi		R16, 0b00000001	;clock de tcnt0
	out		TCCR0B, R16		

loop:
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	rjmp	loop