/************************************************************
 * Implementation of SDL_util class
 *
 * @author      Dipesh Dulal
 * @version     1.0
 * @since       2016-10-15
 ************************************************************/
 // if we are on a windows system
 #ifdef _WIN32
   #include <SDL.h>
   #include <SDL_image.h>
   #include <SDL_ttf.h>
   #include <SDL_mixer.h>
 #endif

 // if we are on a linux system
 #ifdef __linux
   #include <SDL2/SDL.h>
   #include <SDL2/SDL_image.h>
   #include <SDL2/SDL_ttf.h>
   #include <SDL2/SDL_mixer.h>
 #endif

#include <cstdio>
#include <iostream>
#include "SDL_util.h"
#include "WindowElements.h"

namespace SDL_util{

  bool initialize(){
    // initialize SDL subsystems
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
      printf("SDL couldnot initialize! SDL ERROR: %s \n", SDL_GetError());
      return false;
    }

    // initialize image processing
    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if(!(IMG_Init(imgFlags) & imgFlags)){
      printf("SDL_image could not be initialized! SDL_image ERROR: %s\n", IMG_GetError());
      return false;
    }

    // initialize the sdl ttf
    if(TTF_Init() == -1){
      printf("SDL_ttf could not be initialized! SDL_ttf ERROR: %s\n ", TTF_GetError());
      return false;
    }

    
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
      printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
      //success = false;
      return false;
    }


    return true;

  }



  // terminate all the subsystems relating to SDL
  void terminate(){
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
  }
}
