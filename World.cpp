#include "World.h"

World::World() {
	m_entityManager = std::make_unique<EntityManager>();
	//m_componentManager = std::make_unique<AComponentManager>();

	//m_componentManagers.emplace(typeid(DrawComponent), new ComponentManager<DrawComponent>());
	//m_componentManagers.emplace(typeid(TransformComponent), new ComponentManager<TransformComponent>());
	//m_componentManagers.emplace(typeid(MotionComponent), new ComponentManager<MotionComponent>());
	//m_componentManagers.emplace(typeid(InputComponent), new ComponentManager<InputComponent>());
	//m_componentManagers.emplace(typeid(CollisionComponent), new ComponentManager<CollisionComponent>());
}

World::~World() {

}

EntityHandle& World::CreateEntity()
{
	const Entity entity = m_entityManager->CreateEntity();
	EntityHandle handle(entity, this);
	return handle;
}

void World::DestroyEntity(Entity* e) 
{
	////set the components of the entity to inactive so they do not get processed
	//for (auto component : e->m_componentMap)
	//{
	//	component.second->setActive(false);
	//	//set the entity pointer in the component to null. These components will then 
	//	//be destroyed at the end of a game loop iteration.
	//	component.second->setNullEntity();
	//}

	//destroy the entity
	int deletedEntityId = m_entityManager->DeleteEntity(e);
}

template <typename ComponentType>
void World::AddComponent(const Entity& entity, std::shared_ptr<ComponentType> component)
{
	auto& componentManager = GetComponentManager<ComponentType>()->AddComponent(&entity, component);
}