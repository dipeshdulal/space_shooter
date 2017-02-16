/*****************************************************
 * Core Application Class. Initializes and closes the
 * SDL and contains the main game loop
 *
 * @author    Dipesh Dulal
 * @version   1.0
 * @since     2016-10-15
 *****************************************************/
#ifndef SPACESHOOTER_SOUND
    #define SPACESHOOTER_SOUND

#include "WindowElements.h"

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


#include <string>
using namespace std; 

class Sound{

private:
  Mix_Chunk *music;    

public:
    // Constructor
  void load(string);
  void play();

};

extern Sound gBulletSound;
extern Sound gExplosionSound;

#endif
