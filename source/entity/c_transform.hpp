#ifndef TRANSFORM_H 
#define TRANSFORM_H 

#include <iostream>
#include "Component.h"

class TransformComponent : public Component {
public:
  TransformComponent() {
    std::cout << "TransformComponent created\n";
  }

  void Tick(float DeltaTime) override {
    std::cout << "TransformComponent ticking\n";
  }

  //todo(jack): roll vec2 for app logic
  glm::vec2 GetPosition() const {
    return Position;
  }

private:
  glm::vec2 Position{0, 0};
};

#endif
