#pragma once 
#include <ctime>
#include <cstdlib>

struct Ball{
    private:
        int v_pos;
        int h_pos; 
        int v_speed;
        int h_speed;
        int width;
        int height;
    
    public:
        Ball() = default; 

        Ball(const int vert_pos, const int hor_pos, 
            const int vert_speed, const  int hor_speed);

        Ball(int vert_pos, int hor_pos); 

        void moveBall(const unsigned int gameSpeed);

        void setSpeed(const int vert_speed, const int hor_speed);

        int getHeight() const;
        int getWidth() const;
        int getVSpeed() const;
        int getHSpeed() const;
        int getVPos() const;
        int getHPos() const;
};
