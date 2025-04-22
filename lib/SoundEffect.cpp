#include "SoundEffect.hpp"
#include <iostream>

SoundEffect::SoundEffect(std::string file, const int flags) {
    int initted = Mix_Init(flags);
    if ((initted & flags) != flags) {
        std::cerr << "Mix_Init: Failed to init SDL_mixer: " << Mix_GetError() << std::endl;
        std::exit(1);
    }

    if (Mix_OpenAudio(44100, AUDIO_U8, 2, 2048) < 0) {
        std::cerr << "Mix_OpenAudio error: " << Mix_GetError() << std::endl;
        std::exit(1);
    }

    effect = Mix_LoadWAV(file.c_str());
    if (!effect) {
        std::cerr << "Mix_LoadWAV failed: " << Mix_GetError() << std::endl;
    }
}

SoundEffect::~SoundEffect() {
    Mix_FreeChunk(effect);
    Mix_CloseAudio();
    Mix_Quit();
}

void SoundEffect::playEffect(const short reps) {
    if (Mix_PlayChannel(-1, effect, reps) == -1) {
        std::cerr << "Mix_PlayChannel failed: " << Mix_GetError() << std::endl;
    }
}
