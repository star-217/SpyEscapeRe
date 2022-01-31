#pragma once

#include "SpyWinState.h"
#include "SpyDefaultState.h"
#include "SpyLoseState.h"

class SpyState {
public:
	enum class State
	{
		Default,
		Win,
		Lose
	};

	void Initialize();
	void Update();
	void Draw(Vector3 pos, int dir, float alpha);

	SpyStateBase* ChangeState(State state);

private:

	SpyStateBase* _state;

	std::unique_ptr<SpyDefaultState> _default_state;
	std::unique_ptr<SpyWinState> _win_state;
	std::unique_ptr<SpyLoseState> _lose_state;
};