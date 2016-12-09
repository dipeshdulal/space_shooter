/**************************************************
 * Implementation of the main class
 *
 * @author     Dipesh Dulal, Abhimanyu 
 * @version    1.0
 * @since      2016-10-15
 **************************************************/

#include "Application.h"
#include <cstdio>
#include <iostream>

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

// constructor
Application::Application(){
  windowElements.window = NULL;
  windowElements.renderer = NULL;
}

void rightKey(SDL_Event e){
  printf("Right key pressed \n");
}

void sdl(SDL_Event e){
  printf("Left key pressed \n");
  // TextureLoader loader(windowElements.renderer);
  // loader.load("resources/simon.jpg");
  // loader.renderTexture(&a, &rect, windowElements.window);
  // SDL_Rect rect = {0,0,32,32};
  // SDL_Rect a = {640/2,480/2,32,32};
}

void leftAgain(SDL_Event e){
  printf("another function for left key \n");
}

void attackFunction(SDL_Event e){
  printf("Attack key pressed \n");
}

void upFunction(SDL_Event e){
  printf("Up key pressed \n");
}

void downFunction(SDL_Event e){
  printf("Down key pressed \n");
}

int Application::start(){

  if(!initialize()){
    return -1;
  }

  Eventlistner evt;
  FrameRate frameRate;
  TextureLoader loader(windowElements.renderer);

  loader.load("resources/simon.jpg");
  loader.renderTexture(NULL, NULL);
  loader.load("resources/tech_logo.png");

  SDL_Rect rect = {0,0,1945,1945};
  SDL_Rect a = {640/2,480/2,100,100};

  evt.on("LEFT_KEY", &sdl);
  // evt.on("RIGHT_KEY", &rightKey);
  // evt.on("ATTACK_KEY", &attackFunction);
  // evt.on("UP_KEY", &upFunction);
  // evt.on("DOWN_KEY", &downFunction);


  // the main game loop where all the rendering stuff takes place
  while(evt.initialize()){
    // this is the main game loop
    frameRate.start();

      
    loader.renderTexture(&rect,&a);
    loader.presentTexture();

    // calling all the function calls 
    evt.call();

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
