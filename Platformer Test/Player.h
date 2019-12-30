#pragma once
#include <SFML/Graphics.hpp>
#include "../Entity.h"

/*
PlayerState class with static reference to each state 
State class for each player state that inherits from PlayerState
PlayerState has a handleInput method that takes input and a reference to player
PlayerController has handleInput that takes input, calls playerState's handleInput with the pointer it has and passes in input and *this
Player or PlayerController holds a playerState* pointer

*/
class Player : public Entity
{
public:
	Player();
	~Player();

private:
	sf::Sprite m_sprite;

	//PlayerState* m_state

	//enum Player_Sprite { small_idle = 0, small_walk = 1, small_jump = 2, etc...}
	//std::vector<sf::Rect<int>> = { ..... }

};