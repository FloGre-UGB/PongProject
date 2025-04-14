#pragma once 
#include <vector>
#include <SDL2/SDL.h>

struct Middleline{
    int hor_pos;
    int width; 
    unsigned int numOfLines; 

    std::vector<SDL_Rect> lineRectangles; 

    Middleline() = default;
    Middleline(const int h_pos, const int w, const int screenHeight, const unsigned int numol); 

    void parseMiddleline(SDL_Renderer* renderer) const; 
};