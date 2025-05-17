#!/bin/bash

echo "Atualizando pacotes..."
sudo apt update && sudo apt upgrade -y

echo "Instalando g++ e bibliotecas ncurses..."
sudo apt install g++ libncurses5-dev libncursesw5-dev -y

echo "Digite o caminho completo do arquivo calculadora.cpp (exemplo: /mnt/c/Users/Gabriel/Desktop/calculadora.cpp):"
read CAMINHO_CODIGO

if [ ! -f "$CAMINHO_CODIGO" ]; then
    echo "Arquivo não encontrado! Verifique o caminho e tente novamente."
    exit 1
fi

DIR=$(dirname "$CAMINHO_CODIGO")
BASE=$(basename "$CAMINHO_CODIGO")

echo "Indo para o diretório do código: $DIR"
cd "$DIR" || exit 1

echo "Compilando o código..."
g++ "$BASE" -o calculadora -lncurses -std=c++11

if [ $? -eq 0 ]; then
    echo "Compilação concluída com sucesso!"
    echo "Para executar, rode: ./calculadora"
else
    echo "Erro na compilação."
fi
