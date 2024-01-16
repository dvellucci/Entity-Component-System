#pragma once
#include "../Entity.h"
#include "ComponentManager.h"
#include "../EntityHandle.h"
#include <vector>
#include <typeindex>
#include <unordered_map>
#include <stack>
#include <iostream>

typedef unsigned int uint;

class EntityManager {
public:
	EntityManager();
	~EntityManager();

	const Entity& CreateEntity();
	int DeleteEntity(Entity*& e);

	std::unordered_map<uint, Entity*>& getEntityMap() {   }

	//Entity* getEntity(uint id) { return m_entityMap[id]; }

private:
	std::unordered_map<uint, Entity> _entityMap;
	std::vector<std::unique_ptr<Entity>> _entities;

	//reuse ids of deleted entities
	std::stack<uint> m_availableIds;

	int m_entityId = 0;
};
