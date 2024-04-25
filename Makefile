all: main run

main: main.cpp
	g++ -I SDL2 -L lib -L *.cpp -o main.exe -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

run: main
	./main.exe

.PHONY: all run