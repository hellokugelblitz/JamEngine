#ifndef SYSTEM_H 
#define SYSTEM_H

#include "s_base.hpp"

// A System will have a reference to every component that is important to it.

template <struct... Comps>
struct System : public BaseSystem {
protected:
  // a tuple of component pointers, these are the components that our system cares about
  // todo(jack): what is add_pointer
  using CompTuple = std::tuple<std::add_pointer<Comps>...>;
  std::vector<CompTuple, SOMETHINGPOOL> _components; 

public:
  ComponentSystem(EntityManager* entity_manager) : BaseSystem(entity_manager) { } // wtf is this shit

  virtual void on_entity_created(const Entity& entity) override final;
  virtual void on_entity_destroyed(const Entity& entity) override final;

private:
  // when an entity is created, we ar going to expand this guy.. 
  // we are going to loop through the entity, grab the components and do an internal procress on them.

  //recursivley looks through components types
};

template <struct... Comps>
void System<Comps...>::on_entity_created(const Entity& entity)
{
  // Loop and see if any tuples match
  CompTupple compTuple;
  unsigned int matchingComps = 0;

  for(auto& compPair : entity.get_components())
  {
    if(proesses_entity_component<0, Comps...>(compPair.first, compPair.second, compTuple))
    {

    }
  }

}

#endif
