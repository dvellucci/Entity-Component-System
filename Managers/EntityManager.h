#pragma once
#include "../Entity.h"
#include "ComponentManager.h"
#include <vector>
#include <typeindex>
#include <unordered_map>

typedef unsigned int uint;

//forward declare EntityHandle to define createEntity function
class EntityHandle;

class EntityManager {
public:
	EntityManager();
	~EntityManager();

	Entity* createEntity();
	void deleteEntity(Entity* e);

	template <typename ComponentType>
	void attachComponent(Entity* e, ComponentType* component) {

	}

	std::map<uint, Entity*>& getEntityMap() { return m_entityMap; }
	void removeInActiveEntities();	

private:
	std::map<uint, Entity*> m_entityMap;
	std::map<Entity*, std::vector<Component*>> entityMap;

	int m_entityId = 0;
};
