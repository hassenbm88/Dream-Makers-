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

typedef struct 
{
    int stage;//numero de stage
    SDL_Rect pos;
    SDL_Rect post_background;//position du background par rapport a l ecran
    SDL_Surface *image[1];//tableau de background
   /* SDL_Surface* bg_collision;*/
    SDL_Rect position_collision;
    SDL_Rect scroll;
    
}background;

//Prototype des fonctions

void initialiser_background(background *Back);
void afficher_background(SDL_Surface *ecran, background Back);
void scrolling_background(background *Back, int etat);//scroller verticalement et /ou horizontalement tout le cadre si le perso atteint les limites du cadre

