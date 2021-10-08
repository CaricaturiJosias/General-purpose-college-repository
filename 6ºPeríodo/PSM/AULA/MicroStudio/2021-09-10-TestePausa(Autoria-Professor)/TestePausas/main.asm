	rjmp	start

.include "minha_lib.inc"

start:
	nop
	nop
	nop
	nop
	ldi		R16,2
	rcall	pause_R16_us
    rjmp start


