/*
 * LibTeste.inc
 *
 *  Created: 03/09/2021 10:49:36
 *   Author: Gabriel
 */ 
 pause_R16_us:
	nop
.macro pausa_1_ciclo
	nop
.endm

.macro pausa_4_ciclos
	push	R16
	pop		R16
.endm

.macro je
	cpi		@0,@1
	breq	@2
.end

pause_R16_us_loop:
	je		R16, 1, pause_R16_us_end
	dec		R16
	pausa_1_ciclo
	pausa_4_ciclos
	push	R16 ; <- 2 ciclos cada push e pop
	pop		R16
	rjmp pause_R16_us_loop
pause_R16_us_end:
	ret