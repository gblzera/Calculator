#!/bin/bash

# Atualizar pacotes
sudo apt update && sudo apt upgrade -y

# Instalar compilador C++
sudo apt install -y build-essential g++

# Instalar GTKMM 4 para GUI
sudo apt install -y libgtkmm-4.0-dev

# Verifica se makefile existe antes de compilar
if [ -f makefile ]; then
    echo "Compilando projeto com make..."
    make
else
    echo "Makefile não encontrado. Você pode compilar manualmente com:"
    echo "g++ -o calculadora calculadora_gui.cpp -lgtkmm-4.0"
fi

echo "✅ Ambiente pronto!"
