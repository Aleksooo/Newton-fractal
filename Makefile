CC = g++
FLAGS = --std=c++2a -Wall -fsanitize=address
SRCDIR = src
SFMLDIR = /usr/local/Cellar/sfml/2.5.1_2


all: main

main: main.o Equation.o Pool.o Algorithm.o Pallete.o
	$(CC) $(FLAGS) -o main main.o Equation.o Pool.o Algorithm.o Pallete.o -L"$(SFMLDIR)/lib" -lsfml-graphics -lsfml-window -lsfml-system

main.o: $(SRCDIR)/main.cpp $(SRCDIR)/Pool.cpp $(SRCDIR)/Equation.cpp
	$(CC) $(FLAGS) -c $(SRCDIR)/main.cpp

Pool.o: $(SRCDIR)/Pool.cpp
	$(CC) $(FLAGS) -c $(SRCDIR)/Pool.cpp

Equation.o: $(SRCDIR)/Equation.cpp
	$(CC) $(FLAGS) -c $(SRCDIR)/Equation.cpp

Algorithm.o: $(SRCDIR)/Algorithm.cpp
	$(CC) $(FLAGS) -c $(SRCDIR)/Algorithm.cpp

Pallete.o: $(SRCDIR)/Pallete.cpp
	$(CC) $(FLAGS) -c $(SRCDIR)/Pallete.cpp

clean:
	rm *.o
# $(SRCDIR)/*.gch

# g++ --std=c++2a src/main.cpp -I"/usr/local/Cellar/sfml/2.5.1_2/include" -o main -L"/usr/local/Cellar/sfml/2.5.1_2/lib" -lsfml-graphics -lsfml-window -lsfml-system
