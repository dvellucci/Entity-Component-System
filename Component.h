#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

typedef unsigned int uint;

class Component {
public:
	Component(uint id) : m_id(id), m_isActive(true) {

	}

	virtual ~Component() {

	}

	void setActive(bool active) { m_isActive = active; }
	uint getId() { return m_id; }
	bool getIsActive() { return m_isActive; }

private:
	uint m_id;
	bool m_isActive;
};
