#include "RacketRect.hpp"

RacketRect::RacketRect(Racket* racket){
    rect = SDL_Rect{racket->horizontal_pos, racket->vertical_pos,
    racket->racket_width, racket->racket_length};
}

void RacketRect::updatePosition(Racket* racket){
    rect.x = racket->horizontal_pos;
    rect.y = racket->vertical_pos;
}

void RacketRect::parseToRenderer(SDL_Renderer * renderer){
    SDL_RenderFillRect(renderer, &(this->rect));
}

void RacketRect::updateAndParse(Racket* racket, SDL_Renderer * renderer){
    this->updatePosition(racket);
    this->parseToRenderer(renderer);
}

