#ifndef SPACESHOOTER_BULLETS
		#define SPACESHOOTER_BULLETS
	#include "Bullet.h"
	#include <vector>
	#include <iostream>

	using namespace std;
	// contains bullets;
	extern vector<Bullet> playerBullets;
	extern vector<Bullet> enemyBullets;
	extern void renderPlayerBullets();

#endif