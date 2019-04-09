#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include"fonction.h"

int gestion_vie(int vie)
{
    SDL_Surface *ecran = NULL, *coeur = NULL;
    SDL_Rect  positioncoeur;

    positioncoeur.x = 0;
    positioncoeur.y = 0;
    
    SDL_Init(SDL_INIT_VIDEO);

    

    ecran = SDL_SetVideoMode(1200, 800, 32, SDL_HWSURFACE);
 
switch(vie){
case 1:
 coeur=IMG_Load("coeur 1.png");
    SDL_BlitSurface(coeur, NULL, ecran, &positioncoeur);

break;
case 2:
 coeur=IMG_Load("coeur 2.png");
    SDL_BlitSurface(coeur, NULL, ecran, &positioncoeur);

break;
case 3:
 coeur=IMG_Load("coeur 3.png");
    SDL_BlitSurface(coeur, NULL, ecran, &positioncoeur);

break;
case 4:
 coeur=IMG_Load("coeur 4.png");
    SDL_BlitSurface(coeur, NULL, ecran, &positioncoeur);
break;
case 5:
 coeur=IMG_Load("coeur 5.png");
    SDL_BlitSurface(coeur, NULL, ecran, &positioncoeur);
break;
case 6:
 coeur=IMG_Load("coeur 6.jpg");
    SDL_BlitSurface(coeur, NULL, ecran, &positioncoeur);
break;
}

    /* Chargement et blittage de Zozor sur la scène */

    SDL_Flip(ecran);
    pause();

    
    SDL_FreeSurface(coeur);
    SDL_Quit();

    return EXIT_SUCCESS;
}
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
