CC = g++
FLAGS = --std=c++2a
DIR = src

all: main clean

main: main.o Equation.o
	$(CC) $(FLAGS) -o main main.o Equation.o App.o -L"/usr/local/Cellar/sfml/2.5.1_2/lib" -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp Equation.h
	$(CC) $(FLAGS) -c $(DIR)/main.cpp

App.o: $(DIR)/App.h SFML/Window.hpp
	$(CC) $(FLAGS) -c $(DIR)/App.cpp
# -I"/usr/local/Cellar/sfml/2.5.1_2/include"

Equation.o: $(DIR)/Equation.h
	$(CC) $(FLAGS) -c $(DIR)/Equation.cpp

clean:
	rm *.o $(DIR)/*.gch

# g++ --std=c++2a src/main.cpp -I"/usr/local/Cellar/sfml/2.5.1_2/include" -o main -L"/usr/local/Cellar/sfml/2.5.1_2/lib" -lsfml-graphics -lsfml-window -lsfml-system
