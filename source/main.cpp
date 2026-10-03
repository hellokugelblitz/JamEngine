#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "render/render.hpp"
#include "input/input.hpp"
#include "platform/platform.hpp"
#include "platform/sdl3/platform_sdl.hpp" // TODO(jack): preprocessor statements for platform independence?
#include "global.hpp"

Global global; // Global state. Holds raw pointers to subsystems on the heap.

int main() {
    std::cout << "Welcome to JameEngine!" << std::endl;
    std::cout << "Initializing SDl3" << std::endl;

    PlatformManager platform; // platform has a window
    global.platform = &platform;
    platform.window = new SDLWindow(global.window_width, global.window_height, "New Window!");

    // Remember: Allocate in reverse order of how they should be destructed.
    RenderManager render;
    global.render = &render;
    //global.render->render_init(Global::window_width, Global::window_height);
    
    InputManager input;
    global.input = &input;
   
    bool game_running = true;
    SDL_Event event;
    while(game_running) {
        //Get event data
        while( SDL_PollEvent( &event ) == true )
        {
            bool handleEventOutput = global.input->process(event);
            if(!handleEventOutput) game_running = false; // quit game if player hits close
        }
    } 

    std::cout << "Closing JameEngine" << std::endl;
    return 1;
}
