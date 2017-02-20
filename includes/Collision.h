/*****************************************************
 * Definition for Collision class
 *
 * @author    Dexter Shrestha
 * @version   1.0
 * @since     2017-02-13
 *****************************************************/
#ifndef SPACESHOOTER_COLLISION
		#define SPACESHOOTER_COLLISION
	#include "Bullets.h"
	#include "Enemys.h"
	#include "Player.h"
	#include <iostream>

	using namespace std;

	class Collision{
	private:
		int PosX_bullet,PosY_bullet;
		int PosX_enemy,PosY_enemy;
		int PosX_player,PosY_player;
		int min;
		int bulletCollisionIndex;
		int enemyCollisionIndex;
	public:
		Collision(){};
		bool isCollidedBE(Bullets,Enemys);
		bool isCollidedPE(Player, Enemys);
		bool BECollisionDetected();
		bool PECollisionDetected();
		int getBulletCollisionIndex();
		int getEnemyCollisionIndex();
		void getEnemyCollisionPosition(int&, int&);
	};


#endif
