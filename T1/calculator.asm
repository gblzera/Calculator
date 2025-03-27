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
    
    fmt_entrada db "%ld", 0
    fmt_saida db "%ld", 10, 0

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
    ; Preservar registradores base pointer
    push rbp
    mov rbp, rsp

menu:
    ; Exibir menu (em x86-64, os primeiros argumentos vão para registradores)
    mov rdi, msg_menu
    xor rax, rax        ; Zero retornos vetoriais para printf
    call printf
    
    ; Ler opção do usuário
    mov rdi, fmt_entrada
    mov rsi, opcao
    xor rax, rax
    call scanf
    
    ; Verificar opção
    mov rax, [opcao]
    
    ; Verificar se é opção de saída
    cmp rax, 5
    je fim
    
    ; Verificar se é opção válida
    cmp rax, 1
    jl opcao_invalida
    cmp rax, 4
    jg opcao_invalida
    
    ; Ler primeiro número
    mov rdi, msg_num1
    xor rax, rax
    call printf
    
    mov rdi, fmt_entrada
    mov rsi, num1
    xor rax, rax
    call scanf
    
    ; Ler segundo número
    mov rdi, msg_num2
    xor rax, rax
    call printf
    
    mov rdi, fmt_entrada
    mov rsi, num2
    xor rax, rax
    call scanf
    
    ; Realizar a operação escolhida
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
    mov rax, [num1]
    add rax, [num2]
    mov [resultado], rax
    jmp exibir_resultado

subtracao:
    mov rax, [num1]
    sub rax, [num2]
    mov [resultado], rax
    jmp exibir_resultado

multiplicacao:
    mov rax, [num1]
    imul rax, [num2]
    mov [resultado], rax
    jmp exibir_resultado

divisao:
    ; Verificar divisão por zero
    mov rbx, [num2]
    cmp rbx, 0
    je erro_divisao_zero
    
    mov rax, [num1]
    cqo                 ; Estender o sinal de RAX para RDX:RAX (equivalente a cdq em 32-bits)
    idiv qword [num2]   ; RAX = RDX:RAX / operando
    mov [resultado], rax
    jmp exibir_resultado

erro_divisao_zero:
    mov rdi, msg_erro_div
    xor rax, rax
    call printf
    jmp menu

exibir_resultado:
    mov rdi, msg_resultado
    xor rax, rax
    call printf
    
    mov rdi, fmt_saida
    mov rsi, [resultado]
    xor rax, rax
    call printf
    
    jmp menu

opcao_invalida:
    mov rdi, msg_opcao_invalida
    xor rax, rax
    call printf
    jmp menu

fim:
    ; Restaurar registradores e finalizar
    mov rsp, rbp
    pop rbp
    xor rax, rax        ; Retorno 0 para o sistema operacional
    ret