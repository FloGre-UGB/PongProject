#include "Middleline.hpp"

Middleline::Middleline(const int h_pos, const int w, const int screenHeight, const unsigned int numol){
    hor_pos = h_pos;
    width = w;
    numOfLines = numol;
    // determine length of single pieces 
    int lengthOfRects = screenHeight/(2*numol);
    int pos; 
    for (unsigned int i=0; i < numOfLines;i++){
        pos = i * 2* lengthOfRects + lengthOfRects/2; 
        SDL_Rect temp = SDL_Rect{hor_pos - width/2, pos, width, lengthOfRects};
        lineRectangles.push_back(temp);
    }
}

void Middleline::parseMiddleline(SDL_Renderer* renderer) const{
    for (SDL_Rect r : lineRectangles){
        SDL_RenderFillRect(renderer, &r);
    }
}