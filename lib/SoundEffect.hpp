#pragma once

#include <SDL2/SDL_mixer.h>
#include <string>


struct SoundEffect{
    private:
        std::string fileName;
        int formatFlags;
        Mix_Chunk* effect; 
    
    public: 
        SoundEffect()=default; 
        SoundEffect(std::string file, const int flags);
        ~SoundEffect();

        void playEffect(const short reps=1);

};