#pragma once
#include "TileLayer.h"
#include <unordered_map>
#include <SFML/Graphics.hpp>


class Level {
public:
	Level() {};
	Level(std::string level) : m_levelName(level) {};
	~Level() {};

	//void DestroyPreviousLevel();

	void setMapWidth(int width) { m_width = width; }
	void setMapHeight(int height) { m_height = height; }
	void setTileWidth(int width) { m_tileWidth = width; }
	void setTileHeight(int height) { m_tileHeight = height; }

	void drawLevel(sf::RenderWindow*& window)
	{
		for (auto tile : m_backgroundLayer.getTiles())
			window->draw(tile->getSprite());

		for (auto tile : m_wallLayer.getTiles())
			window->draw(tile->getSprite());

		for (auto tile : m_hazardLayer.getTiles())
			window->draw(tile->getSprite());
	}

	int getMapWidth() { return m_width; }
	int getMapHeight() { return m_height; }
	int getTileWidth() { return m_tileWidth; }
	int getTileHeight() { return m_tileHeight; }

	std::string getLevelName()  { return m_levelName; }

	TileLayer& getBackgroundLayer() { return m_backgroundLayer; }
	TileLayer& getWallLayer() { return m_wallLayer; }
	TileLayer& getHazardsLayer() { return m_hazardLayer; }

	struct VectorComparator
	{
		float operator() (const sf::Vector2f vector) const
		{
			return vector.x + vector.y;
		}
	};

	std::unordered_map<sf::Vector2f, std::shared_ptr<Tile>, VectorComparator>& getTileMap() { return m_tileMap; }

private:
	std::string m_levelName;

	//map properties
	int m_width = 0;
	int m_height = 0;
	int m_mapSize = 0;

	//tile properties
	int m_tileWidth = 0;
	int m_tileHeight = 0;
	int m_tileSize = 0;

	//hold 3 tile layer objects
	TileLayer m_backgroundLayer;
	TileLayer m_wallLayer;
	TileLayer m_hazardLayer;


	std::unordered_map<sf::Vector2f, std::shared_ptr<Tile>, VectorComparator> m_tileMap;
};