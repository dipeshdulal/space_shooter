#include "Bullets.h"

vector<Bullet> playerBullets;
vector<Bullet> enemyBullets;

void renderPlayerBullets(){
  for(unsigned int i = 0; i < playerBullets.size();i++){
  	int x,y;
  	playerBullets[i].getPosXY(x,y);
  	cout << x << ", "<< y << endl;
  	if(y < 0){
  		cout << "Deleted bullet";
  		playerBullets.erase(playerBullets.begin() + i);
  		renderPlayerBullets();
   	}
  	playerBullets[i].renderBullet();
  }  
}

