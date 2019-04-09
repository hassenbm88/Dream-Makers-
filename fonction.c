#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include"fonction.h"

void pause()
{
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}
int gestion_score(int collision,int i)
{
    SDL_Surface *ecran = NULL, *score = NULL;
    SDL_Rect  positionscore;
    SDL_Rect rects[10];	
    positionscore.x = 0;
    positionscore.y = 0;
    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
 if(collision==1){
i++;
if(i>10){i=10;}
}else if(collision==0){
i--;
if(i<0){i=0;}
}
   switch(i){
case 0:
score=IMG_Load("0.png");
SDL_BlitSurface(score, NULL, ecran, &positionscore);
break;
case 1:
score=IMG_Load("1.png");
SDL_BlitSurface(score, NULL, ecran, &positionscore);
break;
case 2:
score=IMG_Load("2.png");
SDL_BlitSurface(score, NULL, ecran, &positionscore);
break;
case 3:
score=IMG_Load("3.png");
SDL_BlitSurface(score, NULL, ecran, &positionscore);
break;
case 4:
score=IMG_Load("4.png");
SDL_BlitSurface(score, NULL, ecran, &positionscore);
break;
case 5:
score=IMG_Load("5.png");
SDL_BlitSurface(score, NULL, ecran, &positionscore);
break;
case 6:
score=IMG_Load("6.png");
SDL_BlitSurface(score, NULL, ecran, &positionscore);
break;
case 7:
score=IMG_Load("7.png");
SDL_BlitSurface(score, NULL, ecran, &positionscore);
break;
case 8:
score=IMG_Load("8.png");
SDL_BlitSurface(score, NULL, ecran, &positionscore);
break;
case 9:
score=IMG_Load("9.png");
SDL_BlitSurface(score, NULL, ecran, &positionscore);
break;
case 10:
score=IMG_Load("10.png");
SDL_BlitSurface(score, NULL, ecran, &positionscore);
break;
}

    /* Chargement et blittage de Zozor sur la scène */

    SDL_Flip(ecran);
    pause();

    
    SDL_FreeSurface(score);
    SDL_Quit();

    return i;
}
