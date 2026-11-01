# ifndef INPUT_H
# define INPUT_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "../../vendor/glad/glad.h"

// This class handles Input (key presses) and provides methods to handle them.
struct InputManager {
public:
    // Process currently pressed keys and call the associated callback functions
    bool process(SDL_Event event);
    // Register a keyBinding
    void bind();
    // Unregister a keyBinding
    void unbind();
};


#endif
