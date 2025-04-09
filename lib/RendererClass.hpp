#pragma once
#include <SDL2/SDL.h>
#include "GameStateClass.hpp"
#include <vector>


struct Renderer{
    SDL_Window * window;
    SDL_Renderer * renderer;
    unsigned int screen_width;
    unsigned int screen_height;

    // the game has three rectangles: the two rackets and the ball
    
    // Constructor 
    //Renderer(SDL_Window * w, GameState * state);
    Renderer(SDL_Window * w);
    void draw(GameState * state);
};