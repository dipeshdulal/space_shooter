/*****************************************************
 * Class implementation of the eventlistner
 *
 * @author    Dipesh Dulal
 * @version   1.0
 * @since     2016-10-16
 * @modified  2016-10-16
 *****************************************************/

#include "Eventlistner.h"
#include <iostream>

// include the sdl
#ifdef _WIN32
  #include <SDL.h>
#endif

#ifdef __linux
  #include <SDL2/SDL.h>
#endif

void Eventlistner::getEvent(SDL_Event* evt){
  SDL_PollEvent(evt);
}

bool Eventlistner::initialize(){

  getEvent(&events);
  // if quit registers just quit.
  // A fallback for the application
  if(events.type == SDL_QUIT){
    return false;
  }
  return true;

}

void Eventlistner::subscribe(std::string a, void (*func)(SDL_Event)){
  // store the key and function pointer in an structure

  std::cout << a << std::endl;
  func(events);
}
