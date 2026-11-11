#ifndef BASE_SYSTEM_H 
#define BASE_SYSTEM_H 

struct BaseSystem {
protected:
  EntityManager* _entity_manager;
public:
  explicit BaseSystem(EntityManager* entity_manager) : _entity_manager(entity_manager) { };
  virtual ~BaseSystem() = default;

  virtual void on_entity_created(const Entity& entity) = 0;
  virtual void on_entity_destroyed(const Entity& entity) = 0;
  virtual void update() = 0; // todo(jack): some kind of delta time?
};


#endif
