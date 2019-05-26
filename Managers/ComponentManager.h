#pragma once
#include "../DrawComponent.h"
#include "../TransformComponent.h"

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
	~ComponentManager() {}

	Component* addComponent(Entity* e, ComponentType* component) {
		m_components.push_back(component);
		return component;
	}


	std::vector<ComponentType*>& getComponents() { return m_components; }
private:
	std::vector<ComponentType*> m_components;
};
