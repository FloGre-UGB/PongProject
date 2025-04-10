#pragma once
#include <SDL2/SDL_ttf.h>
#include <string>
#include <iostream>

struct ScoreboardRect{
    int v_pos;
    int h_pos;
    int height; 
    int width; 
    std::string points_displayed;

    TTF_Font* Font; 
    SDL_Color Col; 

    SDL_Rect scoreRect; 
    SDL_Surface * scoreSurface; 
    SDL_Texture * scoreTexture; 


    ScoreboardRect(int vert_pos, int hor_pos, int h, int w, unsigned short points,
        Uint8 r, Uint8 g, Uint8 b, Uint8 a, SDL_Renderer* renderer, TTF_Font* font);

    ~ScoreboardRect();
    
    void setScore(unsigned short points);

    void updateTexture(SDL_Renderer* renderer);
    
    void updateScoreboard(unsigned short points, SDL_Renderer* renderer);

};