#pragma once 
#include "GameStateClass.hpp"
#include <SDL2/SDL.h>

struct KeyboardHandler{
    private:
        const Uint8 * keyboardStates; 

    public:
        //Constructor
        KeyboardHandler() = default;

        void fetchKeyboardStates();

        void handleKeyboardStates(bool* doQuit, GameState* state, const unsigned int gameSpeed);

};