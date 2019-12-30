#pragma once
#include "Managers/EntityManager.h"
#include "Managers/ComponentManager.h"
#include <memory>
#include <cassert>

class EntityHandle;

using namespace std;

class World {
public:
	World();
	~World();

	Entity* createEntity();
	void destroyEntity(Entity* e);

	//attach a component of a specified type to an entity
	template <typename ComponentType, typename = std::enable_if<std::is_base_of<Component, ComponentType>::value>>
	void attachComponent(Entity* e, std::shared_ptr<ComponentType> component) {
		getComponentManager<ComponentType>()->addComponent(component);
		const char* typeName = typeid(ComponentType).name();
		e->m_componentMap.emplace(typeName, component);
	}


	//get component manager for specified type
	template <typename ComponentType>
	ComponentManager<ComponentType>* getComponentManager() {
		auto found = m_componentManagers.find(typeid(ComponentType));
		if (found == m_componentManagers.end()) {
			assert("This is no component manager for this component type.");
			return nullptr;
		}
		return dynamic_cast<ComponentManager<ComponentType>*>(found->second);
	}

private:
	std::unique_ptr<EntityManager> m_entityManager;
	std::unordered_map<std::type_index, BaseComponentManager*> m_componentManagers;
};

