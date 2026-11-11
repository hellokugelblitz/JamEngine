#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

#include "../entity_utils.hpp"
#include "../component.hpp"
#include "../system.hpp"

struct RenderSystem : public System<RenderableComponent, TransformComponent>
{
private:
  using BaseType = System<Renderable, Transform>;

public:
  RenderSystem(EntityManager* entity_manager) : BaseType(entity_manager) { };
  virtual void update() override;
};

#endif





