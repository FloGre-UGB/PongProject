#pragma once
#include <SDL2/SDL_ttf.h>
#include <string>
#include <iostream>

struct ScoreboardRect{
    private:
        int v_pos;
        int h_pos;
        int height; 
        int width; 
        std::string points_displayed;

        TTF_Font* Font; 
        SDL_Color Col; 

        SDL_Surface * scoreSurface; 

    public:
        SDL_Rect scoreRect; 

        SDL_Texture * scoreTexture; 

        ScoreboardRect() = default; 

        ScoreboardRect(const int vert_pos, const int hor_pos, const int h, const int w, const unsigned short points,
            const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a, SDL_Renderer* renderer, TTF_Font* const font);

        ScoreboardRect(const int vert_pos, const int hor_pos, const int h, const int w, const unsigned short points,
            const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a, SDL_Renderer* renderer, const char* file);
        
        ~ScoreboardRect();
        
        void setScore(const unsigned short points);

        void updateTexture(SDL_Renderer* renderer);
        
        void updateScoreboard(const unsigned short points, SDL_Renderer* renderer);

};