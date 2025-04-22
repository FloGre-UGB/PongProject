#pragma once 
#include <SDL2/SDL_ttf.h>
#include "Ball.hpp"

struct BallRect
{
    private:
        SDL_Rect rect; 
    public:
        // Constructors:
        BallRect() = default;
        BallRect(const Ball* const ball);


        // methods:
        void updatePosition(const Ball* const ball);

        void parseToRenderer(SDL_Renderer * renderer) const;

        void updateAndParse(const Ball* const ball, SDL_Renderer* renderer);
};

