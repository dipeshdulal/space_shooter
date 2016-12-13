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
			vector<Bullet> bullet;
			void removeBullet(unsigned int);
			void renderIndividualBullet(unsigned int);
		public:
			void addBullet(Bullet);
			void renderBullets();

	};

	extern Bullets playerBullets;

#endif