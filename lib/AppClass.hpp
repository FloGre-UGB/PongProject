#pragma once 
#include <SDL2/SDL.h>

struct App{
    bool running;
    unsigned int screen_width;
    unsigned int screen_height;

    SDL_Window * window;
    SDL_Surface * surface; 



    App(const unsigned int width, const unsigned int height);

    void run();
}; 