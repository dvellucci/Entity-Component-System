#pragma once
#include "../Entity.h"
#include "ComponentManager.h"
#include <vector>
#include <typeindex>
#include <unordered_map>
#include <stack>
#include <iostream>

typedef unsigned int uint;

class EntityHandle;

class EntityManager {
public:
	EntityManager();
	~EntityManager();

	Entity* createEntity();
	void deleteEntity(Entity*& e);

	std::unordered_map<uint, Entity*>& getEntityMap() {   }

	Entity* getEntity(uint id) { return m_entityMap[id]; }

private:
	std::unordered_map<uint, Entity*> m_entityMap;

	//reuse ids of deleted entities
	std::stack<uint> m_availableIds;

	int m_entityId = 0;
};
