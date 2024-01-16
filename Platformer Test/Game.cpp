#include "Game.h"

int Game::m_levelIndex = 0;

Game::Game() : m_window(nullptr)
{
	//initialize the window
	m_window = new sf::RenderWindow();
	m_window->create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Test Platformer", sf::Style::Titlebar | sf::Style::Close);
	m_window->setFramerateLimit(60);

	m_level = std::make_shared<Level>(m_levels[m_levelIndex]);
	m_levelLoader = std::make_shared<LevelLoader>();

	//initialize game systems
	m_renderSystem = new RenderSystem(&m_world);
	m_motionSystem = new MovementSystem(&m_world);
	m_playerSystem = new PlayerSystem(&m_world, m_level);
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
	m_view.reset(sf::FloatRect(0.f, 0.f, 418.f, 320.f));

	//load the level
	if (!m_levelLoader->loadLevel(m_level))
		assert("Level did not load properly");

	EntityHandle handle = m_world.CreateEntity();

	//create the player
	//Entity* player = m_world.createEntity();
	//m_world.attachComponent(player, make_shared<TransformComponent>(player, 50.0f, 200.0f, "Platformer Test/Assets/mario.png"));
	//m_world.attachComponent(player, make_shared<MotionComponent>(player, 0.15f, 0.1f, 0.0f));
	//m_world.attachComponent(player, make_shared<InputComponent>(player));
	//m_world.attachComponent(player, make_shared<CollisionComponent>(player, sf::Rect<int>{0, 0, 16, 32}));

	//m_world.attachComponent2<TransformComponent>(player, new TransformComponent(player, 50.0f, 200.0f, "Platformer Test/Assets/mario.png"));
	//m_world.attachComponent2<MotionComponent>(player, new MotionComponent(player, 0.15f, 0.1f, 0.0f));
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

		//move objects that need to be moved
		m_motionSystem->update(time);
		clock.restart().asMilliseconds();

		m_window->setView(m_view);

		//render the scene
		m_window->clear(sf::Color(4, 156, 216, 255));

		//draw the tile map
		m_level->drawLevel(m_window);

		//draw objects that need to be drawn
		m_renderSystem->draw(*m_window);
		m_window->display();
	}
}

void Game::changeState()
{
}


