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
    void updatePosition(const Ball* ball);

    void parseToRenderer(SDL_Renderer * renderer) const;

    void updateAndParse(const Ball* ball, SDL_Renderer* renderer);
};

