#include "AppClass.hpp"
#include "GameStateClass.hpp"
#include "RendererClass.hpp"
#include "KeyboardHandler.hpp"
#include "Music.hpp"
#include "SoundEffect.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include <ctime>

App::App(const unsigned int width,const unsigned int height){
    if ( SDL_Init ( SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO)) {
        std::cout << "Failed SDL_Init " << std::endl;
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

App::~App(){
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void App::setSpeed(const unsigned int newSpeed){
    gameSpeed = newSpeed;
}


void App::run(){
    running = true;
    bool doQuit = false;

    // initial movement of the ball: random direction 
    // -> generate random numbers for this
    float arr[] = {-1,1, -2,2};

    srand (time(NULL));
    unsigned short rand_num;

    rand_num = rand() % 2;
    float hor_speed = arr[rand_num];
    rand_num = rand() % 4;
    float vert_speed = arr[rand_num];


    // instantiate a GameState Object
    GameState state  = GameState(screen_height/2, screen_width/10 ,
        screen_height/2, screen_width-screen_width/10, screen_height/2, 
        screen_height/2, vert_speed, hor_speed, 0, 0,
        screen_width, screen_height);

    // instantiate a renderer 
    Renderer renderer = Renderer(window, &state);

    // instantiate a keyboard handler
    KeyboardHandler keyHandler = KeyboardHandler(); 

    // instantiate a SoundEffect object
    SoundEffect bounce = SoundEffect("./build/bouncing.wav", 0);

    // instantiate usic object
    Music music = Music("./build/output.wav", 0);
    music.playMusic();
    // draw the startscreen
    renderer.drawStartscreen(); 
    
    Uint32 timestampLoopBegin;
    Uint32 timeLastPointEnded = 0; // tracks the time at which a point ends (ball leaves field)
    Uint32 timePointIsRunning;
    unsigned int newSpeed = 1; 
    // game loop:
    while(running){
        // get current time:
        timestampLoopBegin = SDL_GetTicks();

        // determine how long the game's been running 
        timePointIsRunning = timestampLoopBegin - timeLastPointEnded; 

        // increase game speed every ten seconds 
        newSpeed = 1 + timePointIsRunning / 10000;
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
        
        // check whether ball collides with racket or wall
        state.checkCollision(0);
        
        // check whether someone scored
        if (state.checkForPoint()){
            // wait before resetting the ball
            SDL_Delay(500);

            timeLastPointEnded = SDL_GetTicks();
            //reset the ball 
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
            running = false;
            break; 
        }
    }

}

SDL_Window * App::getWindow(){
    return window;
}



