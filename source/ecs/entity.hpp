#ifndef ENTITY_H
#define ENTITY_H

#include "../util/types.hpp"
#include "entity_utils.hpp"
#include  "./component.hpp"
#include <memory>
#include <unordered_map>
#include <type_index>
#include <string>

// Entity Rules:
  // Entities are essentially IDs
  // Each entity will also carry a reference to the components it holds

struct Entity 
{
private:
  EntityID _entity_id; // Entity ID - Self explanitory
  std::unordered_map<ComponentId, Component*> _components; // Entities keep a reference table to the the Components they have attached.

public:
  EntityID get_entity_id() {return _entity_id}; // returns entity ID
};

#endif
