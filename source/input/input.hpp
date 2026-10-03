# ifndef INPUT_H
# define INPUT_H

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
