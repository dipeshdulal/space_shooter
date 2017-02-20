/**************************************************
 * Implementation of the main class
 *
 * @author     Dipesh Dulal, Abhimanyu Pandey, Dexter Shrestha
 * @version    1.0
 * @since      2016-10-15
 **************************************************/

#include "Application.h"
#include <cstdio>
#include <iostream>
#include <vector>
#include <future>

using namespace std;

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
#include "Bullets.h"
#include "Enemy.h"
#include "Enemys.h"
#include "Collision.h"
#include "Sound.h"
#include "TextLoader.h"
#include "Animation.h"

// constructor
Application::Application(){
  windowElements.window = NULL;
  windowElements.renderer = NULL;
}

bool gAnimationTrigger = false;
int posX = -100;
int posY = -100;
bool gameover = false;

int Application::start(){

  if(!initialize()){
    return -1;
  }

  TextLoader textLoader("resources/font.ttf", windowElements.renderer);
  SDL_Color color = {255,255,255,255};
  Eventlistner evt;
  FrameRate frameRate;
  TextureLoader loader(windowElements.renderer);
  Player player(evt, windowElements.renderer);
  // future<void> fut = async(renderPlayerBullets);
  Animation animator(windowElements.renderer);
  loader.load("resources/darkPurple.png");
  Enemy enemy(0, 0, windowElements.renderer);
  Collision collider;
  string shooting = "resources/shooting_sound.wav";
  string explosion = "resources/explosion.wav";

  // enemys.addEnemy(enemy);
  // SDL_Rect src = {211,941,99,75};
  // SDL_Rect dst = {100,100,99/2,75/2};
  gBulletSound.load(shooting);
  gExplosionSound.load(explosion);

  // the main game loop where all the rendering stuff takes place
  while(evt.initialize()){
    // this is the main game loop
    if(!gameover){
      frameRate.start();
      loader.renderTexture(NULL, NULL);
      player.render();
      playerBullets.renderBullets();
    // enemys.render();
    // renderPlayerBullets();
    // fut.get();
      textLoader.loadText("Time: " + to_string((frameRate.getTicks()/100)%60), color);
      textLoader.render(10,10,1);
      textLoader.loadText("Score: " + to_string(enemys.getscore()), color);
      textLoader.render(640-110,10,1);

    // animator.Animate(10,10,windowElements.renderer,frameRate);

      animator.Animate(posX, posY, windowElements.renderer, frameRate, gAnimationTrigger);
      gAnimationTrigger = false;

      if(collider.isCollidedBE(playerBullets, enemys)){
        cout<<"CollisionBE"<<endl;
        int enemyIndex = collider.getEnemyCollisionIndex();
        int bulletIndex = collider.getBulletCollisionIndex();

       // get postion
        gAnimationTrigger = true;
        collider.getEnemyCollisionPosition(posX, posY);
        playerBullets.remove(bulletIndex);
        enemys.remove(enemyIndex);
        gExplosionSound.play();
      // bulletIndex.remove(enemyIndex);
        // positionma eplode garaune
      }
      if(collider.isCollidedPE(player,enemys)){
        cout<<"CollisionPE"<<endl;
        int enemyIndex = collider.getEnemyCollisionIndex();
        enemys.remove(enemyIndex);
        collider.getEnemyCollisionPosition(posX, posY);
        gAnimationTrigger = true;
        gExplosionSound.play();      
        gameover = animator.Gameover(windowElements.renderer, textLoader);
      //int 
      // enemy index
      }  
      enemys.push(frameRate.getTicks(), enemy);
      enemys.renderEnemy();
    }
    
    loader.presentRenderer();
    evt.call(frameRate);
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
    "Space Shooter",
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
