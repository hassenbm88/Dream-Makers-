#ifndef JUMP_H_INCLUDED
#define JUMP_H_INCLUDED 

typedef struct
{
	int status;
	float x,y;
	float vx,vy;
	SDL_Surface *image;
} Sprite;
	void InitSprite(Sprite* Sp);
        void Render(Sprite* Sp,SDL_Surface* screen);
        void Saute(Sprite* Sp,float impulsion);
        void ControleSol(Sprite* Sp);
        void Gravite(Sprite* Sp,float factgravite,float factsautmaintenu,Uint8* keys);
        void Evolue(Sprite* Sp,Uint8* keys);
        void jump();
#endif

