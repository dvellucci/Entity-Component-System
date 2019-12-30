#pragma once
#include <SFML/Graphics.hpp>
#include "../Entity.h"

typedef unsigned int uint;

//forward declaration
class Entity; 

class Component {
public:
	Component() = default;
	Component(Entity* owner) : m_isActive(true), m_owner(owner) { }

	virtual ~Component() { }

	void setActive(bool active) { m_isActive = active; }

	inline bool getIsActive() { return m_isActive; }
	inline Entity* getOwner() { return m_owner; }
	inline void setNullEntity() { m_owner = nullptr; }

private:
	bool m_isActive;
	Entity* m_owner;
};
