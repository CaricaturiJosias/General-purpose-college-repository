; ------------------------------- ;
;|            ALUNOS             |;
; ------------------------------- ;
;|                               |;
;| - Gabriel Vitor Cezario       |;
;| - Ricardo Godoi Kurashiki     |;
;|                               |;
; ------------------------------- ;

org 100h

jmp start

; ---------- MACROS ------------- ;

macro jmpline
     PUSH AX
     PUSH DX
     
     mov AH, 2
     
     mov DL, 10
     int 21h  
     
     mov DL, 13
     int 21h 
     
     pop DX
     pop AX
endm

macro prints s1
    PUSH AX
    PUSH DX
    
    mov AH, 9
    mov DX, offset s1
    int 21h
    
    POP DX
    POP AX
endm

macro input var
    PUSH AX
    PUSH DX
    
    mov AH, 0Ah
    mov DX, offset var
    int 21h
    
    POP DX
    POP AX
endm
; ---------- PROGRAMA PRINCIPAL ------------- ;

start:
   call pega_base
 
   jmpline
   jmpline
   
   call pega_valor
    
   jmpline
   jmpline
   
   call converte_valor
   
   ret
   

; ---------- BASE ------------- ;

pega_base:
    prints pergunta_base
    input base
    call confere_base
        
    ret                                 
 
confere_base:
    mov CX, 0001h
 
    mov [10h], 0     ; Memoria responsavel por armazenar valor da base     
    call conv_base
    loop pega_base
    
    call verifica_base
    loop pega_base 
    
    ret

; ---------- VALIDACOES BASE ------------- ;

conv_base:
    PUSH AX    
    
    mov SI, base
    mov AX, [SI+2]
    cmp AH, 0Dh
    je conv_base_um         ; Caso o usuario tenha entrado um valor (ex: 2)
    cmp AL, 30h
    je conv_dois_para_um    ; Caso o usuario tenha entrado dois valores (ex: 02)
    cmp AL, 31h
    ja conv_base_error
conv_base_dois:      
    sub AH, 30h
    mov [10h], AH
    add [10h], 10
    
    POP AX
    mov CX, 0001h  
    ret
conv_dois_para_um:
    mov AL, AH
conv_base_um:
    sub AL, 30h
    mov [10h], AL
    
    POP AX
    mov CX, 0001h
    ret
conv_base_error:
    POP AX
    mov [10h], 0000h
    jmp print_base_invalida

verifica_base:    
    mov BX, [10h]
    
    cmp BL, 02h
    jb print_base_invalida
    cmp BL, 10h
    ja print_base_invalida
    
    mov CX, 0001h
    ret
    
print_base_invalida:
    jmpline
    prints base_invalida
    jmpline
    mov CX, 0002h
    ret

; ---------- VALOR ------------- ;

pega_valor:
    prints pergunta_valor
    input valor
    call confere_valor
        
    ret                                 
 
confere_valor:    
    mov CX, 0001h
 
    mov [20h], 0     ; Memoria responsavel por armazenar o valor inserido  
    mov [21h], 0
    mov [30h], 0     ; Memoria responsavel por armazenar o tamanho da String do numero
         
    call tamanho_valor
    
    call valida_valor
    loop pega_valor
    
    call conv_valor
    loop pega_valor
    
    
    ret

; ---------- VALIDACOES VALOR ------------- ;
    
tamanho_valor:

    PUSH BX
    
    mov SI, valor
    mov BX, 0
tamanho_valor_loop:
    mov BH, [SI+2]
    cmp BH, 0Dh             ; Indica o fim da String   
    je tamanho_valor_fim
    inc SI
    inc BL
    jmp tamanho_valor_loop
tamanho_valor_fim:
    mov [30h], BL
      
    POP BX  
    ret

valida_valor:    
    mov SI, valor
    mov BX, 0
    mov CX, [30h]
valida_valor_loop:
    mov BH, [SI+2]
    cmp BH, 39h
    ja print_valor_invalido
    cmp BH, 30h
    jb print_valor_invalido
    inc SI
    loop valida_valor_loop
valida_valor_fim:
    mov CX, 0001h
    ret       

; 65535
; ((((6)*10 + 5)*10 + 5)*10 + 3)*10 + 5
;     CX=5    CX=4    CX=3    CX=2   CX=1

; se CX == 1, soma apenas com o valor ja salvo
; senao, multiplica por 10 e soma com o valor ja salvo

conv_valor:
    PUSH AX
    PUSH BX
    PUSH CX
    
    mov SI, valor
    mov [20h], 0000h
    mov CX, [30h]
conv_valor_loop:
    mov BX, 10
    mov AX, 0           
    mov AL, [SI+2]      
    sub AL, 30h         
    cmp CX, 1           
    ja conv_valor_mul
    je conv_valor_fim
conv_valor_mul:
    add AX, [20h]
    jc conv_valor_error
           
    mul BX
    jc conv_valor_error
                  
    mov [20h], AX       
    
    inc SI
    loop conv_valor_loop
conv_valor_fim:
    add [20h], AX
    jc conv_valor_error
    
    POP CX
    POP BX
    POP AX
    
    mov CX, 0001h
    
    ret
conv_valor_error:
    POP CX
    POP BX
    POP AX
     
    mov [20h], 0000h
      
    jmp print_valor_invalido

print_valor_invalido:
    jmpline
    prints valor_invalido
    jmpline
    mov CX, 0002h
    ret

; ---------- CONVERSAO ------------- ;

; Valor de entrada em decimal (((Ax10 +B)x10 + C)x10 + D)  
; Converter na base de saida  (((Xxba +Y)xba + Z)xba + W)    

; Quantidade de repeticoes = (base/2), se maior que 1,
; incrementa CX e faz base/2 denovo ate o DL ser 1         

repeticoes:
    push DX
    div 

converte_valor:
    mov [40h], 0000h
    mov SI, [40h]       ; Memoria do valor convertido
    
    mov BX, [10h]       ; Base escolhida
    mov AX, [20h]       ; Valor escolhido
                        
    cmp BX, 10          ; Compara se a base e maior ou menor que 10
    ja  converte_valor_multiplica_loop    ; Metodo se maior: multiplicacao
    jb  converte_valor_divide_loop        ; Metodo se menor; divisao
    
converte_valor_divide_loop:
    mov DX, 0
    div BX
    cmp DL, BX
    ja   resto_maiorQbase
    jbe  resto_menorQbase 
converte_valor_divide_loop_continuacao:
    mov [SI], DL
    inc SI
    jmp converte_valor_divide_loop  
    
resto_maiorQbase:
    add DL, 37h
    jmp converte_valor_loop_continuacao
    
resto_menorQbase:
    add DL, 30h
    jmp converte_valor_loop_continuacao       

; ---------- MISC ------------- ;
       
pergunta_base: db "Insira a base do valor (2 - 16): $"

pergunta_valor: db "Insira o valor em base decimal (0 - 65535): $" 

base_invalida: db "A base inserida nao eh valida!$"

valor_invalido: db "O valor inserido nao eh valido!$"
                                          
valor: db 6, 0, 3 dup('$'), '$'

base: db 3, 0, 3 dup('$'), '$' 
