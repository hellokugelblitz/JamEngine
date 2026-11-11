#ifndef RENDERABLE_H 
#define RENDERABLE_H 

#include "../component.h"
#include "../entity_utils.h"

struct RenderableComponent : public Component {
private:
  ComponentTypeId _component_id = ComponentTypeId::RENDERABLE;

  // todo(jack): Bring in the rendering information for sprites and shit

public:
  RenderableComponent(); 

};

#endif
