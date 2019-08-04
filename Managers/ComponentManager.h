#pragma once
#include "../DrawComponent.h"
#include "../TransformComponent.h"
#include "../MotionComponent.h"
#include "../InputComponent.h"
#include <unordered_map>
#include <list>
#include <deque>

//base class so component managers can be stored in a container
class BaseComponentManager {
public:
	BaseComponentManager() = default;
	virtual ~BaseComponentManager() = default;
	BaseComponentManager(const BaseComponentManager&) = default;
	BaseComponentManager& operator=(const BaseComponentManager&) = default;
	BaseComponentManager(BaseComponentManager&&) = default;
	BaseComponentManager& operator=(BaseComponentManager&&) = default;
};

template <typename ComponentType>
class ComponentManager : public BaseComponentManager {
public:
	using LookupType = ComponentType;

	ComponentManager() {}
	~ComponentManager() {

	}

	void addComponent(std::shared_ptr<ComponentType> component) {
		m_componentsList.push_back(component);
	}

	std::list<std::shared_ptr<ComponentType>>& getComponentsList() { return m_componentsList; }
private:
	std::list<std::shared_ptr<ComponentType>> m_componentsList;
};

/*
Using list of pointers for faster insertion/deletion. 
Allows me to have other pointers to the components in a map.
Slower iteration.

Vector of objects will have fastest iteration, slow insertion/deletion.

Considering using a deque
*/