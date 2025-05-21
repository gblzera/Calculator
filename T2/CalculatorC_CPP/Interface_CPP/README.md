# Calculadora Científica com Interface Gráfica

Este projeto é uma calculadora científica com interface gráfica desenvolvida em C++ utilizando a biblioteca GTKmm. Ela suporta operações matemáticas básicas e funções científicas como seno, cosseno, tangente, logaritmo e raiz quadrada.

## 🧮 Funcionalidades

- Interface gráfica com botões interativos
- Operações básicas: soma, subtração, multiplicação e divisão
- Funções científicas: `sin`, `cos`, `tan`, `log`, `sqrt`
- Avaliação de expressões usando o algoritmo Shunting Yard
- Parênteses e ordem de precedência
- Campo de exibição dos resultados

## 📂 Estrutura do Projeto

```
├── calculator.h           # Classe com as funções matemáticas
├── calculadora_gui.cpp    # Implementação da GUI e lógica da calculadora
├── makefile               # Script para compilação
└── README.md              # Este arquivo
```

## 🧑‍💻 Dependências

- **C++17** ou superior
- **GTKmm 4**

Para instalar o GTKmm 4 no Ubuntu/Debian:

```bash
sudo apt update
sudo apt install libgtkmm-4.0-dev
```

## 🛠️ Compilação

Use o `makefile` incluído no projeto:

```bash
make
```

Isso irá gerar um executável chamado `calculadora`.

## 🚀 Execução

Após compilar, execute a calculadora com:

```bash
./calculadora
```