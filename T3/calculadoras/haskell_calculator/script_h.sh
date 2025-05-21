#!/bin/bash

echo "🔧 Instalando dependências da calculadora Haskell..."

# Atualiza os repositórios
sudo apt update

# Instala GHC (compilador Haskell) e o Cabal
sudo apt install -y ghc cabal-install make

# Atualiza o índice de pacotes do Cabal
cabal update

echo "✅ Ambiente Haskell instalado com sucesso!"

# Compila automaticamente usando o Makefile
echo "⚙️ Compilando o projeto com make..."
make

# Verifica se o executável foi gerado
if [ -f "calc" ]; then
    echo "🚀 Compilação concluída com sucesso! Execute com: ./calc"
else
    echo "❌ Algo deu errado na compilação."
fi
