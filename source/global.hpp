#ifndef GLOBAL_H
#define GLOBAL_H

#include "./input/input.hpp"
#include "./graphics/render.hpp"
#include "./graphics/resource_manager.hpp"
#include "./platform/platform.hpp"

// Forward Declarations
struct RenderManager;
struct InputManager;
struct PlatformManager;
struct ResourceManager;

struct Global {
  static const int window_width  = 800;
  static const int window_height = 600;

  InputManager* input_manager;
  RenderManager* render_manager;
  PlatformManager* platform_manager;
  ResourceManager* resource_manager;
};

extern Global global;

#endif
