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
			void renderIndividualEnemy(int);
		public:
			void addEnemy(Enemy);
			void renderEnemy();
			void push(int, Enemy);
			Enemys() {
				index = 0;
				// speed
			}
	};

	extern Enemys enemys;

#endif