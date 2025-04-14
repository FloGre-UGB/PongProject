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
    /*
    if (keyboardStates[SDL_SCANCODE_RIGHT]){
        state->right.moveRight(gameSpeed, state->screen_width, false);
    }
    if (keyboardStates[SDL_SCANCODE_LEFT]){
        state->right.moveLeft(gameSpeed, state->screen_width, false);
    }
    if (keyboardStates[SDL_SCANCODE_A]){
        state->left.moveLeft(gameSpeed, state->screen_width, true);
    }
    if (keyboardStates[SDL_SCANCODE_D]){
        state->left.moveLeft(gameSpeed, state->screen_width, true);
    }
    */
       
}