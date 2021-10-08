	rjmp start
	
.org 0x20
	PUSH	R16
		in		R16, SREG
		push	R16
			ldi		R16, 6
			out		TCNT0, R16
		pop		R16
		out		SREG, R16
	POP		R16
	reti

start:
	ldi		R16,0x00	; MODO NORMAL
	out		TCCR0A,R16

	ldi		R16,6		; INICIAMOS CONTADOR COM 6
	out		TCNT0,R16

	ldi		R16,0b00000011	; Prescaler DIV 64
	out		TCCR0B,R16

	ldi		R16, 0x01
	sts		TIMSK0, R16

	sei		; Habilita a "chave geral de interrupção"

loop:
	rjmp	loop

