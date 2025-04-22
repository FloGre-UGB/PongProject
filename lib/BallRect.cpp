#include "BallRect.hpp"

BallRect::BallRect(const Ball* const ball){
    rect = SDL_Rect{ball->getHPos(), ball->getVPos(),
        ball->getWidth(), ball->getHeight()}; 
}

void BallRect::updatePosition(const Ball* const ball){
    rect.x = ball->getHPos();
    rect.y = ball->getVPos();
}
void BallRect::parseToRenderer(SDL_Renderer * renderer) const{
    SDL_RenderFillRect(renderer, &(this->rect));
}

void BallRect::updateAndParse(const Ball* const ball, SDL_Renderer * renderer){
    this->updatePosition(ball);
    this->parseToRenderer(renderer);
}



