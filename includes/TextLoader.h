/*****************************************************
 * Font loader class. Used to display the text passed
 * in the window
 *
 * @author    Dipesh Dulal
 * @version   1.0
 * @since     2017-02-18
 *****************************************************/

#ifndef SPACESHOOTER_TEXTLOADER
 #define SPACESHOOTER_TEXTLOADER

 //changed from another computer
 // include the sdl
#ifdef _WIN32
  #include <SDL.h>
  #include <SDL_ttf.h>
#endif

#ifdef __linux
  #include <SDL2/SDL.h>
  #include <SDL2/SDL_ttf.h>
#endif

#include <iostream>
#include <string>

using namespace std;

class TextLoader{
	TTF_Font *_font;
	SDL_Renderer *_renderer;
	SDL_Surface *_surface;
	SDL_Texture *_texture;
	int _width, _height;

public:
	TextLoader(string, SDL_Renderer*);
	void loadText(string, SDL_Color);
	void render(int, int, int);

};

#endif
