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
			_spy(0),_win(0),_lose(0),_state(SpyState::Default),
			_direction(0),_player_count(0),_animetion_flame(0),
			_win_flame(0),_lose_flame(0),_invisible_alpha(0)
{

}
 /**
   * @fn
   * ������
   */
void Spy::Initialize()
{
	_spy = GraphicsDevice.CreateSpriteFromFile(_T("spy.png"));
	_win = GraphicsDevice.CreateSpriteFromFile(_T("playerwin.png"));
	_lose = GraphicsDevice.CreateSpriteFromFile(_T("playerdown.png"));

	//�A���t�@�l�Ȃ̂ŏ����͂P
	_invisible_alpha = 1.0f;

	_move = new Move();
	_move->Initialize();

	_skill = new SkillState();

}

/**
  * @fn
  * �X�V����
  */
void Spy::Update()
{
	KeyboardBuffer key	= Keyboard->GetBuffer();

	_pos			    = _move->MovePostion(_pos,CHARA_SPEED,0);
	_skill->Update();
	_invisible_alpha = _skill->GetAlpfa();
	_direction			= (int)_move->GetDirection();
	_collision			= Rect(_pos.x, _pos.y, _pos.x + CHARA_SIZE.x, _pos.y + CHARA_SIZE.y);

	//�ړ�������������CheckMove�N���X�ɒʒm����
	if (_move->GetMoveCmp())
	{
		_check_move->Notify(this);
	}

	Animetion();

	//�X�L���g�p
	if (key.IsPressed(Keys_Enter)) {
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
	switch (_state) {
	case SpyState::Default:
		SpriteBatch.Draw(*_spy, _draw_spy_pos, RectWH(CHARA_SIZE.x * (int)_animetion_flame, _direction * CHARA_SIZE.y, CHARA_SIZE.x, CHARA_SIZE.y), _invisible_alpha);
		break;
	case SpyState::Win:
		SpriteBatch.Draw(*_win, _draw_spy_pos, RectWH(CHARA_SIZE.x * (int)_win_flame, 0, CHARA_SIZE.x, CHARA_SIZE.y));
		break;
	case SpyState::Lose:
		SpriteBatch.Draw(*_lose, _draw_spy_pos, RectWH(CHARA_SIZE.x * (int)_lose_flame, 0, CHARA_SIZE.x, CHARA_SIZE.y));
		break;
	}
}

/**
  * @fn
  * (�ʏ�)�A�ԉ摜�A�j���[�V����
  */
void Spy::Animetion()
{
	constexpr int animetion_flame_max = 40;

	_animetion_flame = int(_animetion_flame + 1) % animetion_flame_max;
}

/**
  * @fn
  * (������)�A�ԉ摜�A�j���[�V����
  */
void Spy::WinAnimetion()
{
	constexpr float flame_speed	= 0.8f;
	constexpr int max_flame		= 50;

	_win_flame += flame_speed;
	_win_flame = max(_win_flame, max_flame);

}

/**
  * @fn
  * (�s�k��)�A�ԉ摜�A�j���[�V����
  */
void Spy::LoseAnimetion()
{
	constexpr float flame_speed	= 0.8f;
	constexpr int max_flame		= 30;

	_lose_flame += flame_speed;
	_lose_flame = max(_lose_flame, max_flame);

}

/**
  * @fn
  * �����������̏���
  * @param (tag) ������������̃^�O
  */
void Spy::OnCollisionEnter(std::string tag)
{
	if(tag == "TRACKER")
		_state = SpyState::Lose;
}
