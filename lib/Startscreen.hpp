#pragma once
#include <string>
#include <SDL2/SDL_ttf.h>
#include <iostream>


struct Startscreen
{
    private:
        int vPosTitle;
        int hPosTitle;
        int heightTitle; 
        int widthTitle;
        std::string title; 
        TTF_Font* titleFont; 
        SDL_Surface * titleSurface; 

        int vPosSubtitle;
        int hPosSubtitle;
        int heightSubtitle; 
        int widthSubtitle;
        std::string subtitle; 
        TTF_Font* subtitleFont;
        SDL_Surface * subtitleSurface;

        SDL_Color Col; 

    public:    
        SDL_Rect titleRect; 
        SDL_Texture * titleTexture; 
        
        SDL_Rect subtitleRect; 
        SDL_Texture * subtitleTexture; 

        Startscreen() = default; 
        Startscreen(const int x, const int y, const int w, const int h, 
            const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a, 
            SDL_Renderer* renderer, TTF_Font* titleFont, TTF_Font* subtitleFont);

        Startscreen(const int x, const int y, const int w, const int h, 
            const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a, 
            SDL_Renderer* renderer, const char* titleFontFile, const char* subtitleFontFile);
        
        ~Startscreen();

        void updateTexture(SDL_Renderer* renderer, const int time);
        
};
