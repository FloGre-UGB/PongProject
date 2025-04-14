#pragma once
#include <string>
#include <SDL2/SDL_ttf.h>
#include <iostream>


struct Startscreen
{
    TTF_Font* titleFont; 
    TTF_Font* subtitleFont; 
    SDL_Color Col; 

    int vPosTitle;
    int hPosTitle;
    int heightTitle; 
    int widthTitle;
    std::string title; 
    SDL_Rect titleRect; 
    SDL_Surface * titleSurface; 
    SDL_Texture * titleTexture; 
    
    int vPosSubtitle;
    int hPosSubtitle;
    int heightSubtitle; 
    int widthSubtitle;
    std::string subtitle; 
    SDL_Rect subtitleRect; 
    SDL_Surface * subtitleSurface;
    SDL_Texture * subtitleTexture; 

    Startscreen() = default; 
    Startscreen(const int x, const int y, const int w, const int h, const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a, SDL_Renderer* renderer, TTF_Font* titleFont, TTF_Font* subtitleFont);

    ~Startscreen();

    void updateTexture(SDL_Renderer* renderer, const int time);
    
};
