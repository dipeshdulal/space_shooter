/*****************************************************
 * Player class. Used for player movement and 
 * collision detection for later part of development.
 *
 * @author    Dipesh Dulal
 * @version   1.0
 * @since     2016-10-15
 *****************************************************/

#ifndef SPACESHOOTER_PLAYER
	#define SPACESHOOTER_PLAYER

// include the sdl
#ifdef _WIN32
  #include <SDL.h>
#endif

#ifdef __linux
  #include <SDL2/SDL.h>
#endif

#include "Eventlistner.h"
#include "TextureLoader.h"
#include "WindowElements.h"
#include "Bullets.h"

class Player{
	private:
		TextureLoader *_textureLoader = NULL;
		void init();
	public:
		Player(Eventlistner&, SDL_Renderer*);
		void attachEventListners(Eventlistner &);
		void render();
};

// a namespace containing movement of player
namespace PlayerEvent{
	// movement of player 
	extern void _moveLeft(SDL_Event);
	extern void _attack(SDL_Event);
	extern void _moveRight(SDL_Event);
	extern void _moveDown(SDL_Event);
	extern void _moveUp(SDL_Event);
}
#endif