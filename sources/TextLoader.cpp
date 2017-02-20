#include "TextLoader.h"
#include <string>
#include <iostream>

using namespace std;

TextLoader::TextLoader(string ttf, SDL_Renderer* renderer){
	_font = TTF_OpenFont(ttf.c_str(), 16);
	_renderer = renderer;
	if(_font == NULL)
		cout << "Font Not Opened." << endl;
}

void TextLoader::loadText(string text, SDL_Color color){
	_surface = TTF_RenderText_Solid(_font, text.c_str(), color);

	if(_surface == NULL){
		cout << "Unable to render text surface! Error: " << TTF_GetError() << endl; 
	}else{
		_texture = SDL_CreateTextureFromSurface(_renderer, _surface);
		if(_texture == NULL){
			cout << "Unable to create texture from rendered text! Error: " << SDL_GetError() << endl;
 		}else{
 			_width = _surface->w;
 			_height = _surface->h;
 		}
 		SDL_FreeSurface(_surface);
 		_surface = nullptr;
	}

}


void TextLoader::render(int x, int y, int scale){
	SDL_Rect destination = { x, y, _width * scale, _height * scale };
	SDL_Rect source = {0, 0, _width, _height};
	SDL_RenderCopy(_renderer, _texture, &source, &destination);
	SDL_DestroyTexture(_texture);
}
