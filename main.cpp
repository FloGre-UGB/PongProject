#include <SDL2/SDL.h>
#include "lib/AppClass.hpp"
#include "lib/GameStateClass.hpp"
#include <iostream>



int main(){
    App app = App(720, 720);
    if (app.window == NULL) {
        std :: cout << "Failed SDL_CreateWindow " << std :: endl;
        return -1;
    }
    app.run();

}