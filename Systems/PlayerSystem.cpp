#include "PlayerSystem.h"
#include <cassert>

PlayerSystem::PlayerSystem(World* world, sf::Event& event) : System(world), m_event(event)
{
}

PlayerSystem::~PlayerSystem()
{
}

void PlayerSystem::update(sf::Time time)
{
	float direction = 0.0f;
	sf::Vector2f newPosition;
	float airDirection = 0.0f;

	auto& inputComponents = m_world->getComponentManager<InputComponent>()->getComponentsList();

	for (auto& input : inputComponents)
	{
		auto entity = input->getOwner();
		auto transform = entity->getComponent<TransformComponent>();
		auto motion = entity->getComponent<MotionComponent>();
		//auto collision = entity->getComponent<Collision>();

		if (sf::Keyboard::isKeyPressed(input->getRightKey()))
			direction = 1.0f;

		if (sf::Keyboard::isKeyPressed(input->getLeftKey()))
			direction = -1.0f;

		if (sf::Keyboard::isKeyPressed(input->getUpKey()))
			airDirection = -1.0f;

		if (sf::Keyboard::isKeyPressed(input->getDownKey()))
			airDirection = 1.0f;


		if (motion->getOwner()->getIsActive())
		{
			newPosition = sf::Vector2f(motion->getVelocity() * time.asMilliseconds() * direction,
				motion->getJumpVelocity() * time.asMilliseconds() * airDirection);
			motion->setNewPosition(newPosition);
		}
	}
}

void PlayerSystem::draw(sf::RenderWindow& window)
{
}
