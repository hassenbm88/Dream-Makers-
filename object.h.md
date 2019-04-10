# Dream-Makers-
Computer World 2D 
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct
{
	SDL_Surface* image;
	SDL_Rect position;
	int coins;
}objet;
