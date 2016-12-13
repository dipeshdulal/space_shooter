/**************************************************
 * Implementation of the player class
 *
 * @author     Dipesh Dulal
 * @version    1.0
 * @since      2016-12-11
 **************************************************/

// player class constructor

#include "Player.h"
#include <iostream>
#include "Bullet.h"

using namespace std;
using namespace PlayerEvent;

namespace PlayerPosition{
	int posX, posY;	
	int speed;
	SDL_Rect _srcImage;
	SDL_Rect _dstImage;
}

SDL_Renderer *gRenderer = NULL;

// left key logic 
void PlayerEvent::_moveLeft(SDL_Event e){
	PlayerPosition::posX -= PlayerPosition::speed;
	PlayerPosition::_dstImage.x = PlayerPosition::posX;
	if(PlayerPosition::posX<0) 
	{
		PlayerPosition::posX=0;
	}
}

// right key logic 
void PlayerEvent::_moveRight(SDL_Event e){
	PlayerPosition::posX += PlayerPosition::speed;
	PlayerPosition::_dstImage.x = PlayerPosition::posX;
	if(PlayerPosition::posX>590)
	{
		PlayerPosition::posX=590;
	}
}

// up key logic 
void PlayerEvent::_moveUp(SDL_Event e){
	PlayerPosition::posY -= PlayerPosition::speed;
	PlayerPosition::_dstImage.y = PlayerPosition::posY;
	if(PlayerPosition::posY<0)
	{
		PlayerPosition::posY=0;
	}
}

// down key logic 
void PlayerEvent::_moveDown(SDL_Event e){
	PlayerPosition::posY += PlayerPosition::speed;
	PlayerPosition::_dstImage.y = PlayerPosition::posY;
	if(PlayerPosition::posY>440)
	{
		PlayerPosition::posY=440;

	}
}

// bullet logic or attack logic
void PlayerEvent::_attack(SDL_Event e){
	// Bullet b1(PlayerPosition::posX + 99/4 , PlayerPosition::posY, gRenderer);
	// playerBullets.push_back(b1);
}

void Player::init(){
	PlayerPosition::posX = 640/2;
	PlayerPosition::posY = 480/2;
	PlayerPosition::speed = 1;
	PlayerPosition::_srcImage.x = 211;
	PlayerPosition::_srcImage.y = 941;
	PlayerPosition::_srcImage.w = 99;
	PlayerPosition::_srcImage.h = 75;
	PlayerPosition::_dstImage.x = PlayerPosition::posX;
	PlayerPosition::_dstImage.y = PlayerPosition::posY;
	PlayerPosition::_dstImage.w = 99/2;
	PlayerPosition::_dstImage.h = 75/2;
}

Player::Player(Eventlistner& listner, SDL_Renderer *renderer){
	init();	
	gRenderer = renderer;
	_textureLoader = new TextureLoader(renderer);
	_textureLoader->load("resources/sheet.png");
	attachEventListners(listner);  
}

// to render the player
void Player::render(){
	_textureLoader->renderTexture(&PlayerPosition::_srcImage, &PlayerPosition::_dstImage);		
}

// to attachEventListners
void Player::attachEventListners(Eventlistner &listner){
	listner.on("LEFT_KEY", &_moveLeft)  ;
	listner.on("RIGHT_KEY", &_moveRight);
	listner.on("ATTACK_KEY", &_attack);
	listner.on("UP_KEY", &_moveUp);
	listner.on("DOWN_KEY", &_moveDown);
}