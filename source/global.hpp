#ifndef GLOBAL_H
#define GLOBAL_H

#include "./input/input.hpp"
#include "./render/render.hpp"
#include "./platform/platform.hpp"

// Forward Declarations
struct RenderManager;
struct InputManager;
struct PlatformManager;

struct Global {
  static const int window_width  = 800;
  static const int window_height = 600;

  InputManager* input;
  RenderManager* render;
  PlatformManager* platform;
};

extern Global global;

#endif 
