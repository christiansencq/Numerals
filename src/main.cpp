#include <iostream>

#include "SDL2/SDL.h"
#include "App.h"
#include "Constants.h"



int main( int argc, char* argv[])
{

    if (App::Singleton().init("NumberDisplay", SCREEN_WIDTH, SCREEN_HEIGHT, false))
    { 
        App::Singleton().Run();
    }

        

    return 0;
}   