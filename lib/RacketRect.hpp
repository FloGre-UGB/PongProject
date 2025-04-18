#pragma once 
#include <SDL2/SDL_ttf.h>
#include "Racket.hpp"

struct RacketRect{
    SDL_Rect rect; 
    // Constructors:
    RacketRect() = default; 
    RacketRect(const Racket* const racket);

    //methods:
    void updatePosition(const Racket* const racket);

    void parseToRenderer(SDL_Renderer * renderer) const;

    void updateAndParse(const Racket* const racket, SDL_Renderer* renderer);
};
