#include <iostream>
//#include "../vendor/SDL/include/SDL3/SDL.h" // remove when not needed anymore please
///#include "../vendor/SDL/include/SDL3/SDL_main.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "graphics/resource_manager.hpp"
#include "graphics/render.hpp"
#include "input/input.hpp"
#include "platform/platform.hpp"
#include "platform/sdl3/platform_sdl.hpp"
#include "global.hpp"

/*
    General Engine Major TODO List
        World Abstraction Session 6-7 
            Entities
            Components
            World
        Take Input from the User ( Input / Keyboard thing, Bring out SDL Input Events into callback ) * Session 6?
        Utils (Type Management, Helpful code preprocessor statements, i.e. determine type standards for vectors "are we using glm or custom?")
        Sound
        Platform support Windows ( not mac )
*/

Global global; // Global state. Holds raw pointers to subsystems on the heap.

int main() {
    std::cout << "Welcome to JameEngine!" << std::endl;
    std::cout << "Initializing SDl3" << std::endl;

    // Remember: Allocate in reverse order of how they should be destructed.
    PlatformManager platform_manager; // platform has a window
    global.platform_manager = &platform_manager;

    platform_manager.window = new SDLWindow(global.window_width, global.window_height, "New Window!");
    platform_manager.window->init_graphics_context();

    ResourceManager resource_manager;
    global.resource_manager = &resource_manager;

    RenderManager render_manager;
    global.render_manager = &render_manager;

    InputManager input_manager;
    global.input_manager = &input_manager;
   
    // TODO(Jack): get some sort of renderer pass function where we (this is part of Level/World implementation):
        // Set the shaders for the sprites -> draw the sprites
        // Set the shaders for the effects -> draw the effects
        // etc...

    resource_manager.load_shader("../assets/sprite.vs", "../assets/sprite.frag", nullptr, "sprite"); // read shader?
    global.render_manager->set_shader(resource_manager.get_shader("sprite")); 

    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(global.window_width), static_cast<float>(global.window_height), 0.0f, -1.0f, 1.0f);
    resource_manager.get_shader("sprite").Use().SetInteger("image", 0);
    resource_manager.get_shader("sprite").SetMatrix4("projection", projection);
    resource_manager.load_texture("../assets/textures/texture.png", true, "texture");

    bool game_running = true;
    while(game_running) {
        global.render_manager->clear_screen(0,0,0,0);

        render_manager.draw_sprite(resource_manager.get_texture("texture"),glm::vec2(10.0f, 10.0f), glm::vec2(40.0f,40.0f), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
        render_manager.draw_sprite(resource_manager.get_texture("texture"),glm::vec2(50.0f, 10.0f), glm::vec2(40.0f,40.0f), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
        render_manager.draw_sprite(resource_manager.get_texture("texture"),glm::vec2(75.0f, 10.0f), glm::vec2(40.0f,40.0f), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));

        global.platform_manager->window->paint_frame();
        //Get event data
        SDL_Event event;
        // TODO(JACK): Move this to platform layer
        while( SDL_PollEvent( &event ) == true )
        {
            bool handleEventOutput = global.input_manager->process(event);
            if(!handleEventOutput) game_running = false; // quit game if player hits close
        }
    }

    std::cout << "Closing JameEngine" << std::endl;
    return 1;
}
