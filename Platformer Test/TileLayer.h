#pragma once
#include "Tile.h"
#include <vector>
#include <memory>

enum LAYER_TYPE {
	Background_Layer,
	Wall_Layer,
	Hazard_Layer,
	Default_Layer
};

class TileLayer
{
public:
	TileLayer() : m_layerType(Default_Layer) {
		m_tiles = {};
	}
	~TileLayer() {
	}


	std::shared_ptr<Tile> insertTile(sf::Texture texture,  sf::IntRect rect, TileType type, float x, float y) {
		std::shared_ptr<Tile> tile = std::make_shared<Tile>(texture, rect, type, x, y);
		m_tiles.push_back(tile);
		return tile;
	}

	std::vector<std::shared_ptr<Tile>>& getTiles() { return m_tiles; }
private:
	std::vector<std::shared_ptr<Tile>> m_tiles;
	LAYER_TYPE m_layerType;
};