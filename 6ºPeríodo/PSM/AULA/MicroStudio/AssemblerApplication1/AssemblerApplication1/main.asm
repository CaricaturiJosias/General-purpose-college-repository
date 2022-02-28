.org 0x00
jmp start ; Vai para o bloco principal

; Comandos que atualizam os registradores responsáveis por causar as interupcoes
atualiza:
	inc		R21 
    ldi		R20,0			; Zera o registrador R20(anterior)				(contagem até 99)
    cpi		R21, 10
    breq	att_R22			; Se for igual a 10 vai para o registrador R22  (centésimos de segundo)
    rjmp	ret_interrupt
att_R22:
    inc		R22 
    ldi		R21,0			; Zera o registrador R21(anterior)				(unidades de segundo)
    cpi		R22, 10
    breq	att_R23			; Se for igual a 10 vai para o registrador R23
    rjmp	ret_interrupt
att_R23:
    inc		R23
	ldi		R22,0			; Zera o registrador R22(anterior)				(dezenas de segundo)
    cpi		R23, 6
    breq	att_R24			; Se for igual a 6 vai para o registrador R24
    rjmp	ret_interrupt
att_R24:			
	inc		R24			
    ldi		R23,0			; Zera o registrador R22(anterior)				(unidades de minuto)
    cpi		R24, 10
    breq	att_f			; Se for igual a 10 zera todos os outros registradores reiniciando a contagem
    rjmp	ret_interrupt
att_f:
    ldi		R20,0			; Zera o registrador R20
    ldi		R21,0			; Zera o registrador R21
    ldi		R22,0			; Zera o registrador R22
    ldi		R23,0			; Zera o registrador R23
    ldi		R24,0			; Zera o registrador R24
    rjmp	ret_interrupt
; Todos os comandos retornam para o bloco interrupt para ser feito o pop de R16

; Bloco Interrupt
.org 0x20
    push R16
        in    R16,SREG
        push R16
            ldi    R16,6        ; Iniciamos contador com 6
            out    TCNT0,R16
            inc		R20
            cpi		R20,99
            breq	atualiza
            ret_interrupt:
        pop R16
        out SREG,R16
    pop R16
    reti

; Bloco Principal
.include "Bib.inc"
start:
    
    ;Config Portas
    sbi		DDRD,0	; PD0 como saida
    sbi		DDRD,1	; PD1 como saida
    sbi		DDRD,2	; PD2 como saida
    sbi		DDRD,3	; PD3 como saida
    sbi		DDRD,4	; PD4 como saida
    sbi		DDRD,5	; PD5 como saida
    sbi		DDRD,6 	; PD6 como saida
    sbi		DDRD,7	; PD7 como saida
    sbi		DDRB,0	; PB0 como saida
    sbi		DDRB,1	; PB1 como saida
    sbi		DDRB,2	; PB2 como saida
    sbi		DDRB,3	; PB3 como saida
	cbi		DDRC,0	; PC0 como entrada
	cbi		DDRC,1	; PC1 como entrada

	sbi		PORTC,0				; Ativa o resistor de pull-interno de PC0
	sbi		PORTC,1				; Ativa o resistor de pull interno de PC1
    store   ADMUX , 0b00101111

    ; Colocando 0 nos registradores
    ldi		R20,0
    ldi		R21,0
    ldi		R22,0
    ldi		R23,0
    ldi		R24,0

	; Verifica S1
    verifica_S1:
		; Esses comandos basicamente exibem o numero 0 nos displays
		set_display		R21,0b00000001 ; Seleciona registrador R21 e display D1
		pause_i_ms	4
		set_display		R22,0b00000010 ; Seleciona registrador R22 e display D2
		pause_i_ms	4
		set_display		R23,0b00000100 ; Seleciona registrador R23 e display D3
		pause_i_ms	4
		set_display		R24,0b00001000 ; Seleciona registrador R24 e display D4
		pause_i_ms	4

		sbic	PINC, 0			; Se apertar o botao S1 ele ativa o timer
		rjmp	verifica_S1
		rjmp	config_timer

	; Configuração do Timer
	config_timer:
		ldi		R16, 0x00		; Modo normal
		out		TCCR0A, R16 

		ldi		R16, 0b0000011  ; Clock de TCNT0
		out		TCCR0B, R16

		ldi		R16, 6			; Iniciamos contador com 6
		out		TCNT0, R16

		ldi		R16, 0x01       ; Habilita timer 0 overflow interrupt
		sts		TIMSK0, R16

		sei						; Habilita chave de interrupcao

		rjmp	verifica_S2

	; Inicia/reinicia o timer
	start_clock:
		ldi    R16, 0x00		; Modo normal
		out    TCCR0A, R16 

		ldi    R16, 0b0000011	; Clock de TCNT0
		out    TCCR0B, R16

	; Verifica S2
	verifica_S2:
		sbis	PINC,1					; Se pressionar botao S2 ele pausa o timer
		rjmp	pausa
		; Esses comandos basicamente exibem os numeros do timer nos displays
		set_display		R21,0b00000001 ; Seleciona registrador R21 e display D1
		pause_i_ms	4
		set_display		R22,0b00000010 ; Seleciona registrador R22 e display D2
		pause_i_ms	4
		set_display		R23,0b00000100 ; Seleciona registrador R23 e display D3
		pause_i_ms	4
		set_display		R24,0b00001000 ; Seleciona registrador R24 e display D4
		pause_i_ms	4
		rjmp	verifica_S2

/* FUNCOES EXTRAS UTILIZADAS */

; Pausa o timer
pausa:     
	push	R16
	ldi		R16,0b00000000	; Colocando TCCR0B em 0 pausa o timer
	out		TCCR0B, R16
	pop		R16
pause_loop:
	; Esses comandos basicamente exibem os numeros do timer nos displays
	set_display		R21,0b00000001 ; Seleciona registrador R21 e display D1
	pause_i_ms	4
	set_display		R22,0b00000010 ; Seleciona registrador R22 e display D2
	pause_i_ms	4
	set_display		R23,0b00000100 ; Seleciona registrador R23 e display D3
	pause_i_ms	4
	set_display		R24,0b00001000 ; Seleciona registrador R24 e display D4
	pause_i_ms	4
	sbic	PINC,0			/* Se o botao S1 for pressionado ele inicia novamente o clock, 
							caso isso nao ocorra ele fica pausado exibindo os mesmos numeros nos displays */
	jmp		pause_loop
	jmp		start_clock 
   
; Set-up da tabela
tabela_R18:
	ldi        ZL,LOW(tabela*2)
	ldi        ZH,HIGH(tabela*2)
	add        ZL,R18
	ldi        R18,0
	adc        ZH,R18
	lpm        R18,Z
	ret

; Tabela de conversao numero-display
tabela:
.db		0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111
