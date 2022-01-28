/**
 * @file  Tracker.h
 * @brief �S���̃N���X
 * @author ������
 * @date 2021/04/20
 */
#include "Tracker.h"

 /**
   * @fn
   * �R���X�g���N�^
   */
Tracker::Tracker() :_collision(Rect(0,0,0,0)),_stun_time(0.0f),_stun_flag(false),
					_move(nullptr), _check_move(nullptr),_ctracker_state(nullptr),
					_tracker_state(TrackerState::State::Default),_old_tracker_state(TrackerState::State::Default),
					_direc(Direction::None)
{

}

/**
  * @fn
  * ������
  */
void Tracker::Initialize()
{
	_tracker_state = TrackerState::State::Default;

	_collision = Rect(_pos.x, _pos.y, _pos.x + CHARA_SIZE.x, _pos.y + CHARA_SIZE.y);

	_direc			 = Direction::Down;

	_move = new Move();
	_move->Initialize();

	_ctracker_state = new TrackerState();
	_ctracker_state->Initialize();

}

/**
  * @fn
  * �X�V����
  */
void Tracker::Update()
{
	KeyboardBuffer key = Keyboard->GetBuffer();
	_pos = _move->MovePostion(_pos, CHARA_SPEED,1);
	_direc = _move->GetDirection();
	
	//�ړ�������������CheckMove�N���X�ɒʒm����
	if (_move->GetMoveCmp())
	{
		_check_move->Notify(this);
	}

	if (_stun_flag)
	{
		StunTime();
	}

	if (key.IsPressed(Keys_A))
	{
		_tracker_state = TrackerState::State::Attack;
	}

	MoveCollision();

	if(_tracker_state != _old_tracker_state)
	{
		_ctracker_state->ChangeState(_tracker_state);
	}
	_ctracker_state->Update();
	if (_ctracker_state->GetAnimetionFinish())
	{
		_tracker_state = TrackerState::State::Default;
	}

	_old_tracker_state = _tracker_state;
}

/**
  * @fn
  * �`��
  */
void Tracker::Draw()
{
	_ctracker_state->Draw(_pos, (int)_direc);
}


/**
  * @fn
  * �f�R�C���U�������Ƃ��̃X�^������
  */
void Tracker::StunTime()
{
	constexpr float max_time = 120.0f;

	_stun_time++;
	if (_stun_time > max_time)
	{
		_stun_flag = false;
	}
}

/**
  * @fn
  * �U�������Ƃ��̓����蔻��̕ύX
  */
void Tracker::MoveCollision()
{
	if (_tracker_state == TrackerState::State::Attack)
	{
		_collision = Rect(_pos.x, _pos.y, _pos.x + CHARA_SIZE.x, _pos.y + CHARA_SIZE.y);
	}
	else
	{
		_collision = Rect(0,0,0,0);
	}
}

/**
  * @fn
  * �����������̏���
  * @param (tag) ������������̃^�O
  */
void Tracker::OnCollisionEnter(std::string tag)
{
	if(tag == "DECOY")
		_stun_flag = true;
}

