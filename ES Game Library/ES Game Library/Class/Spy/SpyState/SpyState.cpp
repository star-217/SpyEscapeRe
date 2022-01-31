#include "SpyState.h"

/**
  * @fn
  * ������
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
  * �X�V����
  */
void SpyState::Update()
{
	_state->Update();
}

/**
  * @fn
  * �`��
  * @param (pos) Spy�̍��W
  * @param (dir) Spy�̌����Ă����
  * @param (alpha) �������X�L�����g�����Ƃ��̃A���t�@�l
  */
void SpyState::Draw(Vector3 pos, int dir, float alpha)
{
	_state->Draw(pos,dir, alpha);
}

/**
  * @fn
  * �`��
  * @param (state) Spy�̏��
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
