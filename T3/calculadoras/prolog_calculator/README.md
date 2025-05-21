# 🧮 Calculadora Interativa em Prolog

Este projeto é uma **calculadora interativa em Prolog** que permite avaliar expressões matemáticas diretamente no terminal.

## 🐧 Ambiente

Este guia foi feito para uso com **WSL (Windows Subsystem for Linux)** usando o Ubuntu.

## 📦 Instalação

Você pode instalar o SWI-Prolog com o seguinte comando:

```bash
sudo apt update
sudo apt install swi-prolog
```

Ou use o script automatizado:

```bash
chmod +x script_p.sh
./script_p.sh
```

## 🚀 Como usar

1. Certifique-se de que você está no diretório onde está o arquivo `calculator.pl`.
2. Inicie o SWI-Prolog:

   ```bash
   swipl
   ```

3. Carregue o programa:

   ```prolog
   ?- [calculator].
   ```

4. Inicie a calculadora:

   ```prolog
   ?- start.
   ```

5. Digite expressões matemáticas:

   ```prolog
   > 2+3*4.
   Resultado: 14
   ```

6. Para sair da calculadora, digite:

   ```prolog
   > sair.
   👋 Encerrando a calculadora. Até logo!
   ```

## ❗ Sobre o ponto final

O SWI-Prolog **exige que toda entrada termine com um ponto (`.`)**. Sem isso, ele continuará esperando mais entrada.

✅ Correto:
```prolog
2+2.
sair.
```

❌ Incorreto:
```prolog
2+2
```

## 🔚 Como sair do Prolog

Após sair da calculadora, o prompt do Prolog continuará ativo. Para sair completamente:

```prolog
?- halt.
```

Ou pressione:
- `Ctrl+D` (Linux/macOS)
- `Ctrl+Z` e Enter (Windows)