#include "TrackerState.h"

/**
  * @fn
  * 初期化
  */
void TrackerState::Initialize()
{
	_default_state =std::make_unique<DefaultState>();
	_attack_state = std::make_unique<AttackState>();
	_win_state = std::make_unique<WinState>();
	_lose_state = std::make_unique<LoseState>();

	_default_state->Initialize(_T("oni2.png"));
	_attack_state->Initialize(_T("punch.png"));
	_win_state->Initialize(_T("oniwin.png"));
	_lose_state->Initialize(_T("onilose.png"));

	_state = _default_state.get();
}

/**
  * @fn
  * 更新処理
  */
void TrackerState::Update()
{
	_state->Update();

	if (_state->AnimetionFinish())
		ChangeState(TrackerState::State::Default);
}

/**
  * @fn
  * 描画
  * @param (pos) 鬼のポジション
  * @param (dir) 向いてる方向
  */
void TrackerState::Draw(Vector3& pos, int dir)
{
	_state->Draw(pos,dir);
}

/**
  * @fn
  * ステートの切り替え
  * @param (state) 鬼のステート
  */
TrackerStateBase* TrackerState::ChangeState(State state)
{
	switch (state)
	{
	case TrackerState::State::Default:
		_state = _default_state.get();
		break;
	case TrackerState::State::Win:
		_state = _win_state.get();
		break;
	case TrackerState::State::Lose:
		_state = _lose_state.get();
		break;
	case TrackerState::State::Attack:
		_state = _attack_state.get();
		break;
	default:
		break;
	}

	return _state;
}
