/*****************************************************
 * Frame rate controll library
 *
 * @author    Dipesh Dulal
 * @version   1.0
 * @since     2016-10-16
 *****************************************************/
#include "FrameRate.h"
#include <iostream>

using namespace std;
	
// to know the delay time to manipulate the frame rate
void FrameRate::start(){
	// gives numbers of milliseconds sdl library initialized
	int currentTicks = SDL_GetTicks(); 
	
	// miliseconds passed to generate one frame
	int frameTicks = currentTicks - _previousTicks;

	// cout << frameTicks << endl;
// 
	if( frameTicks < _ticksPerFrame ){

		// delay the program0
		SDL_Delay( _ticksPerFrame - frameTicks );
		
	}
	
	_previousTicks = currentTicks;
}	
	
// constructor
FrameRate::FrameRate(){
	cout << "Running at " << _frameRate << " fps" << endl;
}

// return the ticks
int FrameRate::ticks(int fps){

	bool success = false;

	// if divisible by fps
	if( (_previousTicks/100) % fps == 0){
		success = true;
	}

	return success;
}