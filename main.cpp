#include <SFML/Graphics.hpp>
#include "World.h"

constexpr auto SCREEN_WIDTH = 800;
constexpr auto SCREEN_HEIGHT = 600;

int main() {

	sf::Clock clock;
	float deltaTime;

	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML works!");

	World world;
	auto entity = world.createEntity();
	world.attachComponent(entity, TransformComponent(ComponentEnum::Enum::TRANSFORM, 5, 5));

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		
		window.display(); 

		//delete entities after main loop

	}

	return 0;
}