#include "AppClass.hpp"
#include "GameStateClass.hpp"
#include "RendererClass.hpp"
#include "KeyboardHandler.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include <ctime>

App::App(const unsigned int width,const unsigned int height){
    if ( SDL_InitSubSystem ( SDL_INIT_VIDEO | SDL_INIT_EVENTS )) {
        std::cout << "Failed SDL_InitSubSystem " << std::endl;
        std::exit(1);
    }
    running = false;
    screen_width = width;
    screen_height = height;
    timedelta = 20; 
    gameSpeed = 1;


    window = SDL_CreateWindow(
        "Pong",
        SDL_WINDOWPOS_UNDEFINED ,
        SDL_WINDOWPOS_UNDEFINED ,
        width, height,
        0
    );

}

void App::setSpeed(unsigned int newSpeed){
    gameSpeed = newSpeed;
}


void App::run(){
    Uint32 startTime = SDL_GetTicks();

    running = true;
    bool doQuit = false;

    // initial movement of the ball: random direction 
    // -> generate random numbers for this
    float arr[] = {-1,1, 0};
    srand (time(NULL));
    unsigned short rand_num;

    rand_num = rand() % 2;
    float hor_speed = arr[rand_num];
    rand_num = rand() % 3;
    float vert_speed = arr[rand_num];


    // instantiate a GameState Object
    GameState state  = GameState(screen_height/2, 50 ,
        screen_height/2, screen_width-50, screen_height/2, 
        screen_height/2, vert_speed, hor_speed, 0, 0,
        screen_width, screen_height);

    // instantiate a renderer 
    Renderer renderer = Renderer(window);

    // instantiate a keyboard handler
    KeyboardHandler keyHandler = KeyboardHandler(); 

    // draw the initial game state
    renderer.draw(&state);

    Uint32 timestampLoopBegin;
    Uint32 timGameIsRunning;
    unsigned int newSpeed = 1; 
    // game loop:
    while(running){
        // get current time:
        timestampLoopBegin = SDL_GetTicks();

        // determine how long the game's been running 
        timGameIsRunning = timestampLoopBegin - startTime; 

        // increase game speed every ten seconds 
        newSpeed = 1 + timGameIsRunning / 10000;
        // increase game speed
        setSpeed(newSpeed);




        SDL_Event event; 
        // event loop
        while (SDL_PollEvent(&event)){
            keyHandler.fetchKeyboardStates();
            keyHandler.handleKeyboardStates(&doQuit, &state, gameSpeed);

            if (event.type == SDL_QUIT) {
                // clicking the x closes the app
                doQuit = true;
                break;
            }
        }
        state.ball.moveBall(gameSpeed);
        
        // check whether ball collides with racket
        state.checkCollision();
        // check whether someone scored
        if (state.checkForPoint()){
            // wait before resetting the ball
            SDL_Delay(500);
            state.resetBall();
        }

        // render the game state
        renderer.draw(&state);
        SDL_UpdateWindowSurface(window);

        // make sure to have the right game speed (50fps)  
        while (SDL_GetTicks() < timestampLoopBegin + timedelta){
            SDL_Delay(1);
        }

        if (doQuit){
            break; 
        }
    }

}



