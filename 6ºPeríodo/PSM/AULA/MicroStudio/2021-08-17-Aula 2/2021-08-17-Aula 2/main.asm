;
; 2021-08-17-Aula 2.asm
;
; Created: 17/08/2021 09:50:02
; Author : Gabriel
;


; Replace with your application code
start:
	cbi		DDRB,4 ; Considera padrão como cleared/0, então
				   ; não precisaria dessa linha de comando
	sbi		DDRB,5		; PB5 Saída
	sbi		PORTB,4		;<- PB4 com pull up
volta:
	sbic	PINB,4		; Testa PB4
    rjmp apaga_led		; Se PB4=0, salta para apaga_led
	sbi		PORTB,5		; Se PB4=1, liga o led em PB5
	rjmp volta
apaga_led:
	cbi		PORTB,5
	rjmp volta