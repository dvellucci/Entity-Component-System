#pragma once
#include "../Entity.h"
#include <map>

using ComponentIndex = unsigned int;

class EntityMap
{
public:
	EntityMap() {}
	~EntityMap() {}

	void Add(Entity entity, ComponentIndex index)
	{
		_entityComponentIndex.insert({ entity, index });
	}

private:
	std::map<Entity, ComponentIndex> _entityComponentIndex;
};