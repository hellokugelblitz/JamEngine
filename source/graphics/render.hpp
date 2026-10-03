#ifndef RENDER_H
#define RENDER_H 

// This class handles Input (key presses) and provides methods to handle them.
struct RenderManager {
public:
    SDL_Window* game_window;
    int render_init(int width, int height);
};


#endif 
