;
; 2021-09-17-Aula_TesteSerial.asm
;
; Created: 17/09/2021 09:52:01
; Author : Gabriel
;

.macro store
	LDI		R16, @1
	STS		@0, R16
.endm
; Replace with your application code
start:
	;configura baudrate
	store	UBRR0L, 0x00
	store	UBRR0H, 0x68

	;Config USART0
	store	UCSR0A, 0b00100000
	store	UCSR0B, 0b00011000
	store	UCSR0C, 0b00000110

fim:	
	rcall	rx_R16
	inc		R16
	rcall	tx_R16
	rjmp	fim

tx_R16:
	push	R16
tx_R16_loop:
	;Fica aguarndando bit 5 de UCSR0A estar ligado que significa que ele pode receber dados
	LDS		R16, UCSR0A
	SBRS		R16, UDRE0 ; UDRE0 é a mesma coisa que 5
	rjmp	tx_R16_loop
	pop		R16
	sts		UDR0, R16
	ret

	;aguarda um valor ser recebido da porta serial USART0 e coloca o valor em r16
rx_R16:
rx_R16_loop:
	LDS		R16, UCSR0A
	SBRS	R16, RXC0 ; RXC0 é a mesma coisa que 7
	rjmp	rx_R16_loop
	;Le o valor de UDR0 e colocao em r16
	lds		R16, UDR0
	ret		

	;	para casa
	;	Alterar o baudrate para 9600bps
	;	Iniciar a execução imprimindo uma string qualquer e então faz o que tem que fazer