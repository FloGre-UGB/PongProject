#pragma once 
#include <SDL2/SDL_ttf.h>
#include "Racket.hpp"

struct RacketRect{
    SDL_Rect rect; 
    // Constructors:
    RacketRect() = default; 
    RacketRect(Racket* racket);

    //methods:
    void updatePosition(Racket* racket);

    void parseToRenderer(SDL_Renderer * renderer) const;

    void updateAndParse(Racket* racket, SDL_Renderer* renderer);
};
