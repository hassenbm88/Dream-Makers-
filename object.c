# Dream-Makers-
Computer World 2D 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

void initialiser_piece(objet *p)
{
	p->image = IMG_Load("piece.jpg");
	p->coins = 20;
}

void initialiser_trousse(objet *t)
{
	t->trousse = IMG_Load("trousse.jpg");
}
void Display_objet (objet p,SDL_Rect position,SDL_Surface *screen)
{
	
		SDL_BlitSurface(p.image,SDL_Rect  NULL , screen, &position);
		SDL_Flip( screen );
	   
}
SDL_Rect posObjet(SDL_Rect posJ,SposO)
{
	posO.x-=posJ.x;
	posO.y-=posJ.y;
	return posO;
}
