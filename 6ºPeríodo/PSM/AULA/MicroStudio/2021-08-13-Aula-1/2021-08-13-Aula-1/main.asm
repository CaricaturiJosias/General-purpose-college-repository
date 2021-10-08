;
; 2021-08-13-Aula-1.asm
;
; Created: 13/08/2021 10:22:06
; Author : Gabriel
;


; Replace with your application code (
; Sobre a PORTAB.B5
;  DDRB = Se o bit estiver em 1, este bit é saída, 0 vira entrada (Ex: DDRB = 0B00100000 -> BIT 5 na porta B)
;  PORTB = sao os bits de saída (se colocar 1, o pino vai para 1)
;  
inicio:
    sbi		DDRB, 5		; Estou ligando bit 5 da DDRB (PB5 seja saída)
rotulo:
	sbi		PORTB, 5	; Coloco o pino PB5 do chip em set (Acende o led)
	cbi		PORTB, 5	; Coloco o pino PB5 do chip em reset (Apaga o led)
	rjmp	rotulo	