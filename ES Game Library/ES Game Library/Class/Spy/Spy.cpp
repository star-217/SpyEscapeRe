/**
 * @file  Spy.cpp
 * @brief �����鑤�̃N���X
 * @author ������
 * @date 2021/04/20
 */
#include "Spy.h"
#include "../Base/CheckMove/CheckMove.h"

 /**
   * @fn
   * �R���X�g���N�^
   */
Spy::Spy() : _move(nullptr),_skill(nullptr),
			_direction(0),_player_count(0),_invisible_alpha(0)
{

}
 /**
   * @fn
   * ������
   */
void Spy::Initialize()
{

	//�A���t�@�l�Ȃ̂ŏ����͂P
	_invisible_alpha = 1.0f;

	_state = std::make_unique<SpyState>();
	_move = std::make_unique<Move>();
	_skill = std::make_unique<SkillState>();

	_state->Initialize();
	_move->Initialize();

}

/**
  * @fnh
  * �X�V����
  */
void Spy::Update()
{
	KeyboardBuffer key	= Keyboard->GetBuffer();

	_pos			    = _move->MovePostion(_pos,CHARA_SPEED,0);
	_skill->Update();
	_state->Update();
	_invisible_alpha	= _skill->GetAlpha();
	_direction			= (int)_move->GetDirection();
	_collision			= Rect(_pos.x, _pos.y, _pos.x + CHARA_SIZE.x, _pos.y + CHARA_SIZE.y);

	//�ړ�������������CheckMove�N���X�ɒʒm����
	if (_move->GetMoveCmp())
	{
		_check_move->Notify(this);
	}

	//�X�L���g�p
	if (key.IsPressed(Keys_Enter))
	{
		_skill->RandomSkill();
	}
}

/**
  * @fn
  * �`��
  */
void Spy::Draw()
{

	const Vector3 _draw_spy_pos = Vector3(_pos.x, _pos.y - FIX_POS_Y, 0.0f);

	_skill->Draw();
	_state->Draw(_draw_spy_pos,_direction,_invisible_alpha);
}

/**
  * @fn
  * �����������̏���
  * @param (tag) ������������̃^�O
  */
void Spy::OnCollisionEnter(std::string tag)
{
	if (tag == "TRACKER")
		_state->ChangeState(SpyState::State::Lose);

}
