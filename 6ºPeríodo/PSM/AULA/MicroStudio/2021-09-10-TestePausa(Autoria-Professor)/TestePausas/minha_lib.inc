
.macro pausa_1_ciclo
	nop
.endm

.macro pausa_4_ciclos
	push	R16	; <- 2 ciclos
	pop		R16 ; <- 2 ciclos
.endm

.macro	je
	cpi		@0,@1
	breq	@2
.endm

.macro	jne
	cpi		@0,@1
	brne	@2
.endm

 pause_R16_us:
	push	R16
	nop
pause_R16_us_loop:
	je		R16, 1, pause_R16_us_end
	dec		R16
	pausa_4_ciclos
	pausa_4_ciclos
	pausa_1_ciclo
	pausa_1_ciclo
	pausa_1_ciclo
	rjmp	pause_R16_us_loop
pause_R16_us_end:
	pop		R16
	ret
pause_R16_ms:
    push    R16

pause_R16_ms_loop:
    pause_i_us    250
    pause_i_us    250
    pause_i_us    250
    pause_i_us    249
    je        R16,1,pause_R16_ms_fim
    dec        R16
    rjmp    pause_R16_ms_loop

pause_R16_ms_fim:
    pop        R16
    ret