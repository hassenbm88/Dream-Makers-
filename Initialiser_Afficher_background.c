# Dream-Makers-
Computer World 2D 
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include <string.h>
#include <math.h>
#include "Initialiser_Afficher_background.h"

void initialiser_background(background *Back)
{
    Back->stage = 0;

    Back->image[0] = IMG_Load("background.jpg");
   

    Back->pos.x = 0;
    Back->pos.y = 0;
    Back->pos.h = Back->image[0]->h;
    Back->pos.w = Back->image[0]->w;

    Back->post_background.x = 0;
    Back->post_background.y = 0;
    Back->post_background.h = Back->image[0]->h;
    Back->post_background.w = Back->image[0]->w;

}

void afficher_background(SDL_Surface *ecran, background Back)
{
    SDL_BlitSurface(Back.image[0], &Back.pos, ecran, &Back.post_background);
}

void scrolling_background(background *Back, int etat)
{
    switch(etat)
    {
    case 1:
        Back->pos.x = Back->pos.x + 10;
        break;
    case 2:
        Back->pos.x = Back->pos.x - 10;
        break;
    case 3:
        Back->pos.y = Back->pos.y + 10;
        break;
    case 4:
        Back->pos.y = Back->pos.y - 10;
        break;
    }
}
