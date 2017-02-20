#include <iostream>
#include "Animation.h"
#include "TextureLoader.h"
#include "Collision.h"
#include "FrameRate.h"
#include "TextLoader.h"

using namespace std;

bool Animation::Gameover(SDL_Renderer* gRenderer, TextLoader textLoader){
	_textureLoader->load("resources/gameover.png");
	// SDL_Rect srcgameover= {0,0,640,480};
	// SDL_Rect dstgameover= {0,0,640,480};
	_textureLoader->renderTexture( NULL , NULL );
	SDL_Color color = {255,255,255,255};
	// textLoader.loadText("Score: Here", color);
	// textLoader.render(20,480/2,5);

	return true;
}

Animation::Animation(SDL_Renderer* gRenderer){
	_posX=0;
	frame=0;
	_posY=0;
	source.x = 0;
	source.y = 0;
	source.w = 64;
	source.h = 64;
	startTicks = 0;
	_textureLoader = new TextureLoader(gRenderer);
	init();

}

bool finished = false;

bool Animation::Animate(int x ,int y,SDL_Renderer* gRenderer, FrameRate frameRate, bool trigger){
	// Animation gSpriteSheetTexture(gRenderer);
	// SDL_Rect gSpriteClips[4];

	//cout << trigger << endl;

	if(trigger){
		startTicks = frameRate.getTicks();
		finished = false;
	}


	if(!finished){
		int ticks = ( (frameRate.getTicks() - startTicks) % 1600);
		 //cout <<frameRate.getTicks()%1600<< endl;

		//cout << ticks << endl;
		
		if( ticks >= 97 && ticks <100 ){

		}else if(ticks >191 && ticks <200){
			
			source.x = 64;
		}else if(ticks >291 && ticks < 300 ){
			source.x = 2 * 64;
		}else if(ticks >391 && ticks < 400){
			source.x = 3 * 64;
		}
		
		else if(ticks >400 && ticks <500 ){
			source.x = 0* 64;
			source.y= 64;
		}
		else if(ticks>500 && ticks < 600 ){
			source.x = 1 * 64;
		}
		else if(ticks > 600 && ticks < 700){
			source.x = 2 * 64;
		}
		else if(ticks > 700 && ticks < 800){
			source.x = 3 * 64;
		}

		else if(ticks>800 && ticks <900 ){
			source.y= 2*64 ;

			source.x = 0 * 64;
		}
		else if(ticks > 900 && ticks < 1000){
			source.x = 1 * 64;
		}
		else if(ticks > 1000 && ticks < 1100){
			source.x = 2 * 64;
		}
		else if(ticks > 1100 && ticks < 1200){
			source.x = 3 * 64;
		}

		else if(ticks > 1200 && ticks < 1300){
			source.y = 3*64;
			source.x = 0 * 64;
		}
		else if(ticks > 1300 && ticks < 1400){
			source.x = 1 * 64;
		}
		else if(ticks > 1400 && ticks < 1400 ){
			source.x = 2 * 64;
		}
		else if(ticks > 1400 && ticks < 1499){
			source.x = 3 * 64;
			gRenderer = NULL;
			finished = true;
			startTicks = 0;
		}	
	}

	
	render(x, y , &source, gRenderer);
	
	return finished;
}


void Animation::init(){
	_textureLoader->load("resources/explosion.png");

}

Animation::~Animation(){
	_textureLoader = nullptr;
}

void Animation::free(){
	_textureLoader = nullptr;


}

void Animation::render(int x ,int y, SDL_Rect* clip, SDL_Renderer* gRenderer){
	_posX=x; //enemy ko pos halne
	_posY=y; //enemy ko pos halne
	int w=0;
	int h=0;
	SDL_Rect renderQuad= { _posX,_posY,w,h};	

	if(clip!=NULL){
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}	
	
	_textureLoader->renderTexture(clip, &renderQuad);

}

