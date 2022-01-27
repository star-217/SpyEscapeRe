#include "TrackerState.h"

/**
  * @fn
  * 初期化
  */
void TrackerState::Initialize()
{
	_default_state = new DefaultState();
	_attack_state = new AttackState();
	_win_state = new WinState();
	_lose_state = new LoseState();

	_default_state->Initialize(_T("oni2.png"));
	_attack_state->Initialize(_T("punch.png"));
	_win_state->Initialize(_T("oniwin.png"));
	_lose_state->Initialize(_T("onilose.png"));
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
TrackerStateBase* TrackerState::ChangeState(TrackerState::State state)
{
	switch (state)
	{
	case TrackerState::State::Default:
		_state = _default_state;
		break;
	case TrackerState::State::Win:
		_state = _win_state;
		break;
	case TrackerState::State::Lose:
		_state = _lose_state;
		break;
	case TrackerState::State::Attack:
		_state = _attack_state;
		break;
	default:
		break;
	}

	return _state;
}
