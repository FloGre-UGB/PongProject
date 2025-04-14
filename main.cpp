#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "lib/AppClass.hpp"
#include <iostream>



int main(){
    App app = App(1020, 720);
    if (app.window == NULL) {
        std :: cout << "Failed SDL_CreateWindow " << std :: endl;
        return -1;
    }
    app.run();

}