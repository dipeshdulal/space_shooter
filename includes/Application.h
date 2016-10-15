/*****************************************************
 * Core Application Class. Initializes and closes the
 * SDL and contains the main game loop
 *
 * @author    Dipesh Dulal
 * @version   1.0
 * @since     2016-10-15
 * @modified  2016-10-15
 *****************************************************/
#ifndef SPACESHOOTER_APPLICATION
    #define SPACESHOOTER_APPLICATION

#include "WindowElements.h"

class Application{

  private:
    WindowElements windowElements;

  public:
    // Constructor
    Application();

    // Methods
    int start();
    bool initialize();
    void terminate();

};

#endif
