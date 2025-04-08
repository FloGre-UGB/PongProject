#pragma once 


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
    void moveUp();

    //Function that move the racket upwards
    void moveDown();
    
};

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

    void moveBall(unsigned int timedelta);
};


struct GameState{
    Racket left;
    Racket right; 
    unsigned short points_left; 
    unsigned short points_right;

    Ball ball; 

    // Constructor:
    GameState( int v_pos_l=360, int h_pos_l=10, 
                int v_pos_r=360, int h_pos_r=710,
                int v_pos_ball=360, int h_pos_ball=360,
                int v_speed_ball=-1, int h_speed_ball=1,
                unsigned short points_l=0, unsigned short points_r=0
            );

};
