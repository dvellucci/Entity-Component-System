#pragma once
#include "Managers/EntityManager.h"
#include "Managers/ComponentManager.h"
#include "Tracker.h"
#include <memory>
#include <type_traits>

class EntityHandle;

class World {
public:
	World();
	~World();

	Entity* createEntity();
	void destroyEntity(Entity* e);

	//attach specified component to given entity
	template <typename ComponentType, typename = std::enable_if<std::is_base_of<Component, ComponentType>::value>>
	ComponentType* attachComponent(Entity* e, ComponentType&& component) {
		//add component to manager
		ComponentType* newComponent = getComponentManager<ComponentType>()->addComponent(e, &component);
		//store component pointer in entity
		e->addComponent(reinterpret_cast<Component*>(&newComponent));
		return newComponent;
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
};

