
/*****************************************************
 * Enemy Loader Class to render enemy in the given path
 *
 * @author    Dipesh Dulal, Abhimanyu Pandey, Dipesh Shrestha
 * @version   1.0
 * @since     2017-01-28
 *****************************************************/

#ifndef SPACESHOOTER_ENEMY
	#define SPACESHOOTER_ENEMY
	
	 // include the sdl
	#ifdef _WIN32
	  #include <SDL.h>
	#endif

	#ifdef __linux
	  #include <SDL2/SDL.h>
	#endif
	
	#include <vector>
	#include <iostream>
	#include "TextureLoader.h"

	using namespace std;

	class Enemy{
		private:
			SDL_Rect _enemyPos = {425, 468, 93, 84};
			int _posX, _posY, speed = 1;
			TextureLoader *_textureLoader = NULL;
			void init();
		public:
			void render();
			void getSpeed(int&);
			void getPosXY(int&,int&);
			Enemy(){}
			~Enemy();
			Enemy(int, int, SDL_Renderer*);
			void setPosXY(int, int);
	};


#endif