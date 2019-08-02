#include "PlayerSystem.h"
#include <cassert>

PlayerSystem::PlayerSystem(World* world, sf::RenderWindow* window) : System(world), m_window(window)
{
}

PlayerSystem::~PlayerSystem()
{
}

void PlayerSystem::update(sf::Time time)
{
	auto& inputComponents = m_world->getComponentManager<InputComponent>()->getComponents();
	auto& motionComponents = m_world->getComponentManager<MotionComponent>()->getComponents();
	
	/*sf::Event event;
	while (m_window->pollEvent(event))
	{
		for (auto& input : inputComponents)
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(input.getJumpKey()))
					std::cout << "jump";
				break;

			}
		}
	} */

	sf::Vector2f newPos;
	float direction = 0.0f;
	float airDirection = 0.0f;
	float gravity = 1.0f;

	for (auto& input : inputComponents)
	{
		//get the transform component of this entity
		auto entity = input.getOwner();
		auto transform = (TransformComponent*)entity->m_componentMap[typeid(TransformComponent)];
	
		//TransformComponent* transformComponent = reinterpret_cast<TransformComponent*>(entity->getComponent<TransformComponent>());
		//MotionComponent* component = reinterpret_cast<MotionComponent*>(entity->getComponent<MotionComponent>());

		if (sf::Keyboard::isKeyPressed(input.getRightKey()))
		{
			direction = 1.0f;
		} 
		else if (sf::Keyboard::isKeyPressed(input.getLeftKey()))
		{
			direction = -1.0f;
		}

	}
	  
	for (auto& motion : motionComponents)
	{
		if (motion.getOwner()->getIsActive())
		{
			sf::Vector2f newPos = sf::Vector2f(motion.getVelocity() * time.asMilliseconds() * direction, 
												motion.getJumpVelocity() * time.asMilliseconds() * airDirection);
			motion.setNewPosition(sf::Vector2f(newPos.x, newPos.y));
		}
	} 
}

void PlayerSystem::draw(sf::RenderWindow& window)
{
}
