#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <glad/glad.h>

#include "../global.hpp"
#include "render.hpp"

/* Global Variables */
int RenderManager::render_init(int width, int height)
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) == false )
    {
        SDL_Log( "SDL could not initialize! SDL error: %s\n", SDL_GetError() );
        return -1;
    } else {
        SDL_WindowFlags window_flags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN | SDL_WINDOW_HIGH_PIXEL_DENSITY;
        game_window = SDL_CreateWindow( "JamEngine", width, height, window_flags);
        if(game_window == nullptr)
        {
            SDL_Log( "Window could not be created! SDL error: %s\n", SDL_GetError());
            return -1;
        }
        SDL_GLContext game_gl_context = SDL_GL_CreateContext(game_window);
        SDL_GL_MakeCurrent(game_window, game_gl_context);
        SDL_GL_SetSwapInterval(1); // Enable vsync
        SDL_SetWindowPosition(game_window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
        SDL_ShowWindow(game_window);

        // TODO(JACK): move out to seperate func
        if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return -1;
        }
        
        glViewport(0,0, Global::window_width, Global::window_height);
        glClearColor(255,255,255,255);
        glClear(GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(game_window);
    }
    return 0;
}

