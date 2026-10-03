#ifndef PLATFORM_SDL_H 
#define PLATFORM_SDL_H

#include "../window.hpp"
#include <string>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

struct SDLWindow;
struct SDLKeyboard;
struct SDLMouse;

struct SDLWindow : public Window {
public:
    SDL_Window* game_window; // this is the SDL object, not my own class

    SDLWindow() = default;
    SDLWindow(int width, int height, const std::string& title);
    ~SDLWindow() override;

    void prepare_frame() override;
    void end_frame() override;
    bool is_close_requested() override;
    void close() override;
    bool resized() override;

private:
    bool _resized;
    int width;
    int height;
};

struct SDLKeyboard {
public:
    //TODO(Jack): finish
};

struct SDLMouse {
public:
    //TODO(Jack): finish
};

#endif
