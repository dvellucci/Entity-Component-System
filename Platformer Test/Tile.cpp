#include "Tile.h"-

Tile::Tile(sf::Texture& tex, sf::Rect<int>& rect, TileType type, float x, float y) :
	m_texture(tex), m_rect(rect), m_tileType(type), m_xPos(x), m_yPos(y) {

	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(m_rect);
	m_sprite.setPosition(m_xPos * WIDTH, m_yPos * HEIGHT);
}

Tile::~Tile() {

}
