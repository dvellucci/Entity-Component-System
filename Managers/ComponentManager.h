#pragma once
#include "../Components/DrawComponent.h"
#include "../Components/TransformComponent.h"
#include "../Components/MotionComponent.h"
#include "../Components/InputComponent.h"
#include "../Components/CollisionComponent.h"
#include <unordered_map>
#include <list>
#include <deque>

//base class so component managers so that ComponentManager can be instantiated as different types
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

	void addComponent(std::shared_ptr<ComponentType> component) {
		m_componentsList.push_back(component);
	}

	std::vector<std::shared_ptr<ComponentType>>& getComponentsList() { return m_componentsList; }
private:
	std::vector<std::shared_ptr<ComponentType>> m_componentsList;
};
