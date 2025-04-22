#include "GameStateClass.hpp"
#include <cstdlib>

GameState::GameState(int v_pos_l/*=360*/,  int h_pos_l/*=10*/, 
        int v_pos_r/*=360*/,  int h_pos_r/*=710*/, 
        int v_pos_ball/*=360*/,  int h_pos_ball/*=360*/,
        int v_speed_ball/*=-1*/, int h_speed_ball/*=-1*/,
        unsigned short points_l, unsigned short points_r,
        unsigned int s_width, unsigned int s_height){

        // make left racket at position: (v_pos_l, h_pos_l)
        left = Racket(v_pos_l, h_pos_l);
        // make right racket at position: (v_pos_r, h_pos_r)
        right = Racket(v_pos_r, h_pos_r);

        // make ball  
        ball = Ball(v_pos_ball, h_pos_ball, v_speed_ball, h_speed_ball);

        // current score
        points_left = points_l;
        points_right = points_r; 

        //
        screen_height = s_height;
        screen_width = s_width;
}


void GameState::checkCollision(int cut, SoundEffect* bounce){
    bool collision = false;
    // check for collision with rackets
    if (left.checkCollision(&ball, true)){
        collision = true;
        ball.setSpeed(ball.getVSpeed() + cut, ball.getHSpeed() * (-1));
    }
    else if (right.checkCollision(&ball, false)){
        collision = true;
        ball.setSpeed(ball.getVSpeed() + cut, ball.getHSpeed() * (-1));
    }
    // check for collision with walls
    else if (ball.getHPos() > 0 && ball.getHPos() < (int) screen_width &&
            (ball.getVPos() <=0 || ball.getVPos() >= (int) screen_height)) {
        collision = true;
        ball.setSpeed(ball.getVSpeed() * (-1), ball.getHSpeed());
    }
    if (collision == true and bounce!=nullptr){
        bounce->playEffect(0); 
    }
}

bool GameState::checkForPoint(){
    // right player makes a point:
    if (ball.getHPos() + 2*ball.getWidth() < 0){
        points_right++;
        return true;
    }
    // left player makes a point:
    else if (ball.getHPos() > (int) screen_width){
        points_left++;
        return true; 
    }
    else{
        return false;
    }
}

void GameState::resetBall(){
    ball = Ball(screen_height/2, screen_width/2,1,1);
}