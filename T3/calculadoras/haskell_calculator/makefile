# Nome do executável
EXEC = calc

# Arquivos fonte
SOURCES = Main.hs Calculator.hs

# Compilador
GHC = ghc

# Flags de compilação (adicione -Wall se quiser warnings)
GHCFLAGS = -O2

# Regra principal
all: $(EXEC)

$(EXEC): $(SOURCES)
	$(GHC) $(GHCFLAGS) -o $(EXEC) $(SOURCES)

# Limpeza dos arquivos gerados
clean:
	rm -f *.hi *.o $(EXEC)

# Executar diretamente
run: all
	./$(EXEC)
