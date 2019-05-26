#pragma once
#include <SFML/Graphics.hpp>
#include <map>

class Entity;

namespace ComponentEnum {
	enum Enum {
		DRAW,
		COLLISION,
		VELOCITY,
		PHYSICS,
		TRANSFORM
	};
}

class Component {
public:
	Component(ComponentEnum::Enum type) : m_type(type) {

	}

	virtual ~Component() {

	}

	Entity* getOwner() { return m_owner; }
	int getType() { return m_type; }

private:
	Entity* m_owner;
	ComponentEnum::Enum m_type;
};
