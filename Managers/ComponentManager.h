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

	std::unordered_map<std::type_index, std::vector<Component*>> m_componentArrays;
};

class AComponentManager
{

public:
	AComponentManager() {}
	~AComponentManager() {}

	using LookupType = Component;

	template <typename ComponentType>
	void addComponent(std::shared_ptr<ComponentType> component)
	{

	}

	template <typename ComponentType, typename = std::enable_if<std::is_base_of<Component, ComponentType>::value>>
	void RegisterComponent()
	{
		const char* typeName = typeid(ComponentType).name();

		assert(m_componentArrays.find(typeName) == m_componentArrays.end() && "Registering component type more than once.");

		m_componentArrays.insert({ typeName, std::vector<Component*>() });
	}

	std::unordered_map<const char*, std::vector<Component*>> m_componentArrays;
private:

};
