#include "World.h"
#include "EntityHandle.h"

World::World() {
	m_entityManager = std::make_unique<EntityManager>();

	//register the component managers
	m_componentManagers.emplace(typeid(DrawComponent), new ComponentManager<DrawComponent>());
	m_componentManagers.emplace(typeid(TransformComponent), new ComponentManager<TransformComponent>());

	//register the systems

}

World::~World(){

}

Entity* World::createEntity() {
	return  m_entityManager->createEntity();
}

void World::destroyEntity() {

}
