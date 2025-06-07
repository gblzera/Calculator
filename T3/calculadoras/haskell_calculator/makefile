EXEC = calc

SOURCES = Main.hs Calculator.hs

GHC = ghc

# Flags
GHCFLAGS = -O2 

# main rule
all: $(EXEC)

$(EXEC): $(SOURCES)
	$(GHC) $(GHCFLAGS) -o $(EXEC) $(SOURCES)

# clean rule 
clean:
	rm -f *.hi *.o $(EXEC)

# run rule
run: all
	./$(EXEC)
