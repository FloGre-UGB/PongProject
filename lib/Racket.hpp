#pragma once
#include "Ball.hpp"

struct Racket{
    int vertical_pos;
    int horizontal_pos; 

    int racket_width;
    int racket_length; 

    Racket() = default; 
    // Constructor:
    Racket( int v_pos,  int h_pos);

    // Destructor
    ~Racket() = default; 

    //Function that move the racket upwards
    void moveUp(unsigned int gameSpeed=1);

    //Function that move the racket upwards
    void moveDown(unsigned int gameSpeed=1, const int screenHeight=720);

    // Function that checks for collision with ball
    bool checkCollision(Ball * ball);
    
};