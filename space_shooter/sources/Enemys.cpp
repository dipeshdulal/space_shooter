/*****************************************************
 * Implementation fo Enemys class
 *
 * @author    Dipesh Dulal
 * @version   1.0
 * @since     2017-02-11
 *****************************************************/
#include "Enemys.h"
#include "Enemy.h"

void Enemys::removeEnemy(int i){
	Enemy *tmp = new Enemy[30];
	for (int i = index; i < 30; ++i)
		enemy[i] = enemy[i + 1]; 

	for(int i = 0; i < 30; i++){
		tmp[i] = enemy[i];
	}

	enemy = nullptr;
	delete[] enemy;
	enemy = new Enemy[30];
	cout << "Deleted" << endl;
	for(int i = 0; i < 30; i++){
		enemy[i] = tmp[i];
	}

	tmp = nullptr;
	delete[] tmp;
	index--;	
	cout << "ENEMY INDEX: " << index << endl;
}

// render individual enemy at index i
void Enemys::renderIndividualEnemy(int i){
	int x,y;
	enemy[i].getPosXY(x,y);
	float speed;
	enemy[i].getSpeed(speed);
	speed += 0.1;
	enemy[i].setSpeed(speed);
	if(int(speed) % 2){
		y += 1;
	}

	enemy[i].setPosXY(x,y);
	enemy[i].render();
}

void Enemys::addEnemy(Enemy e){
	enemy[index] = e;
	index++;
}

void Enemys::renderEnemy(){
	for(int i = 0; i < index; i++){
		int x,y;
		enemy[i].getPosXY(x,y);
		cout << x << ", " << y << endl;
		// screen height
		if(y > 640){
		    // bullet is out of the screen remove the bullet from vector
			removeEnemy(i);    
			continue;
		}
		renderIndividualEnemy(i);
	}
}

bool enemy_Added = false;

// to push enemy at screen
void Enemys::push(int fr, Enemy enemy){
	fr /= 100;
	// cout << "MOD: " << ( fr % 50 ) << endl;

	// here make this happen more freequently or not based on the level 
	// of the game that is to be added later

	if(( fr % 50 ) == 0) {
		enemy_Added = false;
	}
	if(( fr % 50 ) && !enemy_Added){
		int r = ( rand() % 640 );
		int index = r % 4;
		enemy.enemytype(index);
		enemy.setPosXY(r, 10);
		addEnemy(enemy);
		enemy_Added = true;
	}
}

Enemys enemys;