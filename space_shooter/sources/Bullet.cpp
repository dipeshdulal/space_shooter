/*****************************************************
 * Implementation fo bullet class
 *
 * @author    Dipesh Dulal
 * @version   1.0
 * @since     2016-12-12
 *****************************************************/

#include "Bullet.h"
#include "FrameRate.h"

// bullet constructor
Bullet::Bullet(int x, int y, SDL_Renderer* renderer){
	// sound goes here
	// Sound.speak();
	_posX = x;
	_posY = y;
	_textureLoader = new TextureLoader(renderer);
	init();
}

void Bullet::init(){
	_textureLoader->load("resources/sheet.png");
}


void Bullet::getSpeed(int &speed){
	speed = this->speed;
}

void Bullet::getPosXY(int &x, int &y){
	x = _posX;
	y = _posY;
}

Bullet::~Bullet(){
	_textureLoader = nullptr;
}

// to set the position x and y of the bullet
void Bullet::setPosXY(int x, int y){
	_posX = x;
	_posY = y;
}

void Bullet::render(){
	SDL_Rect bulletPos = {_posX, _posY, 9/2,54/2};
    _textureLoader->renderTexture(&_bulletPos, &bulletPos);
}


