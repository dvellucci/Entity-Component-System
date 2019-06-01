#pragma once
#include "../DrawComponent.h"
#include "../TransformComponent.h"
#include "../MotionComponent.h"
#include <unordered_map>

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

	ComponentType* addComponent(Entity* e, ComponentType* component) {
		m_components.push_back(*component);
		return component;
	}

	template <typename ComponentType>
	ComponentType getComponentType(ComponentType component) {
		
	}

	std::vector<ComponentType>& getComponents() { return m_components; }
private:
	std::vector<ComponentType> m_components;
};
