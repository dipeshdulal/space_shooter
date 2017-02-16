#include "Sound.h"
#include <iostream>
#include <string>

using namespace std;

void Sound::load(string path){

	cout << path << endl;
	music = Mix_LoadWAV(path.c_str());
	if(music == NULL){
		cout << "Failed to load music" << Mix_GetError() << endl;
	}
}


void Sound::play(){
	cout << "Play" << endl;
	if(music != NULL)
		Mix_PlayChannel(-1, music, 0);
	else
		cout << "Music not loaded." << endl;
}

Sound gBulletSound;
Sound gExplosionSound;