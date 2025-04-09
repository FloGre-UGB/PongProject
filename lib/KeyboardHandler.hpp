#pragma once 
#include "GameStateClass.hpp"
#include <SDL2/SDL.h>

struct KeyboardHandler{
    const Uint8 * keyboardStates; 

    //Constructor
    KeyboardHandler() = default;

    void fetchKeyboardStates();

    void handleKeyboardStates(bool* doQuit, GameState* state, const unsigned int gameSpeed);

};