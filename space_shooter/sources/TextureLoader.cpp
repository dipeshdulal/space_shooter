#include "TextureLoader.h"

using namespace std;

// constructor loading the renderer
TextureLoader::TextureLoader(SDL_Renderer* renderer){
	_renderer = renderer;
}


SDL_Texture* TextureLoader::load(string path){
	// this returns a sdl surface
	
	_surface = IMG_Load( path.c_str() );
	if(_surface == NULL){
		cout << "Image load error " << endl;
		cout << IMG_GetError() << endl; 
		return NULL;
	}

	_texture = SDL_CreateTextureFromSurface(_renderer, _surface);

	if(_texture == NULL){
		cout << "Unable to create texture. " << endl;
		cout << SDL_GetError() << endl;
		return NULL;
	}

	// to clear the loaded surface
	SDL_FreeSurface( _surface );
	_surface = NULL;

	return _texture;
}


// destructor
TextureLoader::~TextureLoader(){
	// freeing the memory

	// clearing the screen
	// SDL_RenderClear(_renderer);
	
	SDL_DestroyTexture(_texture);
	_texture = NULL;
	_renderer = NULL;
}

void TextureLoader::renderTexture(SDL_Rect* srcRect,SDL_Rect* dstRect, SDL_Texture* texture){
			
	if(texture == NULL){
		// if((_renderer == NULL) || (_texture == NULL)){
		// 	cout << "Please load texture or renderer." << endl;
		// 	cout << " Run load member of texture loader before passing default argument." << endl;
		// 	return;
		// }
		texture = _texture;
	}		

	// copying texture to screen
	SDL_RenderCopy(_renderer, texture, srcRect, dstRect);
	
}

void TextureLoader::presentRenderer(){
	// updating the screen
	SDL_RenderPresent( _renderer );
}

// to get the texture width and height
void TextureLoader::getTextureWidthHeight(int& w, int& h, SDL_Texture* texture){
	if(texture == NULL){
		if(_texture == NULL)
			cout << "Please load texture." << endl;
		texture = _texture;
	}
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);	
}

