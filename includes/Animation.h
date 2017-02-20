
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
#include "TextLoader.h"


using namespace std;

class Animation{
private:
	int _posX;	int _posY;
	int frame;
	SDL_Rect source;
	SDL_Texture* mTexture;
	TextureLoader *_textureLoader = NULL;
	int startTicks;
	void init();
public:
void render(int , int ,SDL_Rect*,SDL_Renderer*);
void free();
bool loadMedia();
bool Animate(int , int ,SDL_Renderer*, FrameRate, bool);
bool Gameover(SDL_Renderer*, TextLoader);

Animation(){

}
~Animation();
Animation(SDL_Renderer*);

};

#endif



