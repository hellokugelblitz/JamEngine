#ifndef COMPONENT_H 
#define COMPONENT_H 

#include "entity_utils.h"

// Component Rules:
  // Components hold data only
  // Hold a reference to an entity.

class Component {
private:
  EntityId _entity_id; // keep a private reference to the entity this component belongs to
  unsigned int _component_array_index; // todo(jack): delete?

public:
  Component() : _entity_id(0), _component_array_index(0) {}
  virtual bool init(); // Pass location of some XML?

  // Getters and Setters
  EntityId get_entity_id() const { return _entityId; }

  //void set_component_array_index(unsigned int index) { _component_array_index = index; }
  //void get_component_array_index() const { return _component_array_index; }
};

#endif
