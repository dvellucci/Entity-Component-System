#pragma once
#include "../Components/DrawComponent.h"
#include "../Components/TransformComponent.h"
#include "../Components/MotionComponent.h"
#include "../Components/InputComponent.h"
#include "../Components/CollisionComponent.h"
#include <unordered_map>
#include <list>
#include <deque>

using ComponentIndex = unsigned int;

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

//Max number of entities and components per component array
const unsigned int MAX_NUMBER_OF_COMPONENTS = 1024;

template <typename ComponentType>
class ComponentManager : public BaseComponentManager {
public:
	using LookupType = ComponentType;

	ComponentManager() 
	{ 
		//Resize the vector to the max number of components to reserve the space
		_components.reserve(MAX_NUMBER_OF_COMPONENTS);
	}
	~ComponentManager() {}

	/*
	*   When we add a component, we add a component to the index that is equal to the entity id.
	*	Right now, the data in the components array won't be densly packed. It would be better if they were for more efficient performance,
	*	but I can refactor that at some point using a Component Mask and an std::map<Entity, ComponentIndex>
	*/
	void AddComponent(Entity* entity, std::unique_ptr<ComponentType>& component) {
		//entityMap.add(entityId, component)
		//when we add a component, we add a component to the index that is equal to the entity id
		_components[entity->GetId()] = component;
		//_entityComponentMap.emplace(entity->GetId(), )
	}

	void RemoveComponent(const int entityId)
	{
		_components.erase(entityId);
	}

	const std::vector<std::shared_ptr<ComponentType>>& getComponentsList() const { return _components; }

private:
	std::vector<std::unique_ptr<ComponentType>> _components;
	//Mapping of an entity (which is essentially and ID of type int) to an index of the component
	std::map<Entity*, ComponentIndex> _entityComponentMap;
	//entityMap<EntityId, Component>

	std::unordered_map<std::type_index, std::vector<Component*>> m_componentArrays;
};

