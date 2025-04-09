#pragma once 
#include <ctime>
#include <cstdlib>

struct Ball{
    int v_pos;
    int h_pos; 
    int v_speed;
    int h_speed;

    int width;
    int height;
    
    Ball() = default; 

    Ball(int vert_pos, int hor_pos, 
        int vert_speed, int hor_speed);

    Ball(int vert_pos, int hor_pos); 

    void moveBall(unsigned int gameSpeed);

    void setSpeed(const int vert_speed, const int hor_speed);
};
