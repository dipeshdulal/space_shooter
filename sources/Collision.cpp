
#include <iostream>
#include "Collision.h"
#include "Bullets.h"
#include "Enemys.h"
#include "Player.h"

using namespace std;

bool becollision = false;
bool pecollision = false;

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
			
			if(!(BECollisionDetected() && becollision) ){
				becollision = false;
			}

			if(BECollisionDetected() && !becollision){
				becollision = true;
				cout << "BE Collision" << endl;
				return true;
			}
			
			// return BECollisionDetected();
		}
	}

	// bullets.getPosXY(PosX_bullet,PosY_bullet);

	// enemys.getPosXY(PosX_enemy,PosY_enemy);
	// delete[] enemysArray;
	// delete[] bulletArray;
	return false;
}

bool Collision::BECollisionDetected(){
	if(PosY_enemy+84/2<=PosY_bullet && PosY_bullet<=PosY_enemy+84/2+20 ){
	//cout<<"Y Collision"<<endl;
	//cout<<"Bullet :"<<PosX_bullet<<", "<<PosY_bullet<<endl;	
		if(PosX_bullet>=PosX_enemy && PosX_bullet<= PosX_enemy+93/2){
	//	cout<<"X Collision"<<endl;
	//	cout<<"Enemy: "<<PosX_enemy<<","<<PosY_enemy<<endl;
			return true;
		}
		else {
			return false;
		}

	}else{
		return false;
	}
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
			cout << "Enemy Player Collision" << endl;
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
		bool a = PosX_enemy + 93/2 >= (PosX_player + 10) && PosX_enemy <= (PosX_player + 10);
		bool b = PosX_enemy + 93/2 >= (PosX_player - 10) && PosX_enemy <= (PosX_player - 10);
		return a || b;
	}else{
		return false;
	}
}