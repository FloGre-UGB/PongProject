#pragma once
#include <SDL2/SDL_ttf.h>

struct scoreboardRect{
    int v_pos;
    int h_pos;
    int height; 
    int width; 
    unsigned short points_displayed;

    TTF_Font* Font; 
    SDL_Color Col; 


}