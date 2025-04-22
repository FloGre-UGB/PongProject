#include "Music.hpp"

Music::Music(std::string file, const int flags){
    musicFile = file; 
    formatFlags = flags;

    // initiate Mixer libary and check that it worked 
    int initted = Mix_Init(flags);
    if((initted & flags) != flags) {
        std::cout << "Mix_Init: Failed to initiate Mixer library" << std::endl;
        std::exit(1);
    }

    if (Mix_OpenAudio(22050, AUDIO_U8, 2,2*16384) == -1) {
        std::cerr << "Mix_OpenAudio failed: " << Mix_GetError() << std::endl;
    }
    music = Mix_LoadMUS(file.c_str());

    if (!music) {
        std::cerr << "Mix_LoadMUS failed: " << Mix_GetError() << std::endl;
    }

}

Music::~Music(){
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    Mix_Quit();
}

void Music::playMusic(const short reps){
    Mix_PlayMusic(music, reps); 
    if (Mix_PlayingMusic()==0){
        std::cout << "Music not playing" << std::endl;
    }
}
