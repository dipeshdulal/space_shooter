/*****************************************************
 * Texture loader class. Used to display the images
 * and load images to screen.
 *
 * @author    Dipesh Dulal
 * @version   1.0
 * @since     2016-12-11
 *****************************************************/

#ifndef SPACESHOOTER_TEXTURELOADER
 #define SPACESHOOTER_TEXTURELOADER

 //changed from another computer
 // include the sdl
#ifdef _WIN32
  #include <SDL.h>
#endif

#ifdef __linux
  #include <SDL2/SDL.h>
  #include <SDL2/SDL_image.h>
#endif

#include <iostream>
#include <string>

using namespace std;

class TextureLoader{
	private: 
		SDL_Texture* _texture = NULL; 	
		SDL_Surface* _surface = NULL;
		SDL_Renderer* _renderer = NULL;
		
	public:
	
		// constructor that takes the window and window renderer
		TextureLoader(SDL_Renderer*);

		SDL_Texture* load(string path); 
		~TextureLoader();
		void renderTexture(SDL_Rect*, SDL_Rect*, SDL_Texture* = NULL);
		void presentRenderer();
		void getTextureWidthHeight(int &, int &, SDL_Texture* = NULL);

		// to get previously loaded texture 
		SDL_Texture* getOldTexture(){
			return _texture;
		}
};

#endif
