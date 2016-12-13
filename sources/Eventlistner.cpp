/*****************************************************
 * Class implementation of the eventlistner
 *
 * @author    Dipesh Dulal
 * @version   1.0
 * @since     2016-10-16
 *****************************************************/

#include "Eventlistner.h"
#include <iostream>
#include <vector>

// include the sdl
#ifdef _WIN32
  #include <SDL.h>
#endif

#ifdef __linux
  #include <SDL2/SDL.h>
#endif

void Eventlistner::getEvent(SDL_Event* evt){
  SDL_PollEvent(evt);
  const Uint8* keys = SDL_GetKeyboardState( NULL );

  if(keys[SDL_SCANCODE_UP]){
    emit("UP_KEY");
  }

  if(keys[SDL_SCANCODE_DOWN]){
    emit("DOWN_KEY");
  }

  if(keys[SDL_SCANCODE_LEFT]){
    emit("LEFT_KEY");
  }

  if(keys[SDL_SCANCODE_RIGHT]){
    emit("RIGHT_KEY");
  }

  if(keys[SDL_SCANCODE_SPACE]){
    emit("ATTACK_KEY");
  }

  if(keys[SDL_SCANCODE_ESCAPE]){
    emit("ESCAPE_KEY");
  }

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


void Eventlistner::call(){


  // if(keys[SDL_SCANCODE_UP]){
  //   emit("UP_KEY");
  // }

  // if(keys[SDL_SCANCODE_DOWN]){
  //   emit("DOWN_KEY");
  // }

  // if(keys[SDL_SCANCODE_LEFT]){
  //   emit("LEFT_KEY");
  // }

  // if(keys[SDL_SCANCODE_RIGHT]){
  //   emit("RIGHT_KEY");
  // }

  // if(keys[SDL_SCANCODE_SPACE]){
  //   emit("ATTACK_KEY");
  // }

  // if(keys[SDL_SCANCODE_ESCAPE]){
  //   emit("ESCAPE_KEY");
  // }

}

void Eventlistner::on(string a, functionPointer func){
  // store the key and function pointer in an structure
  // if there are alreadt key then store the keys with the
  // functions and if there are no keys then make the new entry
  // on the vector lists
    if(a == "LEFT_KEY"){
      leftKey.push_back(func);
    }
    if(a == "RIGHT_KEY"){
      rightKey.push_back(func);
    }
    if(a == "UP_KEY"){
      upKey.push_back(func);
    }
    if(a =="DOWN_KEY"){
      downKey.push_back(func);
    }
    if(a == "ESC_KEY"){
      escKey.push_back(func);
    }
    if(a == "ATTACK_KEY"){
      attackKey.push_back(func);
    }
}

void Eventlistner::emit(string a){


  if(a == "LEFT_KEY"){
    for(unsigned int i = 0; i < leftKey.size(); i++){
      (*leftKey[i])(events);
    }
  }
  if(a == "RIGHT_KEY"){
    for(unsigned int i = 0; i < rightKey.size(); i++){
      (*rightKey[i])(events);
    }
  }
  if(a == "UP_KEY"){
    for(unsigned int i = 0; i < upKey.size(); i++){
      (*upKey[i])(events);
    }
  }
  if(a =="DOWN_KEY"){
    for(unsigned int i = 0; i < downKey.size(); i++){
      (*downKey[i])(events);
    }
  }
  if(a == "ESC_KEY"){
    for(unsigned int i = 0; i < escKey.size(); i++){
      (*escKey[i])(events);
    }
  }
  if(a == "ATTACK_KEY"){
    for(unsigned int i = 0; i < attackKey.size(); i++){
      (*attackKey[i])(events);
    }
  }
}
