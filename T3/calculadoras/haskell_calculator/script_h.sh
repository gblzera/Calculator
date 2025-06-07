#!/bin/bash

echo "🔧 Instalando dependências da calculadora Haskell..."

sudo apt update

sudo apt install -y ghc cabal-install make

cabal update

echo "✅ Ambiente Haskell instalado com sucesso!"

echo "⚙️ Compilando o projeto com make..."
make

if [ -f "calc" ]; then
    echo "🚀 Compilação concluída com sucesso! Execute com: ./calc"
else
    echo "❌ Algo deu errado na compilação."
fi
