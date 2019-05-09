#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
bool collisionmap (int direction,SDL_Rect col,SDL_Surface *collisionMap,SDL_Surface *ecran);
bool collision(SDL_Rect* coll, SDL_Rect* coll1);

