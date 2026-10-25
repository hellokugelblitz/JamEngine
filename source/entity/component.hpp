#ifndef COMPONENT_H 
#define COMPONENT_H 

#include <SDL3.h>

class Component {
public:
  virtual void handle_events(const SDL_Event& E) {}
  virtual void tick(float DeltaTime) {}
  virtual void render(SDL_Surface* Surface) {}
  virtual ~Component() = default;
};
#endif
