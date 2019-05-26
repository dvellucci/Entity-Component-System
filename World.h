#pragma once
#include "Managers/EntityManager.h"
#include "Systems/System.h"
#include "Managers/ComponentManager.h"
#include <memory>

class EntityHandle;

class World {
public:
	World();
	~World();

	Entity* createEntity();
	void destroyEntity();

	//attach specified component to given entity
	template <typename ComponentType>
	void attachComponent(Entity* e, ComponentType&& component) {
		ComponentManager<ComponentType>* manager = getComponentManager<ComponentType>();
		manager->addComponent(e, &component);
	}

	//get component manager for specified type
	template <typename ComponentType>
	ComponentManager<ComponentType>* getComponentManager() {
		auto found = m_componentManagers.find(typeid(ComponentType));
		return dynamic_cast<ComponentManager<ComponentType>*>(found->second);
	}

private:
	std::unique_ptr<EntityManager> m_entityManager;
	std::unordered_map<std::type_index, BaseComponentManager*> m_componentManagers;
	std::vector<std::unique_ptr<System>> m_systems;
};