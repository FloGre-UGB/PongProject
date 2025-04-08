#include "RendererClass.hpp"
#include <SDL2/SDL.h>
Renderer::Renderer(SDL_Window * w){
    window = w; 
    renderer = SDL_CreateRenderer(window , -1, SDL_RENDERER_ACCELERATED);
}   

void Renderer::draw(GameState * state){
    // Drawing the background
    SDL_SetRenderDrawColor(renderer , 0, 0, 0, 0);
    SDL_RenderClear(renderer);


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

}