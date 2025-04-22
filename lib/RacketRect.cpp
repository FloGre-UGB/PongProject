#include "RacketRect.hpp"

RacketRect::RacketRect(const Racket* const racket){
    rect = SDL_Rect{racket->getHorPos(), racket->getVertcialPos(),
    racket->getWidth(), racket->getHeight()};
}

void RacketRect::updatePosition(const Racket* const racket){
    rect.x = racket->getHorPos();
    rect.y = racket->getVertcialPos();
}

void RacketRect::parseToRenderer(SDL_Renderer * renderer) const{
    SDL_RenderFillRect(renderer, this->getRect());
}

void RacketRect::updateAndParse(const Racket* const racket, SDL_Renderer * renderer){
    this->updatePosition(racket);
    this->parseToRenderer(renderer);
}

const SDL_Rect* RacketRect::getRect() const{
    return &rect;
}