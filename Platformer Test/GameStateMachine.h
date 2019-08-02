#pragma once
#include "GameState.h"
#include <vector>
#include <memory>

class GameStateMachine
{
public:


private:
	std::vector<std::unique_ptr<GameState>> m_gameStates;
};