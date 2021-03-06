/*****************************************************
 * Frame rate controll library
 *
 * @author    Dipesh Dulal
 * @version   1.0
 * @since     2016-10-16
 *****************************************************/
#ifndef SPACESHOOTER_FRAMERATE
 #define SPACESHOOTER_FRAMERATE
	
	// include the sdl
	#ifdef _WIN32
	  #include <SDL.h>
	#endif                        

	#ifdef __linux
	  #include <SDL2/SDL.h>
	#endif

	
	class FrameRate{

		private:
			const int _frameRate = 50;
			int _previousTicks = 0;
			int _previousTicks1 = 0;
			const int _ticksPerFrame = (100/_frameRate);

		public:
			void start();
			int ticks(int);
			// constructor
			FrameRate();
			int getTicks();
	};


#endif