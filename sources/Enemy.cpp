/*****************************************************
 * Implementation fo Enemy class
 *
 * @author    Dipesh Dulal
 * @version   1.0
 * @since     2016-12-12
 *****************************************************/

#include "Enemy.h"
#include "FrameRate.h"

// Enemy constructor
Enemy::Enemy(int x, int y, SDL_Renderer* renderer){
	_posX = x;
	_posY = y;
	speed = 0.01;
	_textureLoader = new TextureLoader(renderer);
	init();
}

void Enemy::init(){
	_textureLoader->load("resources/sheet.png");
}


void Enemy::getSpeed(float &s){
	s = speed;
}

void Enemy::setSpeed(float s){
	speed = s;
}

void Enemy::getPosXY(int &x, int &y){
	x = _posX;
	y = _posY;
}

Enemy::Enemy(){
	speed = 0.01;
}

void Enemy::type(int i){
	_type = i;
}

Enemy::~Enemy(){
	_textureLoader = nullptr;
}

// to set the position x and y of the Enemy
void Enemy::setPosXY(int x, int y){
	_posX = x;
	_posY = y;
}

void Enemy::render(){
	switch(_type){
		case 0:
			_enemyPos.x = 425;
			_enemyPos.y = 384;
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
	}
	SDL_Rect enemyPos = {_posX, _posY, 93/2, 84/2};
    _textureLoader->renderTexture(&_enemyPos, &enemyPos);
}


