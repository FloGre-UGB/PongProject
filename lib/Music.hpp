#pragma once 
#include <string>
#include <iostream>
#include <SDL2/SDL_mixer.h>

struct Music{
    private:
        std::string musicFile;
        int formatFlags;
        Mix_Music* music; 

    public:
        Music() = default; 
        Music(std::string file, const int flags);
        ~Music();

        void playMusic(const short reps=-1);   
};