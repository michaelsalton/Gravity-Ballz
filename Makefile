all: build run

build: 
	g++ Main.cpp -I"C:\Users\alaan\Documents\SFML-2.5.1\include" -o main -L"C:\Users\alaan\Documents\SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system
run:
	./main.exe
