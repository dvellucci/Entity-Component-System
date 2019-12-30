#include "World.h"

World::World() {
	m_entityManager = std::make_unique<EntityManager>();

	m_componentManagers.emplace(typeid(DrawComponent), new ComponentManager<DrawComponent>());
	m_componentManagers.emplace(typeid(TransformComponent), new ComponentManager<TransformComponent>());
	m_componentManagers.emplace(typeid(MotionComponent), new ComponentManager<MotionComponent>());
	m_componentManagers.emplace(typeid(InputComponent), new ComponentManager<InputComponent>());
	m_componentManagers.emplace(typeid(CollisionComponent), new ComponentManager<CollisionComponent>());
}

World::~World() {

}

Entity* World::createEntity() {
	return m_entityManager->createEntity();
}

void World::destroyEntity(Entity* e) 
{
	//set the components of the entity to inactive so they do not get processed
	for (auto component : e->m_componentMap)
	{
		component.second->setActive(false);
		//set the entity pointer in the component to null. These components will then 
		//be destroyed at the end of a game loop iteration.
		component.second->setNullEntity();
	}

	//destroy the entity
	m_entityManager->deleteEntity(e);
}
