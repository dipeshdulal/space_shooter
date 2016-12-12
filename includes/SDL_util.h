/************************************************************
 * Several utility functions wrapped in the namespace
 *
 * @author      Dipesh Dulal
 * @version     1.0
 * @since       2016-10-15
 ************************************************************/

#ifndef SPACESHOOTER_SDL_UTIL
  #define SPACESHOOTER_SDL_UTIL

  #include <string>

  struct SDL_Color;
  struct SDL_Rect;
  struct SDL_Renderer;
  struct SDL_Texture;
  struct SDL_Surface;
  struct WindowElements;

  namespace SDL_util{

    // to initialize all the sdl subsystems
    bool initialize();

    // to create texture (a GPU rendred object) from surface( a software rendered object)
    SDL_Texture* create_texture_from_surface(WindowElements* windowElements, SDL_Surface* surface);

    void terminate();
  }

#endif
// asdasd
