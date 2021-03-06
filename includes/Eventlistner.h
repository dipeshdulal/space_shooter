/*****************************************************
 * The class to listen to all the events.
 *
 * @author    Dipesh Dulal
 * @version   1.0
 * @since     2016-10-16
 *****************************************************/

#ifndef SPACESHOOTER_EVENTLISTNER
  #define SPACESHOOTER_EVENTLISTNER

// include the sdl
#ifdef _WIN32
  #include <SDL.h>
#endif

#ifdef __linux
  #include <SDL2/SDL.h>
#endif

#include <vector>
#include <iostream>
#include "FrameRate.h"

using namespace std;

typedef void(*functionPointer)(SDL_Event);

class Eventlistner{
  private:
    void getEvent(SDL_Event*);
    vector<functionPointer> leftKey;
    vector<functionPointer> rightKey;
    vector<functionPointer> upKey;
    vector<functionPointer> downKey;
    vector<functionPointer> attackKey;
    vector<functionPointer> escKey;
    void emit( string );
  public:
    bool initialize();
    SDL_Event events;
    void call(FrameRate);
    void on(string , void (*function)(SDL_Event));
};

#endif
