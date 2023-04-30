all: clean build run

clean:
	rm -f a.out

build: 
	g++ Main.cpp Entity.cpp -I/opt/homebrew/Cellar/sfml/2.5.1_2/include/ -o a.out -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib/ -lsfml-graphics -lsfml-window -lsfml-system

run:
	./a.out
