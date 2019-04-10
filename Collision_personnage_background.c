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
#include "Collision_personnage_background.h"
#include "getpixel.h"

 //fonction getpixel.h a été intégrée pour rassurer la collision avec le background
 
bool collisionmap (int direction,SDL_Rect col,SDL_Surface *collisionMap,SDL_Surface *ecran)
{
	if (collisionMap == NULL) 
	    collisionMap = SDL_LoadBMP("mapcollision.bmp");
    SDL_Color couleur;
    int i;
    if (direction == 3)
    {
	for(i=(col.y+80);i<(col.y + 100);i++)
{
	couleur = GetPixel(collisionMap, col.x, i);
	if((couleur.r == 255 && couleur.g == 255 && couleur.b == 255) )
	break;
}
    }
    else if (direction == 4)
    {
	for(i=(col.y+80);i<(col.y + 100);i++)
{
       couleur = GetPixel(collisionMap, col.x + 25 + 10, i);
	if((couleur.r == 255	 && couleur.g == 255 && couleur.b == 255) )
	break;
}
    }
    else if (direction == 1)
    {
for(i=col.x + 10;i<(col.x + 25);i++)
{
        couleur = GetPixel(collisionMap, i, col.y - 10 + 80);
	if((couleur.r == 255 && couleur.g == 255 && couleur.b == 255) )
	break;
}
    }
    else if (direction == 2)
    {
for(i=col.x + 10;i<(col.x + 25);i++)
{
        couleur = GetPixel(collisionMap, i, col.y + 100 + 10);
	if((couleur.r == 255 && couleur.g == 255 && couleur.b == 255) )
	break;
}
    }
    
	return ((couleur.r == 255 && couleur.g == 255 && couleur.b == 255) );
  
// la couleur blanche marque la collision de sorte que le personnage une fois en contact ne traversera pas cette partie du map .
}




bool collision(SDL_Rect* coll, SDL_Rect* coll1)
{
    if (coll->y >= coll1->y + coll1->h)
        return false;
    if (coll->x >= coll1->x + coll1->w)
        return false;
    if (coll->y + 20 <= coll1->y)
        return false;
    if (coll->x + 35 <= coll1->x)
        return false;
    return true;
}
