#include "EntityManager.h"
#include "../EntityHandle.h"

EntityManager::EntityManager() {

}

EntityManager::~EntityManager() {
	
}

Entity* EntityManager::createEntity()
{
	Entity* entity = new Entity(m_entityId++);
	m_entityMap.emplace(entity->getId(), entity);
	return entity;
}

void EntityManager::deleteEntity(Entity* e) {
	m_entityMap.erase(e->getId());
}

void EntityManager::removeInActiveEntities() {
	
}
