#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>

class TransformComponent : public Component {
public:
	TransformComponent(uint id, float x, float y, const char* filename) : Component(id), m_x(x), m_y(y) {
		if (!m_texture.loadFromFile(filename)) {
			printf("Failed to load texture %s", filename);
			exit(1);
		}
		m_sprite.setTexture(m_texture);
		m_sprite.setPosition(m_x, m_y);
		m_sprite.setOrigin(m_texture.getSize().x / 2, m_texture.getSize().y / 2);
	}

	~TransformComponent() {}

	sf::Sprite& getSprite() { return m_sprite; }
	float getXpos() { return m_x; }
	float getYpos() { return m_y; }

private:
	float m_x;
	float m_y;

	sf::Sprite m_sprite;
	sf::Texture m_texture;
};