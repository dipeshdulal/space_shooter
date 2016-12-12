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
	_posX = x;
	_posY = y;
	_textureLoader = new TextureLoader(renderer);
	init();
}

void Bullet::init(){
	_textureLoader->load("resources/sheet.png");
}

void Bullet::renderBullet(){
	FrameRate fr;
	while(true){
		fr.start();
		if(_posY < 0){
			break;
		}
		_posY -= speed;
		cout << _posY << endl;e
		SDL_Rect bulletPos = {_posX, _posY, 9/2,54/2};
		_textureLoader->renderTexture(&_bulletPos, &bulletPos);
		_textureLoader->presentRenderer();
	}
}


