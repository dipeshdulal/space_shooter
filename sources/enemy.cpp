#include "Enemy.h"
#include <iostream>


using namespace std;
using namespace EnemyEvent;


namespace EnemyPosition{
	int posX,posY;
	int speed;
	SDL_Rect _srcImage;
	SDL_Rect _dstImage;
}

SDL_Renderer *gRenderer = NULL;


//void EnemyEvent();


void Enemy::init()
{
	EnemyPosition::posX = 240/2;
	EnemyPosition::posy = 0;
	EnemyPosition::speed = 1;
	EnemyPosition::_srcImage.x = 120;
	EnemyPosition::_srcImage.y = 604;
	EnemyPosition::_srcImage.w = 104;
	EnemyPosition::_srcImage.h = 84;
	EnemyPosition::_dstImage.x = EnemyPosition::posX;
	EnemyPosition::_dstImage.y = EnemyPosition::posY;
	EnemyPosition::_dstImage.w = 104/2
	EnemyPosition::_dstImage.h = 84/2;
}

Enemy::Enemy(SDL_Render *render){
	init();
	gRender = render;
	textureLoader = new TextureLoader(render);
	textureLoader->load("resources/sheet.png");
}

void Enemy::render()
{
	textureLoader->renderTexture(&EnemyPosition::_srcImage, &PlayerPosition::_dstImage);
}