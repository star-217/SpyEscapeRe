/**
 * @file  Spy.cpp
 * @brief SpyÇÃìÆçÏÇ∑Ç◊Çƒ
 * @author êØä∞ï∂
 * @date 2021/04/20
 */
#include "Spy.h"

Spy::Spy() :_spy(nullptr), _win(nullptr), _lose(nullptr),
			_spy_pos(Vector3_Zero),_draw_spy_pos(Vector3_Zero),
			_direction(Direction::None),_speed(0),_animetion_flame(0),_win_flame(0),
			_lose_flame(0),_invisible_alpha(0.0f),_state(SpyState::Default),
			_collision(Rect(0,0,0,0))
{

}

void Spy::Initialize(const std::vector<cstring>& data, const Vector3 pos)
{
	_spy			 = GraphicsDevice.CreateSpriteFromFile(_T("spy.png"));
	_win			 = GraphicsDevice.CreateSpriteFromFile(_T("playerwin.png"));
	_lose			 = GraphicsDevice.CreateSpriteFromFile(_T("playerdown.png"));

	_spy_pos		 = pos;
	_map_data		 = data;

	_direction		 = Direction::None;
	_speed			 = 5;
	_animetion_flame = 0;
	_win_flame		 = 0;
	_lose_flame		 = 0;
	_invisible_alpha = 1.0f;

	_move.Initialize();

}

Vector3 Spy::Update()
{
	KeyboardBuffer key	= Keyboard->GetBuffer();
	_spy_pos			= _move.MovePostion(_spy_pos,_map_data, _speed,0);
	_invisible_alpha	= _skill.Update();
	_direction			= _move.GetDirection();

	_collision			= Rect(_spy_pos.x, _spy_pos.y, _spy_pos.x + CHARA_SIZE_X, _spy_pos.y + CHARA_SIZE_Y);

	switch (_state)
	{
	case SpyState::Default: Animetion();     break;
	case SpyState::Win:     WinAnimetion();  break;
	case SpyState::Lose:    LoseAnimetion(); break;
	}

	if (key.IsPressed(Keys_Enter)) {
		_skill.RandomSkil();
	}

	return _spy_pos;
}

void Spy::Draw()
{
	_draw_spy_pos = Vector3(_spy_pos.x, _spy_pos.y - FIXED_POS_Y, 0.0f);

	_skill.Draw();
	switch (_state) {
	case SpyState::Default:
		SpriteBatch.Draw(*_spy,  _draw_spy_pos,
			RectWH(CHARA_SIZE_X * (int)_animetion_flame, ((int)_direction - 1) * CHARA_SIZE_Y, CHARA_SIZE_X, CHARA_SIZE_Y), _invisible_alpha);
		break;
	case SpyState::Win:
		SpriteBatch.Draw(*_win,  _draw_spy_pos, RectWH(CHARA_SIZE_X * (int)_win_flame, 0, CHARA_SIZE_X, CHARA_SIZE_Y));
		break;
	case SpyState::Lose:
		SpriteBatch.Draw(*_lose, _draw_spy_pos, RectWH(CHARA_SIZE_X * (int)_lose_flame, 0, CHARA_SIZE_X, CHARA_SIZE_Y));
		break;
	}
}

void Spy::Animetion()
{
	constexpr int animetion_flame_max = 40;
	_animetion_flame = int(_animetion_flame + 1) % animetion_flame_max;
}


void Spy::WinAnimetion()
{
	constexpr float flame_speed	= 0.8f;
	constexpr int	max_flame	= 50;
	_win_flame += flame_speed;
	_win_flame = max(_win_flame, max_flame);

}

void Spy::LoseAnimetion()
{
	constexpr float flame_speed	= 0.8f;
	constexpr int   max_flame	= 30;

	_lose_flame += flame_speed;
	_lose_flame = max(_lose_flame, max_flame);

}

void Spy::AttackHit()
{
	_state = SpyState::Lose;
}
