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
void Enemy::enemytype(int i){
	index = i;
}

Enemy::Enemy(){
	speed = 0.01;
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
	_enemyPos.w = 93;
	_enemyPos.h = 84;
	switch(index){
		
		case 0:
			_enemyPos.x = 425; 
			_enemyPos.y = 468;
		break;
	
		case 1:
			_enemyPos.x = 143;
			_enemyPos.y = 293;
		break;
		
		case 2:	
			_enemyPos.x = 425;
			_enemyPos.y = 552;
		break;

		case 3:
			_enemyPos.x = 423;
			_enemyPos.y = 728;

	}
	SDL_Rect enemyPos = {_posX, _posY, 93/2, 84/2};

	
    _textureLoader -> renderTexture(&_enemyPos, &enemyPos);
}


