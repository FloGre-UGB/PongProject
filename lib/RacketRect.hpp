#pragma once 
#include <SDL2/SDL_ttf.h>
#include "Racket.hpp"

struct RacketRect{
    SDL_Rect rect; 

    RacketRect() = default; 
    RacketRect(Racket* racket);

    void updatePosition(Racket* racket);

    void parseToRenderer(SDL_Renderer * renderer);

    void updateAndParse(Racket* racket, SDL_Renderer* renderer);
};
