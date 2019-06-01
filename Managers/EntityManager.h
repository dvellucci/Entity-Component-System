#pragma once
#include "../Entity.h"
#include "ComponentManager.h"
#include <vector>
#include <typeindex>
#include <unordered_map>
#include <stack>

typedef unsigned int uint;

//forward declare EntityHandle to define createEntity function
class EntityHandle;

class EntityManager {
public:
	EntityManager();
	~EntityManager();

	Entity* createEntity();
	void deleteEntity(Entity* e);

	std::unordered_map<uint, Entity*>& getEntityMap() { return m_entityMap; }

	Entity* getEntity(uint id) { return m_entityMap[id]; }

private:
	std::unordered_map<uint, Entity*> m_entityMap;

	//reuse ids of deleted entities
	std::stack<uint> m_availableIds;

	int m_entityId = 0;
};
