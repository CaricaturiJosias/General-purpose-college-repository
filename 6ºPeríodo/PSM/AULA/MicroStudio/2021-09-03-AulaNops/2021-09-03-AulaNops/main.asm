;
; 2021-09-03-AulaNops.asm
;
; Created: 03/09/2021 10:15:04
; Author : Gabriel
;

rjmp start

.include "LibTeste.inc"

; Replace with your application code
start:
	nop
	nop
	ldi		R16, 2
	rcall	pause_R16_us
	rjmp	start    

