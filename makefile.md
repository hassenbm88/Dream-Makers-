# Dream-Makers-
Computer World 2D 
prog:menu.o ennemi.o objet.o scroll.o
	gcc   menu.o ennemi.o objet.o scroll.o -o belinda -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
menu.o:menu.c
	gcc -c menu.c

ennemi.o:ennemi.c
	gcc -c ennemi.c

objet.o:objet.c
	gcc -c objet.c

scroll.o:scroll.c
	gcc -c scroll.c
