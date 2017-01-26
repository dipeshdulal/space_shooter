#include "Bullets.h"
#include "Bullet.h"

// to add the bullet inside the bullet vector
void Bullets::addBullet(Bullet bullet){
    this->bullet[bulletIndex] = bullet;
    bulletIndex++;
}

// to remove the bullet inside the 
// bullet vector feed directly from the loop
void Bullets::removeBullet(int index){
  
  Bullet *tmp = new Bullet[30];
  for (int i = index; i < 30; ++i)
    bullet[i] = bullet[i + 1]; 

  for(int i = 0; i < 30; i++){
    tmp[i] = bullet[i];
  }

  bullet = nullptr;
  delete[] bullet;
  bullet = new Bullet[30];

  for(int i = 0; i < 30; i++){
    bullet[i] = tmp[i];
  }

  tmp = nullptr;
  delete[] tmp;
  bulletIndex--;
}

void Bullets::renderIndividualBullet(int index){
  int x,y,speed;
  bullet[index].getPosXY(x,y);
  bullet[index].getSpeed(speed);
  y -= speed;
  bullet[index].setPosXY(x,y);
  bullet[index].render();
}

// render all the bullets avialable to the class
void Bullets::renderBullets(){
  for(int i = 0; i < bulletIndex; i++){
    int x,y;
    bullet[i].getPosXY(x,y);
    cout << x << ", " << y << endl;
    if(y < 0){
      // bullet is out of the screen remove the bullet from vector
      removeBullet(i);    
      continue;
    }
    renderIndividualBullet(i);
  }
}

Bullets playerBullets;