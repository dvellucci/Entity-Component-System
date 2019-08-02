#pragma once
#include <SFML/Graphics.hpp>

#define WIDTH 16
#define HEIGHT 16

enum TileType {
	Background,
	Wall,
	Hazard,
	Default
};

class Tile
{
public:
	Tile(sf::Texture& tex, sf::Rect<int>& rect, TileType type, int x, int y);
	~Tile();

	sf::Sprite& getSprite() { return m_sprite; }
	sf::Rect<int>& getRect() { return m_rect; }

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Rect<int> m_rect;

	int m_xPos, m_yPos;

	TileType m_tileType;
};