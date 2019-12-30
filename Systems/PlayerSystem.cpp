#include "PlayerSystem.h"
#include <cassert>

PlayerSystem::PlayerSystem(World* world, std::shared_ptr<Level> level) : System(world), m_level(level)
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

	TransformComponent* transform;

	for (auto& input : inputComponents)
	{
		Entity* entity = input->getOwner();

		//get the players components to use for each iteration
		transform = entity->getComponent<TransformComponent>();
		MotionComponent* motion = entity->getComponent<MotionComponent>();
		CollisionComponent* collisionBox = entity->getComponent<CollisionComponent>();

		if (motion->getOwner()->getIsActive())
		{
			if (sf::Keyboard::isKeyPressed(input->getRightKey())) direction = 1.0f;
			if (sf::Keyboard::isKeyPressed(input->getLeftKey())) direction = -1.0f;

			transform->setXMovement(motion->getVelocity() * time.asMilliseconds() * direction);

			if (sf::Keyboard::isKeyPressed(input->getUpKey())) airDirection = -1.0f;
			if (sf::Keyboard::isKeyPressed(input->getDownKey())) airDirection = 1.0f;

			transform->setYMovement(motion->getJumpVelocity() * time.asMilliseconds() * airDirection);

			int left_tile = collisionBox->getRectBox().left / m_level->getTileWidth();
			int right_tile = (collisionBox->getRectBox().left + collisionBox->getRectBox().width) / m_level->getTileWidth();
			int top_tile = collisionBox->getRectBox().top / m_level->getTileHeight();
			int bottom_tile = (collisionBox->getRectBox().top + collisionBox->getRectBox().height) / m_level->getTileHeight();

			if (left_tile < 0) left_tile = 0;
			if (right_tile > m_level->getTileWidth()) right_tile = m_level->getTileWidth();
			if (top_tile < 0) top_tile = 0;
			if (bottom_tile > m_level->getTileHeight()) bottom_tile = m_level->getTileHeight();

			for (int i = left_tile; i <= right_tile; i++)
			{
				for (int j = top_tile; j <= bottom_tile; j++)
				{
					int x = i * m_level->getTileWidth();
					int y = j * m_level->getTileHeight();

					std::shared_ptr<Tile> tile = m_level->getTileMap()[sf::Vector2f((int)x, (int)y)];

					if (tile)
					{
						if (tile->getType() != TileType::Background)
						{
							//collision
							if (collisionBox->getRectBox().intersects(tile->getSprite().getGlobalBounds()))
							{
								std::cout << "asda" << std::endl;
							}
						}
					}
				}
			}
	

		}
	}
}

void PlayerSystem::draw(sf::RenderWindow& window)
{
}
