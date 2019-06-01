#pragma once
#include "Managers/ComponentManager.h"
#include "Entity.h"
#include <memory>
#include <typeindex>

/*
Class to keep track of entities and components by storing pointers to them.
*/

class Tracker {
public:
	Tracker() {
		//register the component managers
		m_componentManagers.emplace(typeid(DrawComponent), new ComponentManager<DrawComponent>());
		m_componentManagers.emplace(typeid(TransformComponent), new ComponentManager<TransformComponent>());
	}

	~Tracker() {}

	Entity* trackEntity() {
		Entity* entity = new Entity(m_entityId++);
		m_entities.emplace(m_entityId, entity);
		return entity;
	}

	void untrackEntity() {

	}

	template <typename ComponentType>
	void trackComponent(Entity* e, ComponentType&& component) {

	}

	template <typename ComponentType>
	void untrackComponent(ComponentType* component) {

	}

	//get component manager for specified type
	template <typename ComponentType>
	ComponentManager<ComponentType>* getComponentManager() {
		auto found = m_componentManagers.find(typeid(ComponentType));
		return dynamic_cast<ComponentManager<ComponentType>*>(found->second);
	}

private:
	std::unordered_map<std::type_index, BaseComponentManager*> m_componentManagers;
	std::unordered_map<uint, Entity*> m_entities;
	int m_entityId = 0;
};