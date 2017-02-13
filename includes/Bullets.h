#ifndef SPACESHOOTER_BULLETS
		#define SPACESHOOTER_BULLETS
	#include "Bullet.h"
	#include <vector>
	#include <iostream>

	using namespace std;

	// this should bind all the bullet 
	// and should be responsible to 
	// render all the bullets to the screen
	class Bullets{
		private:
			Bullet *bullet = new Bullet[30];
			int bulletIndex;
			void removeBullet(int);
			int _posX,_posY;
			void renderIndividualBullet(int);
		public:
			void addBullet(Bullet);
			void renderBullets();
			Bullets(){ bulletIndex = 0; }
			Bullet* getBullets();
			int getIndex();

	};

	extern Bullets playerBullets;

#endif