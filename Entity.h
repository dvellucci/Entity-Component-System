#pragma once
#include "Component.h"
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
	virtual ~Entity() {}

	Component* addComponent(Component* component) 
	{
		m_components.push_back(component);
		return component;
	}

	template <typename ComponentType, typename = std::enable_if<std::is_base_of<Component, ComponentType>::value>>
	void addComponent(ComponentType type, Component* component)
	{
		//auto newComponent = reinterpret_cast<ComponentType*>(component);
		m_componentMap.emplace(typeid(ComponentType), reinterpret_cast<Component*>(component));
		//m_componentMap.insert(std::make_pair(typeid(ComponentType), component));
	}

	void setActive(bool isActive) 
	{ 
		m_isActive = isActive; 
		for (auto& component : m_components) 
		{
			component->setActive(isActive);
		}
	}

	int getId() { return m_id; }
	bool getIsActive() { return m_isActive; }
	std::vector<Component*>& getComponents() { return m_components; }

	//std::unordered_map<std::type_index, Component*>& getComponentMap() { return m_componentMap; }
	
	template <typename ComponentType, typename = std::enable_if<std::is_base_of<Component, ComponentType>::value>>
	inline ComponentType* getComponent()
	{
	/*	auto found = m_componentMap.find(typeid(ComponentType));
		if (found != m_componentMap.end())
			return found->second;
		else
			assert("Invalid component type for entity"); */

		return nullptr;
	}

	template <typename ComponentType, typename = std::enable_if<std::is_base_of<Component, ComponentType>::value>>
	Component* getComponent(ComponentType type)
	{
		//return m_tempMap[type];
		return m_componentMap[typeid(ComponentType)];
	}

	std::unordered_map<std::type_index, Component*> m_componentMap;

private:
	int m_id;
	bool m_isActive;

	std::vector<Component*> m_components;
};

