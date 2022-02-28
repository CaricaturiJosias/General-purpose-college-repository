.macro	store
	ldi		R16,@1
	sts		@0,R16
.endm

.macro set_display
	; Apaga os displays
	push	R17
	ldi		R17,0
	out		PORTB,R17

	; Conversao do R18 nos valores da tabela
	mov		R18,@0								; Aqui sao colocados valores da tabela para os registradores, para o a continuação da contagem no timer
	call	tabela_R18
	ldi		R17,@1								; Aqui sao colocados valores em binario, indicando qual display vai ser ligado 
	out		PORTB,R17

	; Carrega os valores convertidos nos segmentos dos displays
	out		PORTD,R18
	pop		R17
.endm

; Pausas

; Pausa 1 ciclo
.macro pausa_1_ciclo
	nop
.endm

; Pausa 4 ciclos
.macro pausa_4_ciclos
	push	R16	; <- 2 ciclos
	pop		R16 ; <- 2 ciclos
.endm

; Je
.macro	je
	cpi		@0,@1
	breq	@2
.endm

; Jne
.macro	jne
	cpi		@0,@1
	brne	@2
.endm

; Pausa R16 us
.macro pause_R16_us
	push	R16
	rcall	pause_R16_us_
	pop		R16
.endm

; Pausa i us
.macro	pause_i_us
	push	R16
	ldi		R16,@0
	rcall	pause_R16_us_
	pop		R16
.endm

; Pausa i ms
.macro pause_i_ms
	push	R16
	ldi		R16,@0
	rcall	pause_R16_ms_
	pop		R16
.endm

pause_R16_us_:
	nop
pause_R16_us_loop_:
	je		R16, 1, pause_R16_us_end_
	dec		R16
	pausa_4_ciclos
	pausa_4_ciclos
	pausa_1_ciclo
	pausa_1_ciclo
	pausa_1_ciclo
	rjmp	pause_R16_us_loop_
pause_R16_us_end_:
	ret

pause_R16_ms_:
pause_R16_ms_loop_:
	pause_i_us	250
	pause_i_us	250
	pause_i_us	250
	pause_i_us	249
	pausa_1_ciclo
	je		R16,1,pause_R16_ms_fim_
	dec		R16
	pausa_4_ciclos
	pausa_4_ciclos
	pausa_1_ciclo
	pausa_1_ciclo
	rjmp	pause_R16_ms_loop_
pause_R16_ms_fim_:
	ret
