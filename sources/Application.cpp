/**************************************************
 * Implementation of the main class
 *
 * @author     Dipesh Dulal, Abhimanyu Pandey
 * @version    1.0
 * @since      2016-10-15
 **************************************************/

#include "Application.h"
#include <cstdio>
#include <iostream>
#include <vector>

#ifdef _WIN32
  #include <SDL.h>
#endif

#ifdef __linux
  #include <SDL2/SDL.h>
#endif

#include "SDL_util.h"
#include "Eventlistner.h"
#include "FrameRate.h"
#include "TextureLoader.h"
#include "Player.h"
#include "Bullet.h"

// constructor
Application::Application(){
  windowElements.window = NULL;
  windowElements.renderer = NULL;
}

void renderPlayerBullets(){
  for(unsigned int i = 0; i < playerBullets.size();i++){
    playerBullets[i].renderBullet();
  }  
}

int Application::start(){

  if(!initialize()){
    return -1;
  }


  Eventlistner evt;
  FrameRate frameRate;
  TextureLoader loader(windowElements.renderer);
  Player player(evt, windowElements.renderer);

  loader.load("resources/darkPurple.png");

  // SDL_Rect src = {211,941,99,75};
  // SDL_Rect dst = {100,100,99/2,75/2};

  // the main game loop where all the rendering stuff takes place
  while(evt.initialize()){
    // this is the main game loop
    frameRate.start();
    loader.renderTexture(NULL, NULL);
    player.render();
    renderPlayerBullets();
    loader.presentRenderer();
  }

  return 0;
}

// Initialize all the modules and allocate memory to assets
bool Application::initialize(){

  // initialize the SDL
  if(!SDL_util::initialize()){
    printf("Could not initialize SDL: %s\n", SDL_GetError());
    return false;
  }

  // creating window to draw on
  windowElements.window = SDL_CreateWindow(
      "Spacee Shooter",
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      windowElements.WINDOW_WIDTH,
      windowElements.WINDOW_HEIGHT,
      SDL_WINDOW_SHOWN
  );

  if( windowElements.window == NULL){
    // window creation failed
    printf("Couldnot create window, SDL_window ERROR: %s\n",SDL_GetError());
    return false;
  }

  // creating renderer that draws on the window
  windowElements.renderer = SDL_CreateRenderer(windowElements.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

  if( windowElements.renderer == NULL){
    // renderer creation failed
    printf("Couldnot create renderer, SDL_Renderer ERROR: %s\n", SDL_GetError());
    return false;
  }

  // set the drawing color
  SDL_SetRenderDrawColor(windowElements.renderer, 129, 207, 224, 0xFF);

  // set the hardware independant logical size for the renderer
  SDL_RenderSetLogicalSize(windowElements.renderer, windowElements.WINDOW_WIDTH, windowElements.WINDOW_HEIGHT);

  return true;
}

// to terminate all the application processes and clear memory
void Application::terminate(){

  SDL_DestroyRenderer(windowElements.renderer);
  windowElements.renderer = NULL;

  SDL_DestroyWindow(windowElements.window);
  windowElements.window = NULL;

  SDL_util::terminate();
}
