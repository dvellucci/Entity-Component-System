#pragma once
#include <SFML/Graphics.hpp>

#define WIDTH 16.0f
#define HEIGHT 16.0f

enum TileType {
	Background,
	Wall,
	Hazard,
	Default
};

class Tile
{
public:
	Tile(sf::Texture& tex, sf::Rect<int>& rect, TileType type, float x, float y);
	~Tile();

	float getXPos() { return m_xPos; }
	float getYPos() { return m_yPos; }
	sf::Sprite& getSprite() { return m_sprite; }
	sf::Rect<float>& getRect() { return m_rect; }
	inline TileType getType() { return m_tileType; }

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Rect<float> m_rect;

	float m_xPos, m_yPos;

	TileType m_tileType;
};