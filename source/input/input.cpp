#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "input.hpp"

bool InputManager::process(SDL_Event event) {
     //If event is quit type
    if( event.type == SDL_EVENT_QUIT ) return false;
   
    // TODO(jack): switch statement
    return true;
}
