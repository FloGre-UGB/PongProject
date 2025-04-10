#include "KeyboardHandler.hpp"
#include <iostream>
void KeyboardHandler::fetchKeyboardStates(){
    keyboardStates = SDL_GetKeyboardState(NULL);
}

void KeyboardHandler::handleKeyboardStates(bool* doQuit, GameState* state, const unsigned int gameSpeed){
    // check for Escape 
    if (keyboardStates[SDL_SCANCODE_ESCAPE]){
        *doQuit = true; 
    }
    // Check for movement commands 
    if (keyboardStates[SDL_SCANCODE_UP]){
        state->right.moveUp(gameSpeed);
    }
    if (keyboardStates[SDL_SCANCODE_DOWN]){
        state->right.moveDown(gameSpeed, state->screen_height);
    }
    if (keyboardStates[SDL_SCANCODE_W]){
        state->left.moveUp(gameSpeed);
    }
    if (keyboardStates[SDL_SCANCODE_S]){
        state->left.moveDown(gameSpeed, state->screen_height);
    }
}