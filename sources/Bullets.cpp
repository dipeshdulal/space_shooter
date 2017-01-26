#include "Bullets.h"
#include "Bullet.h"

// to add the bullet inside the bullet vector
void Bullets::addBullet(Bullet bullet){
    this->bullet.push_back(bullet);
}

// to remove the bullet inside the 
// bullet vector feed directly from the loop
void Bullets::removeBullet(unsigned int index){
  cout << "vector bullets" << index << endl;
  // create a new vector temporary 
  // delete all the contents of the vector and add all the elements except the
  // returned index
  vector<Bullet> tmp;
  for(unsigned int i = 0; i < bullet.size(); i++){
    if( i != index ) 
      tmp.push_back(bullet[i]);
  }
  bullet.clear();
  vector<Bullet>().swap( bullet );
  for(unsigned int i = 0; i < tmp.size(); i++){
    bullet.push_back(tmp[i]);
  }  
  // delete the tmp array
  tmp.clear();
  vector<Bullet>().swap( tmp );
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
      continue;
    }
    renderIndividualBullet(i);
  }
}

Bullets playerBullets;