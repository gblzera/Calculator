
# 📐 Calculadora Científica em Haskell

Este projeto é uma calculadora científica funcional escrita em **Haskell** como parte de um estudo comparativo entre paradigmas de programação. Ela interpreta expressões matemáticas com suporte a:

- Operações básicas: `+`, `-`, `*`, `/`
- Parênteses e precedência
- Números decimais
- Detecção de divisão por zero
- Interface em terminal com entrada interativa (modo REPL)

---

## 📦 Requisitos

✅ Este projeto foi desenvolvido para rodar em:

- Ubuntu 20.04 ou superior **(incluindo WSL no Windows com Ubuntu instalado)**
- Terminal bash com permissões para instalar pacotes

---

## ⚙️ Instalação e Uso

### 1. Clone o repositório ou baixe os arquivos

```bash
git clone https://github.com/gblzera/Calculator.git
cd haskell-calculadora
```

### 2. Dê permissão de execução ao script de instalação

```bash
chmod +x script_h.sh
```

### 3. Execute o script para instalar tudo automaticamente

```bash
./script_h.sh
```

Esse script irá:
- Instalar o compilador GHC
- Instalar o gerenciador Cabal
- Instalar o `make`
- Atualizar os pacotes Haskell
- Compilar automaticamente o projeto com `make`

---

## 🚀 Execução

Depois da instalação, basta rodar o programa:

```bash
./calc
```

Exemplo de uso no terminal:

```
Digite uma expressão (ou 'sair' para encerrar):
4 + 2 * (3 - 1)
Resultado: 8.0
```

---

## 🛠️ Outros comandos úteis

- Recompilar manualmente:

```bash
make
```

- Limpar os arquivos temporários:

```bash
make clean
```

---

## 📁 Estrutura do Projeto

```
├── Calculator.hs             # Módulo com representação e avaliação da expressão
├── Main.hs                   # Parser e interface de terminal interativa
├── install_dependencies.sh   # Script de instalação e build
├── Makefile                  # Compilação via make
└── README.md                 # Este arquivo
```

---

## 🧠 Observações

- Se estiver usando **Windows**, execute o projeto no **WSL com distribuição Ubuntu instalada**.
- A calculadora funciona apenas em terminal (modo texto).
- Não requer bibliotecas externas além do GHC padrão.