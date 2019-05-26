#pragma once
#include "Managers/EntityManager.h"
#include "World.h"

class EntityHandle {
public:
	EntityHandle(Entity entity) : m_entity(entity) {}
	~EntityHandle() {
		
	}

	template <typename ComponentType>
	void attachComponent(ComponentType* component) {
		
	}

	void destroy() {

	}

	Entity m_entity;
	World* world;
};