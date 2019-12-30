#pragma once
#include "Components/Component.h"
#include <vector>
#include <memory>
#include <cassert>
#include <unordered_map>
#include <algorithm>
#include <type_traits>
#include <typeinfo>
#include <typeindex>

class Component;

class Entity {
public:
	Entity() = default;
	Entity(int id) : m_id(id), m_isActive(true) { }
	~Entity() {}

	int getId() { return m_id; }
	inline bool getIsActive() { return m_isActive; }

	std::unordered_map<const char*, std::shared_ptr<Component>> getComponents() { return m_componentMap; }

	//get the specific component type of an entity
	template <typename ComponentType, typename = std::enable_if<std::is_base_of<Component, ComponentType>::value>>
	inline ComponentType* getComponent()
	{
		const char* typeName = typeid(ComponentType).name();
		return static_cast<ComponentType*>(m_componentMap[typeName].get());
	}

	std::unordered_map<const char*, std::shared_ptr<Component>> m_componentMap;

private:
	int m_id;
	bool m_isActive;
};
