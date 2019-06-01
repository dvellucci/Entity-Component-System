#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include "Component.h"


class Entity {
public:

	Entity(int id) : m_id(id), m_isActive(true) { }
	~Entity() {}

	Component* addComponent(Component* component) {
		m_components.push_back(component);
		return component;
	}

	void setActive(bool isActive) { 
		m_isActive = isActive; 
		for (auto& component : m_components) {
			component->setActive(isActive);
		}
	}

	int getId() { return m_id; }
	bool getIsActive() { return m_isActive; }
	std::vector<Component*>& getComponents() { return m_components; }

private:
	int m_id;
	bool m_isActive;

	std::vector<Component*> m_components;
};

