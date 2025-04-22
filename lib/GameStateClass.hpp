#pragma once 
#include "Racket.hpp"
#include "Ball.hpp"
#include "SoundEffect.hpp"


struct GameState{
    
    unsigned short points_left; 
    unsigned short points_right;
    unsigned int screen_width;
    unsigned int screen_height;
    
    Racket left;
    Racket right; 
    Ball ball; 

    // Constructor:
    GameState( int v_pos_l=360, int h_pos_l=10, 
                int v_pos_r=360, int h_pos_r=710,
                int v_pos_ball=360, int h_pos_ball=360,
                int v_speed_ball=-1, int h_speed_ball=1,
                unsigned short points_l=0, unsigned short points_r=0,
                unsigned int s_width=720, unsigned int s_height=720);
    
    // check for collision of one of the of the rackets and ball or the boundary walls and the ball
    // the function then resets the speed of the ball. The cut variable allows to give the ball a cut by a moving racket
    void checkCollision(int cut = 0, SoundEffect* bounce=nullptr); 

    // check whether ball is out and whos made a point
    bool checkForPoint();

    void resetBall();
};
