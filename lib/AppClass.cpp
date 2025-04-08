#include "AppClass.hpp"
#include "GameStateClass.hpp"
#include "RendererClass.hpp"
#include <SDL2/SDL.h>
#include <iostream>

App::App(const unsigned int width,const unsigned int height){
    if ( SDL_InitSubSystem ( SDL_INIT_VIDEO | SDL_INIT_EVENTS )) {
        std::cout << "Failed SDL_InitSubSystem " << std::endl;
        std::exit(1);
    }
    running = false;
    screen_width = width;
    screen_height = height;

    window = SDL_CreateWindow(
        "My first window ",
        SDL_WINDOWPOS_UNDEFINED ,
        SDL_WINDOWPOS_UNDEFINED ,
        width, height,
        0
    );

}

void App::run(){
    running = true;
    bool doQuit = false;
    unsigned int timedelta = 20; 
    // initial movement of the ball: random direction 
    // -> generate random numbers for this
    float arr[] = {-1,1};
    unsigned short rand_num; 
    rand_num = rand() % 2;
    float hor_speed = arr[rand_num];
    rand_num = rand() % 2;
    float vert_speed = arr[rand_num];


    // instantiate a GameState Object
    GameState state  = GameState(screen_height/2, 50 ,
        screen_height/2, screen_width-50, screen_height/2, 
        screen_height/2, vert_speed, hor_speed, 0, 0);

    // instantiate a renderer 
    Renderer renderer = Renderer(window);

    // draw the initial game state
    renderer.draw(&state);

    // game loop:
    while(running){
        // get current time:
        Uint32 timestamp = SDL_GetTicks();

        SDL_Event event; 
        // event loop
        while (SDL_PollEvent(&event)){
            switch (event.type) {

                case SDL_QUIT: // clicking the x closes the app
                    doQuit = true;
                    break;
                case SDL_KEYDOWN:
                    // Esc closes the game 
                    switch (event.key.keysym.scancode){
                        case SDL_SCANCODE_ESCAPE:
                            doQuit = true;   
                            break;
                        case SDL_SCANCODE_UP:
                            state.right.moveUp();
                            break;
                        case SDL_SCANCODE_DOWN:
                            state.right.moveDown();
                            break;
                        case SDL_SCANCODE_W:
                            state.left.moveUp();
                            break;
                        case SDL_SCANCODE_S:
                            state.left.moveDown();
                            break;
                    }
                    break;
                
            }
        }
        state.ball.moveBall(timedelta/8);
        
        // check whether ball collides with racket

        if (doQuit){
            break; 
        }

        // render the game state
        renderer.draw(&state);
        SDL_UpdateWindowSurface(window);

        // make sure to have the right game speed (50fps)  
        while (SDL_GetTicks() < timestamp + timedelta){
            SDL_Delay(1);
        }
    }

}