CC = g++
FLAGS = --std=c++2a
SRCDIR = src
SFMLDIR = /usr/local/Cellar/sfml/2.5.1_2


all: main clean

main: main.o Equation.o Pool.o Algorithm.o
	$(CC) $(FLAGS) -o main main.o Equation.o Pool.o Algorithm.o -L"$(SFMLDIR)/lib" -lsfml-graphics -lsfml-window -lsfml-system

main.o: $(SRCDIR)/main.cpp $(SRCDIR)/Pool.h $(SRCDIR)/Equation.h
	$(CC) $(FLAGS) -c $(SRCDIR)/main.cpp

Pool.o: $(SRCDIR)/Pool.h
	$(CC) $(FLAGS) -c $(SRCDIR)/Pool.cpp

Equation.o: $(SRCDIR)/Equation.h
	$(CC) $(FLAGS) -c $(SRCDIR)/Equation.cpp

Algorithm.o: $(SRCDIR)/Algorithm.h
	$(CC) $(FLAGS) -c $(SRCDIR)/Algorithm.cpp

clean:
	rm *.o
# $(SRCDIR)/*.gch

# g++ --std=c++2a src/main.cpp -I"/usr/local/Cellar/sfml/2.5.1_2/include" -o main -L"/usr/local/Cellar/sfml/2.5.1_2/lib" -lsfml-graphics -lsfml-window -lsfml-system
