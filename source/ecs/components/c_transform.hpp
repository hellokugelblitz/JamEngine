#ifndef TRANSFORM_H 
#define TRANSFORM_H 

#include "../component.h"
#include "../entity_utils.h"

struct TransformComponent : public Component {
private:
  ComponentTypeId _component_id = ComponentTypeId::TRANSFORM;
  glm::vec2 _position{0, 0}; // Could be public, components are just data holders

public:
  TransformComponent(); 

  //todo(jack): roll vec2 for app logic
  glm::vec2 get_position() const {
    return _position;
  }

  glm::vec2 set_position(glm::vec2 position) const {
    return _position = position;
  }
};

#endif
