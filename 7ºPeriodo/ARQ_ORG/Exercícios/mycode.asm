
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

jmp comeco
 
; Pula linha
macro pulaLinha
     PUSH AX
     PUSH DX
     
     mov AH, 2
     
     mov DL, 10
     int 21h  
     
     mov DL, 13
     int 21h 
     
     pop DX
     pop AX
.endm 

comeco:
   ; Pergunta numero
   mov AH, 9
   mov dx, offset perguntaNumero
   int 21h    
   
   ; Pega numero
   mov dx, offset valor
   mov AH, 0Ah
   int 21h
   
   pulaLinha
   
   mov AH, 9
   mov dx, offset valor
   int 21h   
                       
   pulaLinha                      
              
   ; Pergunta base
   mov AH, 9
   mov dx, offset perguntaBase
   int 21h    
   
   ; Pega base
   mov dx, offset base
   mov AH, 0Ah
   int 21h
   
   pulaLinha
   
   mov DL, AL
   mov AH, 2
   int 21h
   
   ; prepara conversao
    
   mov CX, offset base
   cmp CX,  0Ah ; isso nao funciona :c
   JA  BaseMenor 
   JB  BaseMaior
   
   pulaLinha
   
   mov AH, 9
   mov dx, offset mesmaBase
   int 21h
   
   ret
   ;  Base maior que 10
BaseMaior:                  
        
       
   ret
                 
   ;  Base menor que 10
BaseMenor:  
       
    ret                                     

perguntaBase db "Insira a base do valor: $"

perguntaNumero db "Insira um valor decimal: $" 
  
mesmaBase db "A base que voce inseriu e a mesma que 10$"
                                          
valor db 8, 0, 3 dup(' '), '$'  

base db 5, 0, 3 dup(' '), '$'

                                         


