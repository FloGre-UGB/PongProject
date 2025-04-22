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

void Racket::moveRight(unsigned int gameSpeed, const int screenWidth, const bool left){
    if ((left == true && this->horizontal_pos + this->racket_width <= screenWidth/2)
     || (left == false && this->horizontal_pos <= screenWidth)){
        horizontal_pos = horizontal_pos + 5 * gameSpeed;
    }
}

void Racket::moveLeft(unsigned int gameSpeed, const int screenWidth, const bool left){
    if ((left == true && this->horizontal_pos >= 0)
     || (left == false && this->horizontal_pos >= screenWidth/2)){
        horizontal_pos = horizontal_pos - 5 * gameSpeed;
    }
}



bool Racket::checkCollision(Ball * ball, bool left){
    if ((
        (left == true) 
        && (vertical_pos + racket_length >= ball->getVPos() + ball->getHeight()) && (vertical_pos <= ball->getVPos()) 
        && (
            (horizontal_pos + racket_width >= ball->getHPos()) 
            && (horizontal_pos <= ball->getHPos())
        ))
        ||
        (
        (left == false) 
        && (vertical_pos + racket_length >= ball->getVPos() + ball->getHeight()) && (vertical_pos <= ball->getVPos()) 
        && (
            (horizontal_pos <= ball->getHPos() + ball->getWidth())
            && (horizontal_pos + racket_width >= ball->getHPos() + ball->getWidth())

        ))
    ){
        return true; 
    }
    else{
        return false;
    }

}

int Racket::getVertcialPos() const{
    return vertical_pos;
}
int Racket::getHorPos() const{
    return horizontal_pos;
}
int Racket::getWidth() const{
    return racket_width;
}
int Racket::getHeight() const{
    return racket_length;
}

