#ifndef ENTITY_UTILS_H
#define ENTITY_UTILS_H

const unsigned int MAX_ENTITIES = 100; // todo(jack): meaningfully assign max entities size at compile time
const unsigned int MAX_COMPONENTS = 32;
typedef unsigned int EntityId;
typedef unsigned int ComponentId;

// Use enum as apposed to auto increment? Or enum with auto increment?
// Silly way of doing this but whatever: https://generate-random.org/hexadecimal-numbers
enum ComponentTypeId {
  TRANSFORM = 0xB4EBDB50,
  RENDERABLE = 0x4A0B9C1B
};

#endif
