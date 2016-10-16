/*****************************************************
 * The class to listen to all the events.
 *
 * @author    Dipesh Dulal
 * @version   1.0
 * @since     2016-10-16
 * @modified  2016-10-16
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

struct Eventlistner_lists {
  std::string key;
  std::vector<void *(*)(SDL_Event)> functions;
};

class Eventlistner{
  private:
    void getEvent(SDL_Event*);
    std::vector<struct Eventlistner_lists> lists;
  public:
    bool initialize();
    SDL_Event events;
    void subscribe(std::string, void (*function)(SDL_Event));
};

#endif
