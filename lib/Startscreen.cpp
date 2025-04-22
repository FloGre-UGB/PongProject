#include "Startscreen.hpp"

// Constructor 
Startscreen::Startscreen(const int x, const int y, const int w, const int h, 
    const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a, 
    SDL_Renderer* renderer, const char* titleFontFile, const char* subtitleFontFile){
    
        Col = {r,g,b,a};
    
        titleFont = TTF_OpenFont(titleFontFile, 28);
        hPosTitle = x;
        vPosTitle = y;
        heightTitle = h;
        widthTitle = w;
        titleRect = SDL_Rect{hPosTitle, vPosTitle, widthTitle, heightTitle};
        title = "PONG";
    
        subtitleFont = TTF_OpenFont(subtitleFontFile, 28);
        vPosSubtitle = y+h;
        hPosSubtitle = x/2;
        heightSubtitle = h/4;
        widthSubtitle = w + x;
        subtitleRect = SDL_Rect{hPosSubtitle,vPosSubtitle, widthSubtitle, heightSubtitle};
        subtitle = "Starting in 5 seconds";
    
        // make surface 
        titleSurface = TTF_RenderUTF8_Solid(titleFont, title.c_str(), Col);
        if (titleSurface == NULL){
            std::cout << "start Surface creation did not work" << std::endl;
        }
        // make texture
        titleTexture = SDL_CreateTextureFromSurface(renderer, titleSurface);  
        if (titleTexture == NULL){
            std::cout << "start Texture creation did not work" << std::endl;
        }
    
        // make surface 
        subtitleSurface = TTF_RenderUTF8_Solid(subtitleFont, subtitle.c_str(), Col);
        if (titleSurface == NULL){
            std::cout << "start Surface creation did not work" << std::endl;
        }
        // make texture
        subtitleTexture = SDL_CreateTextureFromSurface(renderer, subtitleSurface);  
        if (titleTexture == NULL){
            std::cout << "start Texture creation did not work" << std::endl;
        }
    
    
    }

Startscreen::~Startscreen(){
    TTF_CloseFont(titleFont);
    TTF_CloseFont(subtitleFont);
    SDL_DestroyTexture(titleTexture);
    SDL_FreeSurface(titleSurface);
    SDL_DestroyTexture(subtitleTexture);
    SDL_FreeSurface(subtitleSurface);
}

void Startscreen::updateTexture(SDL_Renderer* renderer, const int time){
    subtitle = "Starting in " + std::to_string(time) + " seconds";
    // free old surface and texture 
    SDL_DestroyTexture(subtitleTexture);
    SDL_FreeSurface(subtitleSurface);
    // make surface 
    subtitleSurface = TTF_RenderUTF8_Solid(subtitleFont, subtitle.c_str(), Col);
    if (titleSurface == NULL){
        std::cout << "start Surface creation did not work" << std::endl;
    }
    // make texture
    subtitleTexture = SDL_CreateTextureFromSurface(renderer, subtitleSurface);  
    if (titleTexture == NULL){
        std::cout << "start Texture creation did not work" << std::endl;
    }
}