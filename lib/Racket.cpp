#include "Racket.hpp"

Racket::Racket(int v_pos, int h_pos){
    vertical_pos = v_pos;
    horizontal_pos = h_pos;
    racket_width = 10;
    racket_length = 100;
}

void Racket::moveUp(unsigned int gameSpeed){
    if (this->vertical_pos >= 0){
        vertical_pos = vertical_pos - 5 * gameSpeed;
    }
}
void Racket::moveDown(unsigned int gameSpeed, const int screenHeight){
    if (this->vertical_pos <= screenHeight - this->racket_length)
        vertical_pos = vertical_pos + 5 * gameSpeed;
}

bool Racket::checkCollision(Ball * ball){
    if ((vertical_pos + racket_length > ball->v_pos) && (vertical_pos < ball->v_pos) 
        && (
            ((horizontal_pos < ball->h_pos) && (horizontal_pos + racket_width > ball->h_pos))
            ||((horizontal_pos - racket_width< ball->h_pos) && (horizontal_pos > ball->h_pos))
        )
        ){
        return true; 
    }
    else{
        return false;
    }

}