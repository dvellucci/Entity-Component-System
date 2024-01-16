#include "EntityHandle.h"


EntityHandle::EntityHandle(Entity entity, World* world)
	: _entity(entity),
	_world(world)
{
}

EntityHandle::~EntityHandle()
{
}

template <typename ComponentType>
void EntityHandle::AddComponent(ComponentType&& component)
{
	_world->AddComponent<ComponentType>(_entity, std::forward<ComponentType>(component));
}