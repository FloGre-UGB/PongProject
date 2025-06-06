#include "BallRect.hpp"

BallRect::BallRect(const Ball* const ball){
    rect = SDL_Rect{ball->h_pos, ball->v_pos,
        ball->width, ball->height}; 
}

void BallRect::updatePosition(const Ball* const ball){
    rect.x = ball->h_pos;
    rect.y = ball->v_pos;
}
void BallRect::parseToRenderer(SDL_Renderer * renderer) const{
    SDL_RenderFillRect(renderer, &(this->rect));
}

void BallRect::updateAndParse(const Ball* const ball, SDL_Renderer * renderer){
    this->updatePosition(ball);
    this->parseToRenderer(renderer);
}



