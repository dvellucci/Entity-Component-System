#pragma once
#include "Entity.h"
#include "World.h"

class Entity;
class World;

class EntityHandle
{
public:

	EntityHandle(Entity entity, World* world);
	~EntityHandle();
	
	//Look up the usage of && to understand fully
	template <typename ComponentType>
	void AddComponent(ComponentType&& component);

private:
	Entity _entity;
	World* _world;
};