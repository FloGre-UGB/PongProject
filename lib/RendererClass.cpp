#include "RendererClass.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <iostream>
#include <filesystem>

Renderer::Renderer(SDL_Window * w, GameState * state){
    window = w; 
    renderer = SDL_CreateRenderer(window , -1, SDL_RENDERER_ACCELERATED);
    // set screen width and screen height
    SDL_GetWindowSize(window, (int*) &screen_width, (int*) &screen_height);
    
    // make rackets and ball rectangles:
    leftRacket = RacketRect(&(state->left));
    rightRacket = RacketRect(&(state->right));
    ball = BallRect(&(state->ball));

    // make middle line 
    middleLine = Middleline((int)screen_width/2, (int) screen_width/100, screen_height, 10);

    // make the scoreboards
    if (TTF_Init()!=0){
        std::cout << "Failed TTF_init " << std::endl;
        std::exit(1);
    }
    // load font: 
    TTF_Font* font = TTF_OpenFont("./build/Monument.ttf", 28);
    // construct the scoreboards:
    int scoreboardVertPos = screen_height/50;
    int scoreboardWidth = screen_width/10;
    int indentScoreboard = screen_width/4-scoreboardWidth/2;
    int scoreboardHeight = screen_height/5; 

    leftScoreboard = new ScoreboardRect(scoreboardVertPos, indentScoreboard, scoreboardHeight, scoreboardWidth,
        state->points_left, 255, 100,0,200, renderer, font);
    rightScoreboard =  new ScoreboardRect(scoreboardVertPos, screen_width - indentScoreboard - scoreboardWidth, scoreboardHeight, scoreboardWidth,
        state->points_right, 255, 100,0,200, renderer, font);
    
    //make startscreen
    int leftIndentStarttext = screen_width/4;
    int upperMarginStarttext = screen_height/4;
    TTF_Font* font2 = TTF_OpenFont("./build/SLC_.ttf", 28);
    start = new Startscreen(leftIndentStarttext, upperMarginStarttext, screen_width/2, screen_height/2, 255, 100,0,200, renderer, font, font2);
    
}   

void Renderer::draw(GameState * state){
    // Drawing the background
    SDL_SetRenderDrawColor(renderer , 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    
    // draw the scoreboard
    rightScoreboard->updateScoreboard(state->points_right, renderer);
    
    leftScoreboard->updateScoreboard(state->points_left, renderer);

    SDL_RenderCopy(renderer, rightScoreboard->scoreTexture, NULL, &(rightScoreboard->scoreRect));

    SDL_RenderCopy(renderer, leftScoreboard->scoreTexture, NULL, &(leftScoreboard->scoreRect));

    // draw the ball in yellow
    SDL_SetRenderDrawColor(renderer , 255, 255, 0, 0);

    // draw the ball
    ball.updateAndParse(&(state->ball), this->renderer);
    
    // Draw the rackets white
    SDL_SetRenderDrawColor(renderer , 255, 255, 255, 0);

    // update positions of the rackets
    leftRacket.updateAndParse(&(state->left),this->renderer);
    rightRacket.updateAndParse(&(state->right),this->renderer);

    // draw the middleline
    middleLine.parseMiddleline(renderer);

    // Displaying the new frame
    SDL_RenderPresent(renderer);

}

void Renderer::drawStartscreen(){
    for (int t =0; t<5; t++){
        // make title
        SDL_RenderCopy(renderer, start->titleTexture,NULL, &(start->titleRect));
        // update the text that is displayed:
        start->updateTexture(renderer, 5-t);
        // make subtitle
        SDL_RenderCopy(renderer, start->subtitleTexture,NULL, &(start->subtitleRect));
        SDL_RenderPresent(renderer);
        SDL_Delay(1000);

        // Drawing the background
        SDL_SetRenderDrawColor(renderer , 0, 0, 0, 0);
        SDL_RenderClear(renderer);
    }
}
