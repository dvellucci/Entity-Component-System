#pragma once
#include "../World.h"
#include "../Systems/RenderSystem.h"
#include "../Systems/MovementSystem.h"
#include "../Systems/PlayerSystem.h"
#include "LevelLoader.h"

constexpr auto SCREEN_WIDTH = 1600;
constexpr auto SCREEN_HEIGHT = 800;

class Game {
public:
	Game();
	~Game();

	void start();
	void gameLoop();
	void changeState();

private:
	World m_world;
	sf::Event m_event;

	//game systems
	System* m_renderSystem;
	System* m_motionSystem;
	System* m_playerSystem;

	std::shared_ptr<LevelLoader> m_levelLoader;
	std::shared_ptr<Level> m_level;

	sf::RenderWindow* m_window;
	sf::View m_view;

	std::vector<std::string> m_levels = { "Platformer Test/Assets/test_level.tmx" };
	static int m_levelIndex;
};