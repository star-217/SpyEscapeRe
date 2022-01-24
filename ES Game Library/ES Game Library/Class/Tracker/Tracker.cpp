/**
 * @file  Tracker.h
 * @brief Tracker‚Ì“®ì‚·‚×‚Ä‚ÌƒvƒƒOƒ‰ƒ€
 * @author ¯Š°•¶
 * @date 2021/04/20
 */
#include "Tracker.h"

Tracker::Tracker() :_tracker(nullptr),_tracker_win(nullptr),_tracker_lose(nullptr),
					_tracker_attack(nullptr),_collision(Rect(0,0,0,0)),_tracker_pos(Vector3_Zero),
					_tracker_spd(0.0f),_stun_time(0.0f),_tracker_flame_x(0.0f),_win_flame(0.0f),
					_lose_flame(0.0f),_attack_flame(0.0f),_stun_flag(false),_direc(Direction::None),
					_tracker_state(TrackerState::Default)
{

}


bool Tracker::Initialize(std::vector<cstring>& data)
{
	_map_data        = data;
	_tracker		 = GraphicsDevice.CreateSpriteFromFile(_T("oni2.png"));
	_tracker_win     = GraphicsDevice.CreateSpriteFromFile(_T("oniwin.png"));
	_tracker_lose	 = GraphicsDevice.CreateSpriteFromFile(_T("onilose.png"));
	_tracker_attack  = GraphicsDevice.CreateSpriteFromFile(_T("punch.png"));

	_tracker_pos = Vector3(1500, 800, 0);
	_tracker_state = TrackerState::Default;

	_tracker_spd     = 5.0f;
	_tracker_flame_x = 0;
	_stun_time		 = 0;
	_win_flame		 = 0;
	_lose_flame		 = 0;
	_attack_flame	 = 0;
	_collision = Rect(_tracker_pos.x, _tracker_pos.y, _tracker_pos.x + CHARA_SIZE_X, _tracker_pos.y + CHARA_SIZE_Y);


	_direc			 = Direction::None;
	_stun_flag		 = false;

	_move.Initialize();

	return false;
}

Vector3 Tracker::Update()
{
	KeyboardBuffer key = Keyboard->GetBuffer();
	_tracker_pos = _move.MovePostion(_tracker_pos,_map_data,_tracker_spd,1);
	_direc = _move.GetDirection();


	if (_stun_flag)
	{
		StunTime();
	}

	if (key.IsPressed(Keys_A))
	{
		_tracker_state = TrackerState::Attack;
	}

	Attack();

	switch (_tracker_state)
	{
	case TrackerState::Default: Animetion();     break;
	case TrackerState::Win:		WinAnimetion();  break;
	case TrackerState::Lose:	LoseAnimetion(); break;
	case TrackerState::Attack:
		AttackAnimetion();
		Attack();
		break;
	}

	return _tracker_pos;
}

void Tracker::Draw()
{


	switch (_tracker_state)
	{
	case TrackerState::Default:
		SpriteBatch.Draw(
			*_tracker, Vector3(_tracker_pos.x, _tracker_pos.y - FIXED_POS_Y, 0),
			RectWH(CHARA_SIZE_X * _tracker_flame_x, CHARA_SIZE_Y * ((int)_direc - 1), CHARA_SIZE_X, CHARA_SIZE_Y)
		);
		break;
	case TrackerState::Win:
		SpriteBatch.Draw(
			*_tracker_win, Vector3(_tracker_pos.x, _tracker_pos.y - FIXED_POS_Y, 0),
			RectWH(CHARA_SIZE_X * _win_flame, CHARA_SIZE_Y, CHARA_SIZE_X, CHARA_SIZE_Y)
		);
		break;
	case TrackerState::Lose:
		SpriteBatch.Draw(
			*_tracker_lose, Vector3(_tracker_pos.x, _tracker_pos.y - FIXED_POS_Y, 0),
			RectWH(CHARA_SIZE_X * _lose_flame, CHARA_SIZE_Y, CHARA_SIZE_X, CHARA_SIZE_Y)
		);
	case TrackerState::Attack:
		SpriteBatch.Draw(
			*_tracker_attack, Vector3(_tracker_pos.x, _tracker_pos.y - FIXED_POS_Y, 0),
			RectWH(CHARA_SIZE_X * _attack_flame, CHARA_SIZE_Y * ((int)_direc - 1), CHARA_SIZE_X, CHARA_SIZE_Y)
		);
		break;
	}

}



void Tracker::StunTime()
{
	constexpr float max_time = 120.0f;

	_stun_time++;
	if (_stun_time > max_time)
	{
		_stun_flag = false;
	}
}

void Tracker::Animetion()
{
	constexpr int max_flame = 40;

	_tracker_flame_x = int(_tracker_flame_x + 1) % max_flame;
}

void Tracker::WinAnimetion()
{
	constexpr int flame_speed = 0.8f;
	constexpr int flame_max   = 50.0f;

	_win_flame  += flame_speed;
	_win_flame  = max(_win_flame, flame_max);

}

void Tracker::LoseAnimetion()
{
	constexpr int flame_speed = 0.8f;
	constexpr int flame_max   = 30.0f;

	_lose_flame  += flame_speed;
	_lose_flame  = max(_lose_flame, flame_max);

}

void Tracker::AttackAnimetion()
{
	constexpr int flame_speed = 1.0f;
	constexpr int flame_max   = 50.0f;

	_attack_flame += flame_speed;
	if (_attack_flame > flame_max)
	{
		_attack_flame  = 0.0f;
		_tracker_state = TrackerState::Default;
	}
}

void Tracker::Stun()
{
	_stun_flag = true;
}

void Tracker::Attack()
{
	_collision = Rect(_tracker_pos.x, _tracker_pos.y, _tracker_pos.x + CHARA_SIZE_X, _tracker_pos.y + CHARA_SIZE_Y);
}
