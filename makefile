prog:*.c
	gcc -g *.c -o prog -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -lSDLmain -I/usr/include/SDL -lm -w
