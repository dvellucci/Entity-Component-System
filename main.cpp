#include "World.h"
#include "Systems/RenderSystem.h"
#include "Systems/MovementSystem.h"
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>   

constexpr auto SCREEN_WIDTH = 1920;
constexpr auto SCREEN_HEIGHT = 1080;

int main() {
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML works!");
	window.setFramerateLimit(60);

	World world;

	auto entity = world.createEntity();
	world.attachComponent(entity, TransformComponent(entity->getId(), 500, 400, "Textures/mario_idle.png"));
	world.attachComponent(entity, MotionComponent(entity->getId(), 0.5f, 0));

	auto entity2 = world.createEntity();
	world.attachComponent(entity2, TransformComponent(entity2->getId(), 100, 400, "Textures/mario_idle.png"));

	System* system = new RenderSystem(&world);
	System* motion = new MovementSystem(&world);

	sf::Clock clock;
	while (window.isOpen())
	{
		//poll keyboard events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//update the game
		sf::Time time = clock.getElapsedTime();

		motion->update(time);

		clock.restart().asMilliseconds();

		//render the scene
		window.clear();
		system->draw(window);
		window.display(); 

		//delete at the end of the main loop
		world.destroyEntity(entity);
	}

	return 0;
}