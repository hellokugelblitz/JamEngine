#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <glad/glad.h>

#include "../global.hpp"
#include "render.hpp"

/* Global Variables */
int RenderManager::render_init()
{
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    
    glViewport(0,0, Global::window_width, Global::window_height);
    glClearColor(255,255,255,255);
    glClear(GL_COLOR_BUFFER_BIT);
    return 0;
}

