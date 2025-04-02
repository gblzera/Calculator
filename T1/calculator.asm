; Calculadora em Assembly x86-64
; Realiza as quatro operações básicas: adição, subtração, multiplicação e divisão

section .data
    msg_menu db 10, "Calculadora em Assembly", 10
             db "1. Adicao", 10
             db "2. Subtracao", 10
             db "3. Multiplicacao", 10
             db "4. Divisao", 10
             db "5. Sair", 10
             db "Escolha uma opcao: ", 0
    
    msg_num1 db "Digite o primeiro numero: ", 0
    msg_num2 db "Digite o segundo numero: ", 0
    msg_resultado db "Resultado: ", 0
    msg_erro_div db "Erro: Divisao por zero!", 10, 0
    msg_opcao_invalida db "Opcao invalida! Tente novamente.", 10, 0
    
    fmt_entrada_int db "%ld", 0
    fmt_entrada_float db "%lf", 0
    fmt_saida_float db "%lf", 10, 0

section .bss
    opcao resq 1
    num1 resq 1
    num2 resq 1
    resultado resq 1

section .text
    global main
    extern printf
    extern scanf

main:
    push rbp
    mov rbp, rsp

menu:
    mov rdi, msg_menu
    xor rax, rax
    call printf
    
    mov rdi, fmt_entrada_int
    mov rsi, opcao
    xor rax, rax
    call scanf
    
    mov rax, [opcao]
    
    cmp rax, 5
    je fim
    
    cmp rax, 1
    jl opcao_invalida
    cmp rax, 4
    jg opcao_invalida
    
    mov rdi, msg_num1
    xor rax, rax
    call printf
    
    mov rdi, fmt_entrada_float
    mov rsi, num1
    xor rax, rax
    call scanf
    
    mov rdi, msg_num2
    xor rax, rax
    call printf
    
    mov rdi, fmt_entrada_float
    mov rsi, num2
    xor rax, rax
    call scanf
    
    mov rax, [opcao]
    
    cmp rax, 1
    je adicao
    
    cmp rax, 2
    je subtracao
    
    cmp rax, 3
    je multiplicacao
    
    cmp rax, 4
    je divisao

adicao:
    fld qword [num1]  ; Carrega num1 na FPU
    fadd qword [num2] ; Soma num2
    fstp qword [resultado] ; Armazena o resultado
    jmp exibir_resultado_float

subtracao:
    fld qword [num1]
    fsub qword [num2]
    fstp qword [resultado]
    jmp exibir_resultado_float

multiplicacao:
    fld qword [num1]
    fmul qword [num2]
    fstp qword [resultado]
    jmp exibir_resultado_float

divisao:
    fld qword [num2]
    fabs
    fldz
    fucompp
    fstsw ax
    sahf
    je erro_divisao_zero
    
    fld qword [num1]
    fdiv qword [num2]
    fstp qword [resultado]
    jmp exibir_resultado_float

erro_divisao_zero:
    mov rdi, msg_erro_div
    xor rax, rax
    call printf
    jmp menu

exibir_resultado_float:
    mov rdi, msg_resultado
    xor rax, rax
    call printf
    
    mov rdi, fmt_saida_float
    mov rax, 1  ; Indica argumento float para printf
    movq xmm0, [resultado]  ; Carrega resultado em xmm0 para printf
    call printf
    
    jmp menu

opcao_invalida:
    mov rdi, msg_opcao_invalida
    xor rax, rax
    call printf
    jmp menu

fim:
    mov rsp, rbp
    pop rbp
    xor rax, rax
    ret
