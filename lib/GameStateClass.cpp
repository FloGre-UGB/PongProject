#include "GameStateClass.hpp"
#include <cstdlib>



Racket::Racket(int v_pos, int h_pos){
    vertical_pos = v_pos;
    horizontal_pos = h_pos;
    racket_width = 10;
    racket_length = 100;
}

void Racket::moveUp(){
    vertical_pos = vertical_pos - 5;
}
void Racket::moveDown(){
    vertical_pos = vertical_pos + 5;
}

Ball::Ball(int vert_pos, int hor_pos, int vert_speed, int hor_speed){
    v_pos = vert_pos;
    h_pos = hor_pos;
    v_speed = vert_speed;
    h_speed = hor_speed;
    width = 10;
    height = 10; 
}

void Ball::moveBall(unsigned int timedelta){
    v_pos = v_pos + timedelta * v_speed;
    h_pos = h_pos + timedelta * h_speed;
}

GameState::GameState(int v_pos_l/*=360*/,  int h_pos_l/*=10*/, 
        int v_pos_r/*=360*/,  int h_pos_r/*=710*/, 
        int v_pos_ball/*=360*/,  int h_pos_ball/*=360*/,
        int v_speed_ball/*=-1*/, int h_speed_ball/*=-1*/,
        unsigned short points_l, unsigned short points_r){

        // make left racket at position: (v_pos_l, h_pos_l)
        left = Racket(v_pos_l, h_pos_l);
        // make right racket at position: (v_pos_r, h_pos_r)
        right = Racket(v_pos_r, h_pos_r);

        // make ball  
        ball = Ball(v_pos_ball, h_pos_ball, v_speed_ball, h_speed_ball);

        // current score
        points_left = points_l;
        points_right = points_r; 
}