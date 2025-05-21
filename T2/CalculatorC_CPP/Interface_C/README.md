# 🧮 Calculadora Gráfica em C com GTK

Este é um projeto simples de uma **calculadora com interface gráfica**, desenvolvida em **linguagem C** utilizando a biblioteca **GTK+ 3**. A aplicação permite realizar as quatro operações básicas (+, −, ×, ÷) e conta com botões de limpar (`C`), apagar (`Del`) e calcular (`=`).

---

## ✨ Funcionalidades

- Interface gráfica simples e responsiva
- Operações básicas: adição, subtração, multiplicação e divisão
- Botão `Del` para apagar o último caractere digitado
- Botão `C` para limpar toda a expressão
- Alinhamento do visor à direita
- Avaliação da expressão da esquerda para a direita

---

## 📷 Captura de Tela

![screenshot](docs/screenshot.png)

---

## 🧰 Requisitos

Para compilar e executar o projeto, é necessário ter:

- Sistema Linux (ou WSL no Windows)
- `gcc` (compilador C)
- `GTK+ 3` e `pkg-config`

---

## ⚙️ Instalação

### Ubuntu / Debian (incluindo WSL)

```bash
sudo apt update
sudo apt install build-essential libgtk-3-dev pkg-config
```

---

## 🚀 Compilação e Execução

```bash
gcc calculadora_gtk.c -o calculadora `pkg-config --cflags --libs gtk+-3.0`
./calculadora
```

> No **WSL**, lembre-se de iniciar um servidor gráfico (como o `VcXsrv`) e configurar o `DISPLAY`:

```bash
export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0
```

---

## 📁 Estrutura do Projeto

```
T2/
├── CalculatorC_CPP/
│ ├── Interface_C/
│ │ ├── calculadora.c 
│ │ └── README.md
```

---

## 🧠 Observações Técnicas

- A expressão é avaliada da esquerda para a direita, sem respeitar precedência de operadores (PEMDAS). Por exemplo: `2+3*4` será interpretado como `(2+3)*4 = 20`.
- Para suporte a precedência matemática, seria necessário implementar um parser recursivo ou integrar uma biblioteca de parsing.

---

## 🛠️ Autor

Gabriel – 2025  
Desenvolvido para fins didáticos e acadêmicos.

---

## 📄 Licença

Este projeto é de uso livre para fins de aprendizado.