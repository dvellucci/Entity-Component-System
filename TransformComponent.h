#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>

class TransformComponent : public Component {
public:
	TransformComponent(Entity* owner, float x, float y, const char* filename) : Component(owner), m_x(x), m_y(y) {
		if (!m_texture.loadFromFile(filename)) {
			printf("Failed to load texture %s", filename);
			exit(1);
		}
		m_sprite.setTexture(m_texture);
		m_sprite.setPosition(sf::Vector2f(m_x, m_y));
		m_sprite.setOrigin(m_texture.getSize().x / (float)2, m_texture.getSize().y / (float)2);
	}

	~TransformComponent() {}

	inline void setNewPosition(sf::Vector2f newPosition) {
		m_newPosition = newPosition;
	}
	inline sf::Vector2f& getNewPosition() { return m_newPosition; }

	sf::Sprite& getSprite() { return m_sprite; }
	inline float getXpos() { return m_x; }
	inline float getYpos() { return m_y; }

private:
	float m_x;
	float m_y;

	sf::Vector2f m_newPosition;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
};