all: main run

main: main.cpp
	g++ -std=c++17 -I include -L lib *.cpp -o main -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lSDL2_net

run: main
	./main

.PHONY: all run
