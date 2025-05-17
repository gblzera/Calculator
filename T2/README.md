# 🧮 Calculadora C++ com NCurses (Terminal - WSL)

Este projeto é uma calculadora de terminal feita em **C++** com interface interativa usando a biblioteca **NCurses**. Foi desenvolvida para rodar no **Linux via WSL (Windows Subsystem for Linux)** no Windows.

---

## ✅ O que este projeto oferece

- Operações básicas (soma, subtração, multiplicação, divisão)
- Operações avançadas (potência, raiz, log, seno, cosseno, etc.)
- Histórico de cálculos
- Interface no terminal com NCurses
- Script de setup automatizado

---

## ⚙️ Como foi feito

- Linguagem: **C++**
- Interface: **NCurses**
- Ambiente: **Ubuntu via WSL no Windows**
- Automatização: Script `setup_calc.sh` para facilitar a instalação e compilação

---

## ▶️ Como executar

### 1. Instale o WSL com Ubuntu (se ainda não tiver)

No PowerShell (como administrador):

```powershell
wsl --install
```

Crie um usuário e senha quando solicitado ao abrir o Ubuntu pela primeira vez.

---

### 2. Use o script de instalação

Dentro do Ubuntu (WSL):

```bash
chmod +x setup_calc.sh
./setup_calc.sh
```

O script vai pedir o caminho completo do arquivo `calculadora.cpp`, por exemplo:

```
/mnt/c/Users/SeuNome/Desktop/calculadora.cpp
```

Ele cuidará da instalação das dependências e da compilação.

---

### 3. Execute a calculadora

Após a instalação:

```bash
./calculadora
```

Use as **setas** para navegar e **ENTER** para selecionar operações.

---

## 📝 Observações

- Este projeto foi testado no **WSL com Ubuntu 22.04**.
- O terminal precisa ser compatível com teclas especiais (sugestão: use o **Windows Terminal**).
- O código-fonte e o script de setup estão neste repositório.