;
; 2021-08-21-Lista.asm
;
; Created: 21/08/2021 09:14:29
; Author : Gabriel
;
;	Arduino UNO
;	S1 = PD4 = Entrada 4
;	S2 = PD3 = Entrada 3
;	Função: ~S1 NAND S2 === S1 OR ~S2
;   LED1 apagado somente quando S1 = PD4 = 0 / S2 = PD3 = 1
; i/o config
start:	
    CBI		DDRD, 3
	CBI		DDRD, 4
	SBI		DDRD, 6
	SBI		PORTD, 3
	SBI		PORTD, 4

volta:
	SBIC	PIND, 3		;SE PIND3 = S2 = 0, APAGA
	rjmp	acende
	SBIS	PIND, 4		;SE PIND4 = S1 = 1, APAGA
	rjmp	acende
	CBI		PORTD, 6	; APAGA
	rjmp	volta

acende:
	SBI		PORTD, 6	; ACENDE
	rjmp	volta
