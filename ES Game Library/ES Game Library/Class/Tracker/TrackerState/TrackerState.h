#pragma once

#include "TrackerAttackState.h"
#include "TrackerDefaultState.h"
#include "TrackerWinState.h"
#include "TrackerLoseState.h"

class TrackerState {
public:
	TrackerState();
	~TrackerState() {};

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

	std::unique_ptr<TrackerDefaultState>	_default_state;
	std::unique_ptr<TrackerAttackState>	_attack_state;
	std::unique_ptr<TrackerWinState>		_win_state;
	std::unique_ptr<TrackerLoseState>		_lose_state;


};