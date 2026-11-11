#ifndef ENTITY_MANAGER_H 
#define ENTITY_MANAGER_H

#include <unordered_map>
#include <vector>

#include "entity.hpp"
#include "entity_utils.hpp"
#include "component.hpp"

struct EntityManager {
private:
  using Entities = std::unordered_map<EntityId, Entity>;
  using Components = std::vector<std::vector<Component>>;
  using Systems = std::vector<System>;

  Entities _entities;
  Components _components;
  Systems _systems;

public:
  EntityManager() = default;
  ~EntityManager();

  void create_systems(); // maybe needed
  void update(); // Maybe tick?

  EntityId create_entity();
  bool destroy_entity(EntityId entity_id);

};
#endif



