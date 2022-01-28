#pragma once

#include "AttackState.h"
#include "DefaultState.h"
#include "WinState.h"
#include "LoseState.h"

class TrackerState {
public:

	enum class State
	{
		Default,
		Win,
		Lose,
		Attack
	};

	void	Initialize();
	void	Update();
	void	Draw(Vector3& pos, int dir);

	TrackerStateBase* ChangeState(State state);
	bool GetAnimetionFinish() { return _state->AnimetionFinish(); }

private:

	TrackerStateBase* _state;

	DefaultState*	_default_state;
	AttackState*	_attack_state;
	WinState*		_win_state;
	LoseState*		_lose_state;


};