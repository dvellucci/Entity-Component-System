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

	std::vector<std::shared_ptr<Tile>>& getTiles() { return m_tiles; }
private:
	std::vector<std::shared_ptr<Tile>> m_tiles;
	LAYER_TYPE m_layerType;
};