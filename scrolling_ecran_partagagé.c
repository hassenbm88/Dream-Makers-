# Dream-Makers-
Computer World 2D 
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "scroll.h"

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
  else if (direction==4 && coll->x + coll->w/2 >= camera->w/2 + 10 - 300) 
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


int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *surface1 = NULL, *surface2 = NULL, *background= NULL;
    SDL_Event event;
    SDL_Rect position1, position2,positionback,positionback2,camera1;
    int continuer = 1;
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(300, 300, 32, SDL_HWSURFACE);
   
    position1.x=150;
    position1.y=150;
    position2.x=600;
    position2.y=0;
    camera1.w=300;
    camera1.h=300;
    
    camera1.x=0;
    camera1.y=0;
    
positionback.x = 0;
	positionback.y = 0;
positionback2.x = 300;
	positionback2.y = 0;
	surface1 = IMG_Load("map.png");
position2.x=600;
position2.y=0;
	background = IMG_Load("joueur1.png");
    SDL_BlitSurface(surface1, &camera1 , ecran, &positionback );
    //SDL_BlitSurface(background, NULL, ecran,&position1 );
    SDL_Flip(ecran);

    while(continuer)
    {
        SDL_WaitEvent(&event);
 
        switch(event.type)
        {
            case SDL_QUIT:
            continuer = 0;
            break;
	    case SDL_KEYDOWN:
		switch(event.key.keysym.sym)
		{
			case SDLK_UP:
				scroll(&camera1,1,&position1,positionback,positionback2,surface1);
				position1.y-=10;
			break;
			case SDLK_DOWN:
				scroll(&camera1,2,&position1,positionback,positionback2,surface1);
				position1.y+=10;
			break;
			case SDLK_LEFT:
				scroll(&camera1,3,&position1,positionback,positionback2,surface1);
				position1.x-=10;
			break;
			case SDLK_RIGHT:
				scroll(&camera1,4,&position1,positionback,positionback2,surface1);
				position1.x+=10;
			break;
		}
display_scroll(ecran,surface1,camera1);
		break;
        }
    }
    SDL_Quit();
    SDL_FreeSurface(surface1);
    SDL_FreeSurface(surface2);
    SDL_FreeSurface(background);
    return EXIT_SUCCESS;
}
