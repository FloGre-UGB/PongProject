#include "KeyboardHandler.hpp"
#include <iostream>
void KeyboardHandler::fetchKeyboardStates(){
    keyboardStates = SDL_GetKeyboardState(NULL);
}

void KeyboardHandler::handleKeyboardStates(bool* doQuit, GameState* state, const unsigned int gameSpeed){
    // check for Escape 
    bool checkUpCollision = false;
    bool checkDownCollision = false; 
    if (keyboardStates[SDL_SCANCODE_ESCAPE]){
        *doQuit = true; 
    }
    // Check for movement commands 
    if (keyboardStates[SDL_SCANCODE_UP]){
        state->right.moveUp(gameSpeed);
        checkUpCollision = true;
    }
    if (keyboardStates[SDL_SCANCODE_DOWN]){
        state->right.moveDown(gameSpeed, state->screen_height);
        checkDownCollision = true;
    }
    if (keyboardStates[SDL_SCANCODE_W]){
        state->left.moveUp(gameSpeed);
        // check for collision with ball and give it a cut if there is a collision
        checkUpCollision = true;
    }
    if (keyboardStates[SDL_SCANCODE_S]){
        state->left.moveDown(gameSpeed, state->screen_height);
        checkDownCollision = true; 
    }

    if (checkUpCollision){
        state->checkCollision(-1);
    }

    if (checkDownCollision){
        state->checkCollision(1);
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