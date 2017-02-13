#ifndef WINDOW_ELEMENTS
  #define WINDOW_ELEMENTS

struct SDL_Window;
struct SDL_Renderer;

struct WindowElements{
  SDL_Window* window;
  SDL_Renderer* renderer;

  const int WINDOW_WIDTH = 640;
  const int WINDOW_HEIGHT = 480;
};

#endif
