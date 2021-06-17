#pragma once

#include "../../ESGLib.h"

class GameState
{
public:
	GameState() : game_state(0) {}
	~GameState(){}

	static GameState GetInstance()
	{
		GameState instance;
		return instance;
	}

	int SetGameState(int state)
	{
		game_state = state;
	}
	int GetGameState() {return game_state ; }
private:
	int game_state;
};