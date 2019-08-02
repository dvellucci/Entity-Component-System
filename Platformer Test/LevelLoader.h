#pragma once
#include "tinyxml2.h"
#include "Level.h"
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace tinyxml2;

class LevelLoader
{
public:
	LevelLoader();
	~LevelLoader();

	bool loadLevel(std::shared_ptr<Level> level);

private:
	XMLDocument m_tmxFile;

	
	int m_firstTileID;

	sf::Texture m_tilesetImage;

};