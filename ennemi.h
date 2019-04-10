# Dream-Makers-
Computer World 2D 
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdbool.h>
void initialiser_enigme(int *x1,int *y1,int *x2,int *y2,int *x3,int *y3);
int generatin_aleatoire(int nbalea);
void afficher_enigme(char image[20],SDL_Surface *ecran);
void resolution_enigme(SDL_Rect *col);
bool enigmeh(SDL_Surface *ecran);
bool test(SDL_Rect col,SDL_Surface *collisionMap,SDL_Surface *ecran);
bool collisionenigme (int direction,SDL_Rect col,SDL_Surface *collisionMap,SDL_Surface *ecran);
