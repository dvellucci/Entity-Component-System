#include "EntityManager.h"

EntityManager::EntityManager() {

}

EntityManager::~EntityManager() {
	
}

Entity* EntityManager::createEntity()
{
	uint entityId = 0;

	//check if there is a re-usable id
	if (m_availableIds.empty()) {
		entityId = m_entityId++;
	}	
	else {
		entityId = m_availableIds.top();
		m_availableIds.pop();
	}

	Entity* entity = new Entity(entityId);
	m_entityMap.emplace(entityId, entity);

	return entity;
}

void EntityManager::deleteEntity(Entity* e) {
	m_entityMap.erase(e->getId());
}
