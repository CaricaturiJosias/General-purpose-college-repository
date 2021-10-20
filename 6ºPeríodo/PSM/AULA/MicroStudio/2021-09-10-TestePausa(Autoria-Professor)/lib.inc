.macro insere
	push	R16
	ldi		R16, @0
	sts		@1, R16
	pop		R16
.endm