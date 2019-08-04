#include "LevelLoader.h"
#include <cstring>

LevelLoader::LevelLoader() : m_firstTileID(0)
{

}

LevelLoader::~LevelLoader()
{
}

bool LevelLoader::loadLevel(std::shared_ptr<Level> level)
{
	m_tmxFile.LoadFile(level->getLevelName().c_str());

	XMLElement* mapNode = m_tmxFile.RootElement();
	level->setMapWidth(atoi(mapNode->Attribute("width")));
	level->setMapHeight(atoi(mapNode->Attribute("height")));
	level->setTileWidth(atoi(mapNode->Attribute("tilewidth")));
	level->setTileHeight(atoi(mapNode->Attribute("tileheight")));

	XMLElement* tileSet = mapNode->FirstChildElement("tileset");
	m_firstTileID = atoi(tileSet->Attribute("firstgid"));
	std::string imagePath = tileSet->Attribute("source");

	sf::Image img;
	if (!img.loadFromFile("Platformer Test/Assets/" + imagePath)) {
		std::cout << "Failed to load tile sheet." << std::endl;
		return false;
	}

	img.createMaskFromColor(sf::Color(255, 255, 255));
	m_tilesetImage.loadFromImage(img);
	m_tilesetImage.setSmooth(false);

	int columns = m_tilesetImage.getSize().x / level->getTileWidth();
	int rows = m_tilesetImage.getSize().y / level->getTileHeight();

	std::vector<sf::Rect<int>> subRects;

	//define the individual sprites of the tileset
	for (int y = 0; y < rows; y++) {
		for (int x = 0; x < columns; x++) {
			sf::Rect<int> rect;

			rect.top = y * level->getTileHeight();
			rect.height = level->getTileHeight();
			rect.left = x * level->getTileWidth();
			rect.width = level->getTileWidth ();;

			subRects.push_back(rect);
		}
	}

	XMLElement* layerElement;
	layerElement = mapNode->FirstChildElement("layer");
	while (layerElement) {
		XMLElement* layerData;
		layerData = layerElement->FirstChildElement("data");
		if (!layerData) {
			std::cout << "Bad map. No layer information found." << std::endl;
			return false;
		}

		std::string layerName = layerElement->Attribute("name");

		XMLElement* tileElement = layerData->FirstChildElement("tile");
		float x = 0;
		float y = 0;

		while (tileElement) {
			auto tileAttribute = tileElement->Attribute("gid");
			if (tileAttribute) {
				int tileGID = atoi(tileElement->Attribute("gid"));
				int rectToUse = tileGID - m_firstTileID;

				if (rectToUse >= 0) {
					if (layerName == "Background") {
						level->getBackgroundLayer().getTiles().push_back(std::make_shared<Tile>(m_tilesetImage, subRects[rectToUse], TileType::Background, x, y));
					}
					else if (layerName == "Walls") {
						level->getWallLayer().getTiles().push_back(std::make_shared<Tile>(m_tilesetImage, subRects[rectToUse], TileType::Wall, x, y));
					}
					else if (layerName == "Hazard") {
						level->getHazardsLayer().getTiles().push_back(std::make_shared<Tile>(m_tilesetImage, subRects[rectToUse], TileType::Hazard, x, y));
					}
				}
			}

			x++;
			if (x >= level->getMapWidth())
			{
				x = 0;
				y++;
				if (y >= level->getMapHeight())
					y = 0;
			}

			tileElement = tileElement->NextSiblingElement("tile");
		}

		layerElement = layerElement->NextSiblingElement();
	}


	return true;
}
