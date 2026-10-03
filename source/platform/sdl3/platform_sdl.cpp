#include "./platform_sdl.hpp"
#include <iostream>


SDLWindow::SDLWindow(int width, int height, const std::string &title) {
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
        this->~SDLWindow();
    } else {
        SDL_WindowFlags window_flags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN | SDL_WINDOW_HIGH_PIXEL_DENSITY;
        game_window = SDL_CreateWindow( "JamEngine", width, height, window_flags);
        if(game_window == nullptr)
        {
            SDL_Log( "Window could not be created! SDL error: %s\n", SDL_GetError());
            this->~SDLWindow();
        }
        SDL_GLContext game_gl_context = SDL_GL_CreateContext(game_window);
        SDL_GL_MakeCurrent(game_window, game_gl_context);
        SDL_GL_SetSwapInterval(1); // Enable vsync
        SDL_SetWindowPosition(game_window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
        SDL_ShowWindow(game_window);
  }
}

SDLWindow::~SDLWindow() {
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
    if (this->game_window == nullptr) {
        return;
    }
    SDL_Quit();
    std::exit(0);
}

void SDLWindow::prepare_frame(){
  //TODO(Jack): finish
}

void SDLWindow::end_frame(){
  //TODO(Jack): finish
}

bool SDLWindow::is_close_requested(){
    //TODO(Jack): finish
    return false;
}

void SDLWindow::close(){
  //TODO(Jack): finish
}

bool SDLWindow::resized(){
    //TODO(Jack): finish
    return false;
}

