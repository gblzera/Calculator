# Calculadora básica em Python

import os
import platform

def limpar_terminal():
    sistema = platform.system().lower()
    os.system('cls' if sistema == 'windows' else 'clear')

def obter_numero(mensagem):
    while True:
        entrada = input(mensagem)

        if entrada.lower() == 'sair':
            return None
        
        try: 
            return float(entrada)
        except ValueError:
            print('Por favor, digite um número válido ou "sair" para encerrar.')


def calcular(primeiro_valor, segundo_valor, operador):
    operacoes = {
        '+': lambda x, y: f'Resultado da soma: {primeiro_valor + segundo_valor}',
        '-': lambda x, y: f'Resultado da subtração: {primeiro_valor - segundo_valor}',

        '*': lambda x, y: f'Resultado da multiplicação: {primeiro_valor * segundo_valor}',
        '/': lambda x, y: f'Resultado da divisão: {primeiro_valor / segundo_valor}' if y != 0 else 'Erro: divisão por zero.'
    }

    resultado = operacoes.get(operador, lambda x, y: 'Operador inválido')(primeiro_valor, segundo_valor)
    return f'Resultado: {resultado}' if isinstance(resultado, (int, float)) else resultado

while True:
    limpar_terminal()

    primeiro_numero = obter_numero('Digite um número (ou "sair" para encerrar): ')

    if primeiro_numero is None:
        break

    segundo_numero = obter_numero('Digite outro número: ')

    if segundo_numero is None:
        break

    while True:
        operador = input('Digite um operador (+ - * /): ')
        operadores = ['+', '-', '*', '/']

        if operador in operadores:
            break

        print('Por favor, digite um operador válido.')

    print(calcular(primeiro_numero, segundo_numero, operador))
    input('Pressione Enter para continuar ...')