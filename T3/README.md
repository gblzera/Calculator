# 🔢 Comparação de Paradigmas: Calculadoras Funcional (Haskell) e Lógico (Prolog)

Este projeto tem como objetivo comparar **paradigmas de programação** através da implementação de **calculadoras** nas linguagens **Haskell (funcional)** e **Prolog (lógica)**.

Ele serve como estudo prático das diferenças entre esses paradigmas, focando em **sintaxe, modelo de execução, clareza, modularidade** e **facilidade de implementação de lógica matemática**.

---

## 🚀 Linguagens e Paradigmas

### 🔷 Funcional — Haskell

- Programação funcional pura
- Imutabilidade e recursão como base
- Avaliação preguiçosa (lazy evaluation)
- Tipagem forte e inferida

### 🔶 Lógico — Prolog

- Baseado em lógica de predicados (fatos e regras)
- Execução por unificação e backtracking
- Natural para problemas declarativos

---

## 🧮 Funcionalidades

Cada calculadora implementa:

- Operações básicas: `+`, `-`, `*`, `/`
- Parênteses e precedência
- Avaliação de expressões matemáticas
- Interação via terminal

Extras por linguagem:
- Haskell: suporte a expressões aninhadas e operadores personalizados
- Prolog: avaliação por regras e inferência

---

## 📁 Estrutura do Projeto

```
calculadoras/
├── haskell_calculator/
│   ├── Calculator.hs             # Módulo principal da calculadora funcional
│   └── Main.hs                   # Entrada principal com parsing e execução
├── prolog_calculator/
│   └── calculator.pl             # Fatos, regras e avaliador lógica
└── README.md                     # Este arquivo
```

---

## 🛠️ Dependências

### Haskell

- [GHC](https://www.haskell.org/ghc/) — Compilador Haskell
- [Stack](https://docs.haskellstack.org/) (opcional, recomendado)

```bash
sudo apt update
sudo apt install haskell-platform
```

### Prolog

- [SWI-Prolog](https://www.swi-prolog.org/)

```bash
sudo apt install swi-prolog
```

---

## ⚙️ Execução

### Haskell

```bash
cd haskell_calculator
runhaskell Main.hs
```

### Prolog

```bash
cd prolog_calculator
swipl -s calculator.pl
```

---

## 📊 Comparação entre os Paradigmas

| Critério               | Haskell                    | Prolog                      | 
|------------------------|----------------------------|-----------------------------|
| Modelo de Execução     | Avaliação de expressões    | Resolução lógica (regras)   | 
| Sintaxe                | Funcional, tipada          | Declarativa, baseada em fatos e regras | 
| Curva de Aprendizado   | Alta                       | Alta                        | 
| Facilidade com expressões | Alta com parser combinators | Média (requere modelagem lógica) | 
| Suporte/Ferramentas    | Forte                      | Forte                       | 

---

## 🎯 Objetivo do Estudo

> "Não é só sobre fazer contas. É sobre **como** você faz contas em diferentes universos de pensamento computacional."

Este projeto serve como base para:
- Relatórios acadêmicos sobre paradigmas
- Análise de expressividade e clareza
- Entendimento de modelos de execução radicalmente diferentes

---

## 📚 Referências

- [Learn You a Haskell for Great Good!](http://learnyouahaskell.com/)
- [SWI-Prolog Documentation](https://www.swi-prolog.org/pldoc/)