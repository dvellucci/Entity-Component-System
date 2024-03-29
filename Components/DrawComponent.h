#pragma once
#include "Component.h"

class DrawComponent : public Component {
public:
	DrawComponent(Entity* owner, const char* filename) : Component(owner) {
		if (!m_texture.loadFromFile(filename)) {
			printf("Failed to load texture %s", filename);
			exit(1);
		}
		m_sprite.setTexture(m_texture);
	}

	~DrawComponent() {

	}

	inline void setPosition(float x, float y) { m_sprite.setPosition(sf::Vector2f(x, y)); }
	sf::Sprite& getSprite() { return m_sprite; }

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
};