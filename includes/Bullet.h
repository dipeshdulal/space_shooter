/*****************************************************
 * Bullet loader class. Used to render the bullets 
 *
 * @author    Dipesh Dulal
 * @version   1.0
 * @since     2016-12-12
 *****************************************************/

#ifndef SPACESHOOTER_BULLET
	#define SPACESHOOTER_BULLET
	
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

	class Bullet{
		private:
			SDL_Rect _bulletPos = {856,421,9/2, 54/2};
			int _posX, _posY, speed = 3;
			TextureLoader *_textureLoader = NULL;
			void init();
		public:
			void getPosXY(int&,int&);
			Bullet(int, int, SDL_Renderer*);
			void renderBullet();		
	};


#endif