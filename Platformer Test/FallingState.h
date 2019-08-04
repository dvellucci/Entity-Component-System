#pragma once
#include "PlayerState.h"

class FallingState : public PlayerState
{
public:
	FallingState();
	~FallingState();

	virtual PlayerState* handleInput(sf::Keyboard::Key key);
	virtual void Enter(TransformComponent& playerTransform);

private:
};