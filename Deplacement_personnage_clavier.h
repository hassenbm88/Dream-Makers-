# Dream-Makers-
Computer World 2D 
#ifndef FILE_PROS_H_INCLUDED
#define FILE_PROS_H_INCLUDED
//#include <SDL/SDL_rotozoom.h>

typedef struct 
{
    int vie;//nombre de vie du joueur 
    int score;//score du joueur
    int indice;
    char nom[20];//nom du joueur
    int vitesse;//vitesse du perso
    int direction;//direction du perso
    int onground;
    Sint16 Ysaut;
    int ground;

    
    SDL_Rect position;//position de l image par rapport a l ecran
    SDL_Rect post_coeur;
     

    SDL_Surface *coeur;                                                           
    SDL_Surface *imagesprite[8];//image sur forme de sprite c est a dire une image constitue de plusieurs posture du perso
    SDL_Surface *jumpsprite[4];
}Personnage;
//Prototype des fonctions
void initialiser_Personnage(Personnage *P);
void afficher_perso(Personnage P, SDL_Surface *ecran);//afficher un 1er et unique perso
void deplacer_Perso(Personnage *P, int direction);//deplacer un perso moyennant le clavier dans un cadre fixe de la map 
void animer_perso(Personnage *P, int direction);//animer le perso lors du deplacement
void UpdatePlayer(Personnage* perso);
#endif // FILE_PROS_H_INCLUDED

