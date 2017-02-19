
#ifndef SPACESHOOTER_ANIMATION
	#define SPACESHOOTER_ANIMATION
#ifdef _WIN32
	  #include <SDL.h>
	#endif

	#ifdef __linux
	  #include <SDL2/SDL.h>
		
	#endif

#include <iostream> 
#include "TextureLoader.h"
#include "Collision.h"
#include "FrameRate.h"

using namespace std;

class Animation{
private:
	int _posX;	int _posY;
	int frame;
	SDL_Texture* mTexture;
	TextureLoader *_textureLoader = NULL;
	void init();
public:
void render(int , int ,SDL_Rect*,SDL_Renderer*);
void free();
bool loadMedia();
void Animate(int , int ,SDL_Renderer*, FrameRate);

Animation(){
	_posX=0;
	frame=0;
	_posY=0;
}
~Animation();
Animation(SDL_Renderer*);

};

#endif



