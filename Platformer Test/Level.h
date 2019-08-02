#pragma once
#include "TileLayer.h"

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

	int getMapWidth() { return m_width; }
	int getMapHeight() { return m_height; }
	int getTileWidth() { return m_tileWidth; }
	int getTileHeight() { return m_tileHeight; }

	std::string getLevelName()  { return m_levelName; }

	TileLayer& getBackgroundLayer() { return m_backgroundLayer; }
	TileLayer& getWallLayer() { return m_wallLayer; }
	TileLayer& getHazardsLayer() { return m_hazardLayer; }

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
};