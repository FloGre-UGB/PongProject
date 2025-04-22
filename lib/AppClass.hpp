#pragma once 
#include <SDL2/SDL.h>

struct App{
    private:
        bool running;
        unsigned int screen_width;
        unsigned int screen_height;
        unsigned int timedelta; 
        unsigned int gameSpeed;
        SDL_Window * window;
        SDL_Surface * surface; 


    public:

        App(const unsigned int width, const unsigned int height);

        ~App(); 
        
        void run();

        void setSpeed(const unsigned int newSpeed);

        SDL_Window * getWindow();
}; 