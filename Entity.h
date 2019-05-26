#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include "Component.h"

class Entity {
public:
	Entity(int id) : m_id(id), m_isActive(true) { }
	~Entity() {}

	void setActive(bool isActive) { m_isActive = isActive; }

	int getId() { return m_id; }
	bool getIsActive() { return m_isActive; }

private:
	int m_id;
	bool m_isActive;
};

