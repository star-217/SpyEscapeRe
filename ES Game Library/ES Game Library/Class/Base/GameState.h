#pragma once

#include "../../ESGLib.h"

class GameState
{
public:
	GameState() : _game_state(0) {}
	~GameState(){}

	static GameState GetInstance()
	{
		GameState instance;
		return instance;
	}

	int SetGameState(int state)
	{
		_game_state = state;
	}
	int GetGameState() {return _game_state ; }
private:
	int _game_state;
};