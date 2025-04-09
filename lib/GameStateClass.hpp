#pragma once 
#include "Racket.hpp"
#include "Ball.hpp"


struct GameState{
    Racket left;
    Racket right; 
    unsigned short points_left; 
    unsigned short points_right;
    unsigned int screen_width;
    unsigned int screen_height;

    Ball ball; 

    // Constructor:
    GameState( int v_pos_l=360, int h_pos_l=10, 
                int v_pos_r=360, int h_pos_r=710,
                int v_pos_ball=360, int h_pos_ball=360,
                int v_speed_ball=-1, int h_speed_ball=1,
                unsigned short points_l=0, unsigned short points_r=0,
                unsigned int s_width=720, unsigned int s_height=720);
    
    // check for collision of one of the of the rackets and ball or the boundary walls and the ball
    void checkCollision(); 

    // check whether ball is out and whos made a point
    bool checkForPoint();

    void resetBall();
};
