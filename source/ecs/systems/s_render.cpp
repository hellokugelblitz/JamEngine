#include "s_render.hpp"

void RenderSystem::update()
{
  for(auto& compTuple : _components)
  {
    TransformComponent* transform = std::get<TransformComponent*>(compTuple);
    RenderableComponent* renderable = std::get<TransformComponent*>(compTuple);

    // todo(jack): do rendering stuff!
  }
}

