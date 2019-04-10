# Dream-Makers-
Computer World 2D 
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include <stdbool.h>
#include "getpixel.h"


bool test(SDL_Rect col,SDL_Surface *collisionMap,SDL_Surface *ecran)
{
SDL_Color couleur;
	couleur = GetPixel(collisionMap, col.x, col.y);
	return((couleur.r == 0 && couleur.g == 255 && couleur.b == 0) );
	
}

void initialiser_enigme(int *x1,int *y1,int *x2,int *y2,int *x3,int *y3)
{
*x1=720;
*y1=350;
*x2=470;
*y2=170;
*x3=570;
*y3=60;
}
int generatin_aleatoire(int nbalea)
{
srand(time(NULL));
nbalea=1+rand()%5;
return nbalea;
}

void afficher_enigme(char image[20],SDL_Surface *ecran)
{
SDL_Surface *enigme=NULL;
SDL_Rect positionenigme;
    positionenigme.x = 0;
    positionenigme.y = 0;
enigme = IMG_Load(image);
SDL_BlitSurface(enigme, NULL, ecran, &positionenigme);
SDL_Flip(ecran);
}

void resolution_enigme(SDL_Rect *col)
{
int continuer=1;
SDL_Event event;
	while (continuer)

    {

        SDL_WaitEvent(&event);

        switch(event.type)

        {

            case SDL_QUIT:

                continuer = 0;

	    case SDL_MOUSEBUTTONDOWN:
		col->x=event.button.x;
		col->y=event.button.y;
		continuer=0;
        }
	

    }
}


bool collisionenigme (int direction,SDL_Rect col,SDL_Surface *collisionMap,SDL_Surface *ecran)
{
	if (collisionMap == NULL) 
	collisionMap = SDL_LoadBMP("map collision.bmp");
    SDL_Color couleur;
    int i;
    if (direction == 3)
    {
	for(i=(col.y+80);i<(col.y + 100);i++)
{
	couleur = GetPixel(collisionMap, col.x - 10, i);
	if((couleur.r == 0 && couleur.g == 255 && couleur.b == 0) )
	break;
}
    }
    else if (direction == 4)
    {
	for(i=(col.y+80);i<(col.y + 100);i++)
{
       couleur = GetPixel(collisionMap, col.x + 35 + 10, i);
	if((couleur.r == 0 && couleur.g == 255 && couleur.b == 0) )
	break;
}
    }
    else if (direction == 1)
    {
for(i=col.x;i<(col.x + 35);i++)
{
        couleur = GetPixel(collisionMap, i, col.y - 10 + 80);
	if((couleur.r == 0 && couleur.g == 255 && couleur.b == 0) )
	break;
}
    }
    else if (direction == 2)
    {
for(i=col.x;i<(col.x + 35);i++)
{
        couleur = GetPixel(collisionMap, i, col.y + 100 + 10);
	if((couleur.r == 0 && couleur.g == 255 && couleur.b == 0) )
	break;
}
    }
    
	return ((couleur.r == 0 && couleur.g == 255 && couleur.b == 0) );

}



bool enigmeh(SDL_Surface *ecran)
{
srand(time(NULL));
int nbalea=0;
int x1=0,y1=0,x2=0,y2=0,x3=0,y3=0,verif=0;
char image[20],imagerep[20]="s",imagecol[20]="c",categorie1[20]="h",categorie2[20]="g",categorie3[20]="p";


SDL_Surface *imagefond=NULL, *enigme=NULL, *reponse=NULL, *teste=NULL ;

SDL_Rect positionFond,col;
    SDL_Event event;
    int continuer = 1,cont=1,clic=0;

    positionFond.x = 0;
    positionFond.y = 0;
initialiser_enigme(&x1,&y1,&x2,&y2,&x3,&y3);
	imagefond = IMG_Load("fond.png");

SDL_BlitSurface(imagefond, NULL, ecran, &positionFond);
SDL_Flip(ecran);
while (continuer)

{

    SDL_PollEvent(&event);//attendre l'evenement

    switch(event.type)

    {
        
case SDL_MOUSEBUTTONDOWN:
switch(event.button.button)
{
case SDL_BUTTON_LEFT:
{

if((event.button.x<316.3)&&(event.button.x>101)&&(event.button.y>44)&&(event.button.y<335.6))
            {
		
            strcpy(image,"");
            strcpy(categorie1,"h");
            nbalea=1+rand()%2;
            sprintf(image,"%d",nbalea);
            strcat(image,".png");
            strcat(categorie1,image);
	    strcpy(image,categorie1);
	    strcat(imagerep,categorie1);
	    strcat(imagecol,categorie1);
            afficher_enigme(image,ecran);
            SDL_Flip(ecran);//mise a jour ecran
		verif=1;
            }
else if((event.button.x<616.2)&&(event.button.x>401.8)&&(event.button.y>44)&&(event.button.y<335.6))
            {
            strcpy(image,"");
            strcpy(categorie2,"g");
            nbalea=1+rand()%3;
            sprintf(image,"%d",nbalea); 
            strcat(image,".png");
            strcat(categorie2,image);
            strcpy(image,categorie2);
	    strcat(imagerep,categorie2);
	    strcat(imagecol,categorie2);
            afficher_enigme(image,ecran);
            SDL_Flip(ecran);//mise a jour ecran
		verif=1;
            }
else if((event.button.x<920)&&(event.button.x>712.2)&&(event.button.y>44)&&(event.button.y<335.6))
            {
            strcpy(image,"");
            strcpy(categorie3,"h");
	    nbalea=1+rand()%3;
            sprintf(image,"%d",nbalea);
            strcat(image,".png");
            strcat(categorie3,image);
            strcpy(image,categorie3);
	    strcat(imagerep,categorie3);
	    strcat(imagecol,categorie3);
            afficher_enigme(image,ecran);
            SDL_Flip(ecran);//mise a jour ecran
		verif=1;
            }
break;
}//event.button.button
}
	    case SDL_KEYDOWN:
            switch (event.key.keysym.sym)

            {
               
            }//event.key.keysym.sym

            break;
            case SDL_QUIT: /* Si c'est un événement QUITTER */
            continuer = 0; /* On met le booléen à 0, donc la boucle va s'arrêter */
            break;
    }//switch(event.type)

	if(verif==1)
{
	teste = IMG_Load(imagecol);
	reponse = IMG_Load(imagerep);
	resolution_enigme(&col);
	if(test(col,teste,ecran))
{
	afficher_enigme(imagerep,ecran);
	SDL_Delay(1000);
	return true;
	continuer=0;
}
	else
	return false;
	continuer=0;
}

}//while

/*SDL_FreeSurface(imagefond);
    SDL_FreeSurface(enigme);*/


}
