#pragma once 
#include <SDL2/SDL_ttf.h>
#include "GameStateClass.hpp"

struct RacketRect{
    SDL_Rect rect; 

    RacketRect(Racket* racket);
};
