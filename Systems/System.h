#pragma once
#include "../Entity.h"

class System {
public:
	System() {
	}

	virtual ~System() {
	}

	virtual void update(int dt) = 0;

	void registerEntity(Entity& entity) {
		m_registeredEntities.push_back(entity);
	}

private:
	std::vector<Entity> m_registeredEntities;
};