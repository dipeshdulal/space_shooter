#include "Bullets.h"

// to add the bullet inside the bullet vector
void Bullets::addBullet(Bullet bullet){
  if(this->bullet.size() < 4){
    this->bullet.push_back(bullet);
  }
}

// to remove the bullet inside the 
// bullet vector feed directly from the loop
void Bullets::removeBullet(unsigned int index){
  bullet.erase(bullet.begin()+index);
}

void Bullets::renderIndividualBullet(unsigned int index){
  int x,y,speed;
  bullet[index].getPosXY(x,y);
  bullet[index].getSpeed(speed);
  y -= speed;
  bullet[index].setPosXY(x,y);
  bullet[index].render();
}

// render all the bullets avialable to the class
void Bullets::renderBullets(){
  for(unsigned int i = 0; i < bullet.size(); i++){
    int x,y;
    bullet[i].getPosXY(x,y);
    cout << x << ", " << y << endl;
    if(y < 0){
      // bullet is out of the screen remove the bullet from vector
      removeBullet(i);    
      break;
    }
    renderIndividualBullet(i);
  }
}

Bullets playerBullets;