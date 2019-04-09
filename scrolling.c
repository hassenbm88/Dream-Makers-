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

#include "getpixel.h"



bool collisionmapscrolling (int direction,SDL_Rect col,SDL_Surface *collisionMap,SDL_Surface *ecran)

{

	if (collisionMap == NULL) 

	collisionMap = IMG_Load("map.png");

    SDL_Color couleur;

    int i;

    if (direction == 3)

    {

	for(i=(col.y+80);i<(col.y + 100);i++)

{

	couleur = GetPixel(collisionMap, col.x - 10, i);

	if((couleur.r == 0 && couleur.g == 0 && couleur.b == 255) )

	break;

}

    }

    else if (direction == 4)

    {

	for(i=(col.y+80);i<(col.y + 100);i++)

{

       couleur = GetPixel(collisionMap, col.x + 35 + 10, i);

	if((couleur.r == 0 && couleur.g == 0 && couleur.b == 255) )

	break;

}

    }

    else if (direction == 1)

    {

for(i=col.x;i<(col.x + 35);i++)

{

        couleur = GetPixel(collisionMap, i, col.y - 10 + 80);

	if((couleur.r == 0 && couleur.g == 0 && couleur.b == 255) )

	break;

}

    }

    else if (direction == 2)

    {

for(i=col.x;i<(col.x + 35);i++)

{

        couleur = GetPixel(collisionMap, i, col.y + 100 + 10);

	if((couleur.r == 0 && couleur.g == 0 && couleur.b == 255) )

	break;

}

    }

    

	return ((couleur.r == 0 && couleur.g == 0 && couleur.b == 255) );



}









void scroll (SDL_Rect *camera,int direction,SDL_Rect *coll,SDL_Rect positionBack1,SDL_Rect positionBack2,SDL_Surface *collisionMap) 

{

int speed=10;



  if (direction==1 && coll->y  + coll->h/2 <= camera->h/2 - 10) 

  {

    camera->y-=speed;

    coll->y+=10;

  }

  else if (direction==2 && coll->y + coll->h/2 >= camera->h/2 + 10) 

  {

    camera->y+=speed;

    coll->y-=10;

  }

  else if (direction==3 && coll->x - 600 + coll->w/2 <= camera->w/2 - 10 + positionBack1.x) 

  {

    camera->x-=speed;

   coll->x+=10;

  }

  else if (direction==4 && coll->x + coll->w/2 >= camera->w/2 + 10 - positionBack2.x) 

  {

    camera->x+=speed;

    coll->x-=10;

  }



  if( camera->x < 0 - positionBack1.x)

    {

        camera->x = 0;

	coll->x-=10;

    }

    if( camera->y < 0 )

    {

        camera->y = 0;

	coll->y-=10;

    }

  if( camera->x > collisionMap->w - camera->w + positionBack2.x)

    {

        camera->x = collisionMap->w - camera->w ;

	coll->x+=10;

    }

    if( camera->y > collisionMap->h - camera->h  )

    {

        camera->y = collisionMap->h - camera->h ;

	coll->y+=10;

    }



  

}









void display_scroll (SDL_Surface *screen,SDL_Surface *map,SDL_Rect camera)

{

  SDL_Rect position;

	position.x=0;
  position.y=0;

  SDL_BlitSurface(map,&camera , screen, &position);

  SDL_Flip(screen);



}

void display_scroll2 (SDL_Surface *screen,SDL_Surface *map,SDL_Rect camera)

{

  SDL_Rect position;

	position.x=600;

	position.y=0;

  SDL_BlitSurface(map,&camera , screen, &position);

  SDL_Flip(screen);



}
