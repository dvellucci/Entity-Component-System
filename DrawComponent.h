#pragma once
#include "Component.h"

class DrawComponent : public Component {
public:
	DrawComponent(uint id, const char* filename) : Component(id) {
		if (!m_texture.loadFromFile(filename)) {
			printf("Failed to load texture %s", filename);
			exit(1);
		}
		m_sprite.setTexture(m_texture);
	}

	~DrawComponent() {

	}

	sf::Sprite& getSprite() { return m_sprite; }

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
};