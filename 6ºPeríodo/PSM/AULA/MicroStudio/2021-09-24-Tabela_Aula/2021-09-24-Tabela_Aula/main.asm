;
; 2021-09-24-Tabela_Aula.asm
;
; Created: 24/09/2021 10:41:21
; Author : Gabriel
;


; Replace with your application code
start:
	ldi		r16, 4
	push	r16
	rcall	tabela_r16
	pop		r16
	rjmp	start

tabela_r16:
	ldi		ZL, LOW(tabela*2)
	ldi		ZH, HIGH(tabela*2)
	add		ZL, R16
	lpm		r16, Z
	adc		ZH, R16
	ret

tabela: 
	.db 0x10, 0x30, 0x52, 0x080, 0x4B, 0xFC, 0x00, 0x00
