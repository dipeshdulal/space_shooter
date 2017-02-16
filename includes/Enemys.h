/*****************************************************
 * Implementation fo Enemys class
 *
 * @author    Dipesh Dulal, Dexter Shrestha
 * @version   1.0
 * @since     2017-02-11
 *****************************************************/
#ifndef SPACESHOOTER_ENEMYS
		#define SPACESHOOTER_ENEMYS

	#include <iostream>
	#include "Enemy.h"

	// binding class for adding and removing the enemys from screen
	// later collider is supposed to be added for score counts
	// and some other stuffs
	class Enemys{
		private: 
			Enemy *enemy = new Enemy[30];
			int index;
			// float speed;
			void removeEnemy(int);
			int _posX,_posY;
			void renderIndividualEnemy(int);
		public:
			void addEnemy(Enemy);
			void renderEnemy();
			void push(int, Enemy);
			Enemys() {
				index = 0;
				// speed
			}
			Enemy* getEnemys();
			int getIndex();
			void remove(int);
	};

	extern Enemys enemys;

#endif