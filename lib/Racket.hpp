#pragma once
#include "Ball.hpp"

struct Racket{
    private:
        int vertical_pos;
        int horizontal_pos; 

        int racket_width;
        int racket_length; 

    public:
        Racket() = default; 
        // Constructor:
        Racket( int v_pos,  int h_pos);

        // Destructor
        ~Racket() = default; 

        //Function that move the racket upwards
        void moveUp(unsigned int gameSpeed=1);

        //Function that move the racket upwards
        void moveDown(unsigned int gameSpeed=1, const int screenHeight=720);

        // Function that moves the racket to the right
        void moveRight(unsigned int gameSpeed=1, const int screenWidth=720, const bool left=true);
        // Function that moves the racket to the left
        void moveLeft(unsigned int gameSpeed=1, const int screenWidth=720, const bool left=true);


        // Function that checks for collision with ball
        bool checkCollision(Ball * ball, bool left);
        
        // functions used to get the position and measures 
        int getVertcialPos() const;
        int getHorPos() const;
        int getWidth() const;
        int getHeight() const; 
};