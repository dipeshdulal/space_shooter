
#include <iostream>
#include "Collision.h"
#include "Bullets.h"
#include "Enemys.h"
#include "Player.h"

using namespace std;

bool becollision = false;
bool pecollision = false;
// int previousIndexCol

bool Collision::isCollidedBE(Bullets bullets,Enemys enemys){
	
	int index = enemys.getIndex();
	Enemy* enemysArray = enemys.getEnemys();

	int bulletIndex = bullets.getIndex();
	Bullet* bulletArray = bullets.getBullets();

	// cout << index << endl;
	// cout << bulletIndex << endl;
	for(int i = 0; i < index; i++){
		enemysArray[i].getPosXY(PosX_enemy, PosY_enemy);
		for(int j = 0; j < bulletIndex;  j++){
			bulletArray[j].getPosXY(PosX_bullet, PosY_bullet);
			// if(!BECollisionDetected() && !becollision){
			// 	continue;
			// }
			// cout << PosX_bullet << ":" << PosY_bullet << endl;

			if(!(BECollisionDetected() && becollision) ){
				becollision = false;
				// continue;
			}

			if(BECollisionDetected() && !becollision){
				becollision = true;
				bulletCollisionIndex = j;
				enemyCollisionIndex = i;
				// break;
				return true;
			}
			
			// return BECollisionDetected();
		}
		// return becollision;
	}
	

	return false;
	// bullets.getPosXY(PosX_bullet,PosY_bullet);

	// enemys.getPosXY(PosX_enemy,PosY_enemy); 
}

void Collision::getEnemyCollisionPosition(int& x, int& y){
	x = PosX_enemy;
	y = PosY_enemy;
}

int Collision::getBulletCollisionIndex(){
	return bulletCollisionIndex;
}

int Collision::getEnemyCollisionIndex(){
	return enemyCollisionIndex;
}

bool Collision::BECollisionDetected(){
	// if(PosY_enemy+84/2 <= PosY_bullet && PosY_bullet <=PosY_enemy+84/2+20 ){
	//cout<<"Y Collision"<<endl;
	//cout<<"Bullet :"<<PosX_bullet<<", "<<PosY_bullet<<endl;	
		if(PosY_bullet == PosY_enemy){
			if(PosX_bullet >= PosX_enemy && PosX_bullet <= PosX_enemy+93/2){
			//	cout<<"X Collision"<<endl;
			//	cout<<"Enemy: "<<PosX_enemy<<","<<PosY_enemy<<endl;
				return true;
			}
			else {
				return false;
			}	
		}else{return false; }
		

	// }else{
		// return false;
	// }
}


bool Collision::isCollidedPE(Player player, Enemys enemys){

	int index = enemys.getIndex();
	Enemy* enemysArray = enemys.getEnemys();

	player.getPosXY(PosX_player, PosY_player);

	for(int i = 0; i < index; i++){

		enemysArray[i].getPosXY(PosX_enemy, PosY_enemy);

		if(!(PECollisionDetected() && pecollision) ){
			pecollision = false;
		}

		if(PECollisionDetected() && !pecollision){
			pecollision = true;
			// cout << "Enemy Player Collision" << endl;
			return true;
		}

	}
	// enemys.getPosXY(PosX_enemy,PosY_enemy);
	// player.getPosXY(PosX_player,PosY_player);
	// //cout<<PosX_player<<", "<<PosY_player<<endl;
	// if(PosY_enemy+84/2==PosX_player){
	// // cout<<"Y Collision"<<endl;
	// 	if(PosX_enemy+93/2==PosX_player){
	// 	// cout<<"X Collision"<<endl;
	// 		cout << "Player Enemy Collision" << endl;
	// 		return true;
	// 	}
	// 	else{
	// 		return true;

	// 	}
	// }
	// else{
	// 	return false;

	// }
	return false;
}

bool Collision::PECollisionDetected(){
	if(PosY_enemy == PosY_player){
		// cout<<"Y Collision"<<endl;
		bool a = PosX_enemy + 93/2 >= (PosX_player + 20) && PosX_enemy <= (PosX_player + 20);
		bool b = PosX_enemy + 93/2 >= (PosX_player - 20) && PosX_enemy <= (PosX_player - 20);
		return a || b;
	}else{
		return false;
	}
}