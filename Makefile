all:
	g++ --std=c++2a src/main.cpp -I"/usr/local/Cellar/sfml/2.5.1_2/include" -o main -L"/usr/local/Cellar/sfml/2.5.1_2/lib" -lsfml-graphics -lsfml-window -lsfml-system
