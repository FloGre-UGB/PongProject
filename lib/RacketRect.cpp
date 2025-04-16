#include "RacketRect.hpp"

RacketRect::RacketRect(const Racket* const racket){
    rect = SDL_Rect{racket->horizontal_pos, racket->vertical_pos,
    racket->racket_width, racket->racket_length};
}

void RacketRect::updatePosition(const Racket* const racket){
    rect.x = racket->horizontal_pos;
    rect.y = racket->vertical_pos;
}

void RacketRect::parseToRenderer(SDL_Renderer * renderer) const{
    SDL_RenderFillRect(renderer, &(this->rect));
}

void RacketRect::updateAndParse(const Racket* const racket, SDL_Renderer * renderer){
    this->updatePosition(racket);
    this->parseToRenderer(renderer);
}

