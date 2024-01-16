#include "EntityManager.h"

EntityManager::EntityManager() {

}

EntityManager::~EntityManager() {
	
}

const Entity& EntityManager::CreateEntity()
{
	uint entityId = 0;

	//check if there is a re-usable id
	if (m_availableIds.empty()) {
		entityId = ++m_entityId;
	}
	else {
		entityId = m_availableIds.top();
		m_availableIds.pop();
	}

	//auto entity = std::make_unique<Entity>(entityId);
	//_entities.push_back(entity);

	Entity entity(entityId);
	return entity;
}

int EntityManager::DeleteEntity(Entity*& e) {
	////set the entity's components to false so they don't get processed
	//for (auto component : e->getComponents()) 
	//{
	//	component.second->setActive(false);
	//}
	//  
	///add the entities id to the stack of available ids
	int id = e->GetId();
	//Add an assert in case we are deleting an entity that already does not exist
	m_availableIds.push(id);
	_entityMap.erase(id);
	return id;
	//delete e;
	////remove the entity from the map and delete it
	//m_entityMap.erase(e->getId());
	
}
