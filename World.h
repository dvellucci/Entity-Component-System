#pragma once
#include "Managers/EntityManager.h"
#include "Managers/ComponentManager.h"
#include <memory>
#include <cassert>

class EntityHandle;
class EntityManager;

//Goal is to have a component manager for each component type. Each component manager stores their components in an array,
//and each manager will main an entity map mapping an entity id to an integer representing the component's index in the manager's component array.

//TODO:
/* 
* Add a compoent mask for systems
* Finish the ComponentManager::AddComponent function to set the entitymap
* implement the ComponentManager::RemoveComponent function
* implement function to delete entities
*/

//DONE:
//Refactor GetComponentManager to work with the new vector -> Can be further refactored to work with an index to prevent looping through the vector every time
//Refactor EntityManager::createEntity() to use an EntityHandle and to return an EntityHandle. This EntityHandle is used to add a component to an entity.

using namespace std;

class World {
public:
	World();
	~World();

	EntityHandle& CreateEntity();
	void DestroyEntity(Entity* e);

	template <typename ComponentType>
	void AddComponent(const Entity& entity, std::shared_ptr<ComponentType> component);

	//loop through component managers to return the one of type ComponentType or create and return the newly created one
	//TODO:Check if it can be made faster. Doing this when components are added is a performance hit
	template <typename ComponentType>
	inline ComponentManager<ComponentType>* GetComponentManager()
	{
		static_assert(std::is_base_of<BaseComponentManager, ComponentType>::value, "T must be a subtype of BaseComponentManager");

		for (const auto& manager : _componentManagers)
		{
			if (auto componentMgr = static_cast<ComponentManager<ComponentType>*>(manager.get()))
			{
				return componentMgr;
			}
		}

		//if a manager for the new component was not created, create it 
		_componentManagers.push_back(std::make_unique<ComponentManager<ComponentType>>());
		return static_cast<ComponentManager<ComponentType>*>(_componentManagers.back().get());
	}

private:
	std::unique_ptr<EntityManager> m_entityManager;
	std::unordered_map<std::type_index, BaseComponentManager*> m_componentManagers;

	//Container to hold all our component manager types. Use unique_ptr since no other class will have ownership
	std::vector<std::unique_ptr<BaseComponentManager>> _componentManagers;
};

