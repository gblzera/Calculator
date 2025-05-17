# ⚙️ Script de Setup para Calculadora NCurses

Este script automatiza a instalação do compilador, bibliotecas necessárias e a compilação do programa **Calculadora C++ com NCurses** no Ubuntu via **WSL**.

---

## 📦 Como usar

1. Coloque o script `setup_calc.sh` no seu ambiente Ubuntu (WSL).
2. Dê permissão de execução ao script:

```bash
chmod +x setup_calc.sh
```

3. Execute o script:

```bash
./setup_calc.sh
```

4. Quando solicitado, informe o **caminho completo** para o arquivo `calculadora.cpp`  
   _(exemplo: `/mnt/c/Users/Gabriel/Desktop/calculadora.cpp`)_.

---

## ✅ O que o script faz

- Atualiza o sistema
- Instala o compilador **g++** e as bibliotecas **libncurses5-dev** e **libncursesw5-dev**
- Compila o código da calculadora
- Informa como executar o programa no terminal

Se tudo ocorrer bem, você poderá rodar a calculadora com:

```bash
./calculadora
```

---

## ⚠️ Observações

- Certifique-se de informar o **caminho correto** para o arquivo `.cpp`.
- O script **não move arquivos**, apenas compila o programa no diretório onde o código está localizado.
- Ideal para rodar diretamente no terminal do **Ubuntu (WSL)** no **Windows**.
