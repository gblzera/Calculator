# 🧮 Calculadora NCurses em C++ - Interface Terminal

Uma calculadora poderosa feita inteiramente em **C++** usando a biblioteca **NCurses** para interface no terminal. Com ela, você pode realizar operações **básicas**, **avançadas** e ainda acessar um **histórico de cálculos** — tudo direto no seu terminal Linux rodando via **WSL no Windows**.

---

## 🚀 Como executar no Windows via WSL

### 🔧 Passo 1: Instalar o WSL
1. Abra o **PowerShell como administrador**.
2. Rode o comando para instalar o WSL com Ubuntu:

```powershell
wsl --install
```

3. Reinicie o computador, se solicitado.
4. Na primeira vez que abrir o Ubuntu, será solicitado que você **crie um usuário e senha Linux**.

---

### ⚙️ Passo 2: Configurar o ambiente no Ubuntu (WSL)
1. Abra o **Ubuntu** pelo menu Iniciar.
2. Atualize os pacotes:

```bash
sudo apt update && sudo apt upgrade -y
```

3. Instale o compilador C++ e a biblioteca NCurses:

```bash
sudo apt install g++ libncurses5-dev libncursesw5-dev -y
```

---

### 📁 Passo 3: Preparar o código
1. Copie o arquivo `calculadora.cpp` para algum diretório acessível no Ubuntu.
2. No terminal, navegue até esse diretório:

```bash
cd /mnt/c/caminho/para/seu/codigo
```
> Substitua `/caminho/para/seu/codigo` pelo caminho correto do seu arquivo.

---

### 🛠️ Passo 4: Compilar o programa

```bash
g++ calculadora.cpp -o calculadora -lncurses -std=c++11
```

---

### ▶️ Passo 5: Executar

```bash
./calculadora
```

Agora é só usar as **setas** para navegar no menu, **ENTER** para selecionar e curtir a calculadora no terminal!

---

## ✨ Funcionalidades

- ✅ Operações básicas: soma, subtração, multiplicação, divisão
- ✅ Operações avançadas: potência, raiz quadrada, módulo, logaritmo, seno, cosseno
- ✅ Histórico de cálculos com opção de limpar
- ✅ Tratamento de erros (divisão por zero, entradas inválidas etc)
- ✅ Interface interativa no terminal com NCurses

---

## 📝 Nota rápida

Se o programa não responder corretamente aos comandos do teclado:
- Verifique se o terminal está configurado corretamente para capturar teclas especiais.
- Experimente rodar em outro emulador de terminal como **Windows Terminal**, **ConEmu**, **Alacritty**, entre outros.