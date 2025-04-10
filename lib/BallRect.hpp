#pragma once 
#include <SDL2/SDL_ttf.h>
#include "Ball.hpp"

struct BallRect
{
    SDL_Rect rect; 
    // Constructors:
    BallRect() = default;
    BallRect(Ball * ball);


    // methods:
    void updatePosition(Ball* ball);

    void parseToRenderer(SDL_Renderer * renderer);

    void updateAndParse(Ball* ball, SDL_Renderer* renderer);
};

