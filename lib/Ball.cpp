#include "Ball.hpp"

Ball::Ball(const int vert_pos, const int hor_pos, const int vert_speed, const int hor_speed){
    v_pos = vert_pos;
    h_pos = hor_pos;
    v_speed = vert_speed;
    h_speed = hor_speed;
    width = 10;
    height = 10; 
}

void Ball::moveBall(const unsigned int gameSpeed){
    v_pos = v_pos + gameSpeed * v_speed;
    h_pos = h_pos + gameSpeed * h_speed;
}

void Ball::setSpeed(const int vert_speed, const int hor_speed){
    v_speed = vert_speed;
    h_speed = hor_speed;
}

Ball::Ball(int vert_pos, int hor_pos){
    width = 10;
    height = 10; 
    v_pos = vert_pos;
    h_pos = hor_pos;
    
    // initial movement of the ball: random direction 
    // -> generate random numbers for this
    const float arr[] = {-1,1, -2, 2};
    unsigned short rand_num;

    rand_num = rand() % 2;
    h_speed = arr[rand_num];
    rand_num = rand() % 4;
    v_speed = arr[rand_num];
}