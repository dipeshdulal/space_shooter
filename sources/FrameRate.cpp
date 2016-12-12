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

	// cout << _ticksPerFrame << endl;

	if( frameTicks < _ticksPerFrame ){
		// delay the program
		SDL_Delay( _ticksPerFrame - frameTicks );
	}

	_previousTicks = currentTicks;
}	
	
// constructor
FrameRate::FrameRate(){
	cout << "Running at " << _frameRate << " fps" << endl;
}