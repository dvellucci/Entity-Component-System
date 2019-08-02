#include "Game.h"

int Game::m_levelIndex = 0;

Game::Game() : m_window(nullptr)
{
	//initialize the window
	m_window = new sf::RenderWindow();
	m_window->create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Test Platformer", sf::Style::Titlebar | sf::Style::Close);
	m_window->setFramerateLimit(60);

	//initialize game systems
	m_renderSystem = new RenderSystem(&m_world);
	m_motionSystem = new MovementSystem(&m_world);
	m_playerSystem = new PlayerSystem(&m_world, m_window);

	m_level = std::make_shared<Level>(m_levels[m_levelIndex]);
	m_levelLoader = std::make_shared<LevelLoader>();
}

Game::~Game()
{
	delete m_window;
	delete m_renderSystem;
	delete m_motionSystem;
	delete m_playerSystem;
}

void Game::start()
{
	//set the camera
	m_view.reset(sf::FloatRect(0.f, 0.f, 415.f, 315.f));

	//load the level
	if (!m_levelLoader->loadLevel(m_level))
		assert("Level did not load properly");

	//create the player
	Entity* player = m_world.createEntity();
	m_world.attachComponent(player, TransformComponent(player, 50, 200, "Platformer Test/Assets/mario.png"));
	m_world.attachComponent(player, MotionComponent(player, 0.15f, 0.1f, 0.0f));
	m_world.attachComponent(player, InputComponent(player));

	//run the main game loop
	gameLoop();
}

void Game::gameLoop()
{
	//loop to handle events
	sf::Clock clock;
	while (m_window->isOpen()) {

		sf::Time time = clock.getElapsedTime();

		sf::Event event;
		while (m_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window->close();

		}

		//process player input/information
		m_playerSystem->update(time);

		m_motionSystem->update(time);
		clock.restart().asMilliseconds();

		m_window->setView(m_view);

		//render the scene
		m_window->clear(sf::Color(4, 156, 216, 255));

		for (auto tile : m_level->getBackgroundLayer().getTiles())
			m_window->draw(tile->getSprite());

		for (auto tile : m_level->getWallLayer().getTiles())
			m_window->draw(tile->getSprite());

		for (auto tile : m_level->getHazardsLayer().getTiles())
			m_window->draw(tile->getSprite());

		m_renderSystem->draw(*m_window);
		m_window->display();
	}
}

void Game::changeState()
{
}


