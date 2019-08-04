#pragma once
#include "PlayerState.h"

class JumpingState : public PlayerState
{
public:
	JumpingState();
	~JumpingState();

	virtual PlayerState* handleInput(sf::Keyboard::Key key);
	virtual void Enter(TransformComponent& playerTransform);

private:

};