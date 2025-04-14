#include "ScoreboardRect.hpp"

ScoreboardRect::ScoreboardRect(int vert_pos, int hor_pos, int h, int w, unsigned short points,
    Uint8 r, Uint8 g, Uint8 b, Uint8 a, SDL_Renderer* renderer, TTF_Font* font){
    Font = font; 

    // set text color
    Col ={r,g,b,a};
    
    // make rect
    scoreRect = SDL_Rect{hor_pos, vert_pos, w, h};
    
    points_displayed = std::to_string(points);

    // make surface 
    //scoreSurface = TTF_RenderText_Solid(Font, points_displayed.c_str(), Col); 
    scoreSurface = TTF_RenderUTF8_Solid(Font, points_displayed.c_str(), Col);
    if (scoreSurface == NULL){
        std::cout << "Surface creation did not work" << std::endl;
    }
    // make texture
    scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);  
    if (scoreTexture == NULL){
        std::cout << "Texture creation did not work" << std::endl;
    }

}

ScoreboardRect::~ScoreboardRect(){
    SDL_DestroyTexture(scoreTexture);
    SDL_FreeSurface(scoreSurface);
    
}

void ScoreboardRect::setScore(unsigned short points){
    points_displayed = std::to_string(points); 
}


void ScoreboardRect::updateTexture(SDL_Renderer* renderer){
    SDL_DestroyTexture(scoreTexture);
    SDL_FreeSurface(scoreSurface);
    scoreSurface = TTF_RenderText_Solid(Font, points_displayed.c_str(), Col); 
    scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface); 
    if (scoreTexture == NULL){
        std::cout << "ScoreboardRect::updateTexture: Texture recreation did not work" << std::endl;
    }
}

void ScoreboardRect::updateScoreboard(unsigned short points, SDL_Renderer* renderer){
    this->setScore(points);
    this->updateTexture(renderer);
}