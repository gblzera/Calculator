CXX = g++
CXXFLAGS = -std=c++17 -Wall -g
GTKMM_FLAGS = `pkg-config --cflags --libs gtkmm-4.0`

# Se estiver usando GTKmm 3 em vez de 4, use esta linha
# GTKMM_FLAGS = `pkg-config --cflags --libs gtkmm-3.0`

all: calculadora

calculadora: calculadora_gui.o calculator.o
	$(CXX) $(CXXFLAGS) -o calculadora calculadora_gui.o calculator.o $(GTKMM_FLAGS)

calculadora_gui.o: calculadora_gui.cpp calculator.h
	$(CXX) $(CXXFLAGS) -c calculadora_gui.cpp $(GTKMM_FLAGS)

calculator.o: calculator.cpp calculator.h
	$(CXX) $(CXXFLAGS) -c calculator.cpp

clean:
	rm -f *.o calculadora