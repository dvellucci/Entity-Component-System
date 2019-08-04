#pragma once
#include <SFML/Graphics.hpp>
#include "../TransformComponent.h"

class PlayerState
{
public:
	PlayerState() { }
	virtual ~PlayerState() { }

	//handle the player's input 
	virtual PlayerState* handleInput(sf::Keyboard::Key key) = 0;
	//sets the player's sprite when entering a new state
	virtual void Enter(TransformComponent& playerTransform) = 0;

private:
	//static StandingState standing;
	//static JumpingState jumping;
	//static FallingState falling;
};