#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"

class TransformComponent : public Component {
public:
	TransformComponent(Entity* owner, float x, float y, const char* filename) : Component(owner) {
		if (!m_texture.loadFromFile(filename)) {
			printf("Failed to load texture %s", filename);
			exit(1);
		}
		m_sprite.setTexture(m_texture);
		m_sprite.setPosition(x, y);
		//m_sprite.setOrigin(m_texture.getSize().x / (float)2, m_texture.getSize().y / (float)2);

		//will need to use textureRect when moving to sprite sheet
		m_width = m_texture.getSize().x;
		m_height = m_texture.getSize().y;
	}

	~TransformComponent() {}

	inline void setXMovement(float val)
	{
		m_position.x = val;
	}

	inline void setYMovement(float val)
	{
		m_position.y = val;
	}

	inline sf::Vector2f getPosition() const { return m_position; }
	inline sf::Sprite& getSprite() { return m_sprite; }
	inline int getXpos() { return (int)m_sprite.getPosition().x; }
	inline int getYpos() { return (int)m_sprite.getPosition().y; }
	inline int getWidth() { return m_width; }
	inline int getHeight() { return m_height; }

private:
	int m_width;
	int m_height;

	sf::Vector2f m_position;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
};