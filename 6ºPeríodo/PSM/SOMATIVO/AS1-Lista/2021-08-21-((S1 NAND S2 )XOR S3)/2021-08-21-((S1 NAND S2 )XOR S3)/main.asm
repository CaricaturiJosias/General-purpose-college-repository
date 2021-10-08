;
; 2021-08-21-((S1 NAND S2 )XOR S3).asm
;
; Created: 21/08/2021 14:36:24
; Author : Gabriel
;
; Replace with your application code
; S1 = PD2 = 2
; S2 = PD3 = 3
; S3 = PD4 = 4
; LED1 = PD6 = 6
; LED2 = PD5 = 5
; Função = (S1 NAND S2) XOR S3
start:
	CBI		DDRD, 2
	CBI		DDRD, 3
	CBI		DDRD, 4
	SBI		DDRD, 5
	SBI		DDRD, 6
	SBI		PORTD, 2
	SBI		PORTD, 3
	SBI		PORTD, 4

volta:
	SBIS	PIND, 4		;SE PD4 = 0 (pressionado), vai para Spos 
	rjmp	Spos1
	SBI		PORTD, 6

	SBIS	PIND, 2		;SE PD2 = S1 = 0 (apertado/aterrado), volta, senão vai para acende 
	rjmp	reset
	rjmp	acende
	; vai ser separado em SPos1 e SPos2 pois não sei usar a função de comparação em port
	; da mesma porta

Spos1: ;ver se ambos são negativos, se PD3 é 0 e PD2 é 1, reseta, se PD3 é 1, Spos2
	SBIS	PIND, 3
	rjmp	Spos2	
	CBI		PORTD, 6
	SBIS	PIND, 2
	rjmp	reset
	rjmp	acende
	
Spos2: ;	Só vai vir aqui se PD3 for 0 (pressionado), testa PD2 = 1 só
	SBI		PORTD, 6
	SBIC	PIND, 2
	rjmp	reset
	 
acende:
	SBI		PORTD, 5
	rjmp	volta

reset:
	CBI		PORTD, 5
	rjmp	volta