#include "RendererClass.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <iostream>
#include <filesystem>

Renderer::Renderer(SDL_Window * w){
    window = w; 
    renderer = SDL_CreateRenderer(window , -1, SDL_RENDERER_ACCELERATED);
    // set screen width and screen height
    SDL_GetWindowSize(window, (int*) &screen_width, (int*) &screen_height);
}   

void Renderer::draw(GameState * state){
    // Drawing the background
    SDL_SetRenderDrawColor(renderer , 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    
    /*
    // draw the scoreboard (move somewhere else)
    std::string strScoreLeft = std::to_string(state->points_left);
    std::string strScoreRight = std::to_string(state->points_right);

    if (TTF_Init()!=0){
        std::cout << "Failed TTF_init " << std::endl;
        std::exit(1);
    }

    TTF_Font* Sans = TTF_OpenFont("./build/Monument.ttf", 24);
    if (Sans == nullptr){
        std::cout << "font not found" << std::endl;
        std::exit(1);
    }

    SDL_Color Col = {0, 120, 255};
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, strScoreLeft.c_str(), Col); 
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    SDL_Rect Message_rect; //create a rect
    Message_rect.x = 100;  //controls the rect's x coordinate 
    Message_rect.y = 100; // controls the rect's y coordinte
    Message_rect.w = 100; // controls the width of the rect
    Message_rect.h = 400; // controls the height of the rect

    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
    
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
    */

    // make rectangles to draw the rackets
    SDL_Rect lRacket = SDL_Rect{state->left.horizontal_pos,
        state->left.vertical_pos,
        state->left.racket_width,
        state->left.racket_length
        };
        
    SDL_Rect rRacket = SDL_Rect{state->right.horizontal_pos,
            state->right.vertical_pos,
            state->right.racket_width,
            state->right.racket_length
        };

    // make rectangle to draw the ball 
    SDL_Rect ball = SDL_Rect{state->ball.h_pos, state->ball.v_pos,
        state->ball.width, state->ball.height
        };

    std::vector<SDL_Rect> rectangles = {lRacket, rRacket, ball}; 
    
    // draw the rectangles using white
    SDL_SetRenderDrawColor (renderer , 255, 255, 255, 0);
    for (SDL_Rect r:rectangles){
        
        SDL_RenderFillRect(renderer, &r);
    }


    // Displaying the new frame
    SDL_RenderPresent(renderer);

    // Don't forget to free your surface and texture


}