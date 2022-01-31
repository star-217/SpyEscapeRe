#include "SpyState.h"

/**
  * @fn
  * 初期化
  */
void SpyState::Initialize()
{
	_default_state = std::make_unique<SpyDefaultState>();
	_win_state = std::make_unique<SpyWinState>();
	_lose_state = std::make_unique<SpyLoseState>();

	_default_state->Initialize(_T("spy.png"));
	_win_state->Initialize(_T("playerwin.png"));
	_default_state->Initialize(_T("playerdown.png"));

	_state = _default_state.get();
}

/**
  * @fn
  * 更新処理
  */
void SpyState::Update()
{
	_state->Update();
}

/**
  * @fn
  * 描画
  * @param (pos) Spyの座標
  * @param (dir) Spyの向いてる方向
  * @param (alpha) 透明化スキルを使ったときのアルファ値
  */
void SpyState::Draw(Vector3 pos, int dir, float alpha)
{
	_state->Draw(pos,dir, alpha);
}

/**
  * @fn
  * 描画
  * @param (state) Spyの状態
  */
SpyStateBase* SpyState::ChangeState(State state)
{
	switch (state)
	{
	case SpyState::State::Default:
		_state = _default_state.get();
		break;
	case SpyState::State::Win:
		_state = _win_state.get();
		break;
	case SpyState::State::Lose:
		_state = _lose_state.get();
		break;
	default:
		break;
	}

	return _state;
}
