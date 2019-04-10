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
#include "Deplacement_personnage_clavier.h"



void initialiser_Personnage(Personnage *P)
{

    P->vie = 3;
    P->score = 0;
    P->vitesse = 0;
    P->direction = 1;
    P->indice = 0;

    P->coeur = IMG_Load("5.png");
   
    P->imagesprite[0] = IMG_Load("d1.png");
    P->imagesprite[1] = IMG_Load("d2.png");
    P->imagesprite[2] = IMG_Load("d3.png");
    P->imagesprite[3] = IMG_Load("d4.png");
    P->imagesprite[4] = IMG_Load("g1.png");
    P->imagesprite[5] = IMG_Load("g2.png");
    P->imagesprite[6] = IMG_Load("g3.png");
    P->imagesprite[7] = IMG_Load("g4.png");
    //chargement des images pour le saut 

    P->jumpsprite[0] = IMG_Load("d1.png");
    P->jumpsprite[1] = IMG_Load("d2.png");
    P->jumpsprite[2] = IMG_Load("d3.png");
    P->jumpsprite[3] = IMG_Load("d4.png");
    P->jumpsprite[4] = IMG_Load("g1.png");
   
  
    P->post_coeur.x = 50;
    P->post_coeur.y = 50;
    P->position.x = 50;
    P->position.y = 50;
}


void afficher_perso(Personnage P, SDL_Surface *ecran)
{
    SDL_BlitSurface(P.imagesprite[P.indice], NULL, ecran, &P.position);
  //SDL_BlitSurface(P.imagesjump[P.jumpindice], NULL, ecran, &P.position);
    SDL_BlitSurface(P.coeur, NULL, ecran, &P.post_coeur);
}


void deplacer_Perso(Personnage *P, int direction)
{
    switch(direction)
    {
    case 1:
    if(P->position.x > 400)
    P->position.x -= 10;
    else
    P->position.x += 10;
    break;

    case 2:
    if(P->position.x <150)
    P->position.x += 10;
    else
    P->position.x -= 10;
    break;
}



void animer_perso(Personnage *P, int direction)
{
    if(direction == 0)
    {  
        P->indice = 1;
    }

    if(direction == 1)
    {
        if(P->indice < 3)
        {
            P->indice ++;
        }
        else
            P->indice = 0;
    }

    if(direction == 2)
    {
        if(P->indice < 7 && P->indice > 3)
        {
            P->indice ++;
        }
        else
            P->indice = 4;
    }
    
/*Quand le personnage peut sauter*/
 if(direction == 0)
    {  
        P->jumpindice = 12;
    }

    if(direction == 1)
    {
        if(P->jumpindice < 5)
        {
            P->jumpindice ++;
        }
        else
            P->jumpindice = 0;
    }

    if(direction == 2)
    {
        if(P->jumpindice <= 12 && P->jumpindice > 5)
        {
            P->jumpindice++;
        }
        else
            P->jumpindice = 5;
    }

}




void UpdatePlayer(Personnage* perso)
{
/*mis a jour du personnage apres le saut*/
        int collision_sol;
	if(collision_sol==1)
	{
		perso->ground = 1;
		perso->Ysaut = 0;
	}

	if(collision_sol==0 && perso->jump ==0)
	{
		perso->Ysaut = 10;
	}
	
	if(perso->jump == 1 && perso->Ysaut < 0)
	{
		perso->Ysaut += 8;
	}

	else
       {
		perso->jump = 0;
	perso->position.y += perso->Ysaut ;
        }
}
