prog:game.o main.o
	gcc game.o main.o -o prog -lSDL -lSDL_image -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -g
game.o:game.c
	gcc -c game.c -lSDL -lSDL_image -g

