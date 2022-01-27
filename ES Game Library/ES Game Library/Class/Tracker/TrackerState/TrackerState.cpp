#include "TrackerState.h"

/**
  * @fn
  * ������
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
  * �X�V����
  */
void TrackerState::Update()
{
	_state->Update();

	if (_state->AnimetionFinish())
		ChangeState(TrackerState::State::Default);
}

/**
  * @fn
  * �`��
  * @param (pos) �S�̃|�W�V����
  * @param (dir) �����Ă����
  */
void TrackerState::Draw(Vector3& pos, int dir)
{
	_state->Draw(pos,dir);
}

/**
  * @fn
  * �X�e�[�g�̐؂�ւ�
  * @param (state) �S�̃X�e�[�g
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
