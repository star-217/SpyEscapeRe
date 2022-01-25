#include "Spy.h"

void Spy::Initialize()
{
	_spy = GraphicsDevice.CreateSpriteFromFile(_T("spy.png"));
	_win = GraphicsDevice.CreateSpriteFromFile(_T("playerwin.png"));
	_lose = GraphicsDevice.CreateSpriteFromFile(_T("playerdown.png"));

	_map_data = Map::GetInstance().GetMapData();

	_direction = 0;
	_player_count = 0;

	_animetion_flame = 0;
	_win_flame = 0;
	_lose_flame = 0;

	_invisible_alpha = 1.0f;

	_tag = "SPY";
	_move.Initialize();

}

void Spy::Update()
{
	KeyboardBuffer key	= Keyboard->GetBuffer();
	_pos			= _move.MovePostion(_pos,_map_data, _speed,0);
	_invisible_alpha	= _skill.Update();
	_direction			= (int)_move.GetDirection();

	_collision			= Rect(_pos.x, _pos.y, _pos.x + _chara_size_width, _pos.y + _chara_size_height);

	Animetion();

	if (key.IsPressed(Keys_Enter)) {
		_skill.RandomSkil();
	}

}

void Spy::Draw()
{
	constexpr int fix_postion_y = 20;

	const Vector3 _draw_spy_pos = Vector3(_pos.x, _pos.y - fix_postion_y, 0.0f);

	_skill.Draw();
	switch (_state) {
	case DEFAULT:
		SpriteBatch.Draw(*_spy, _draw_spy_pos, RectWH(CHARA_SIZE_X * (int)_animetion_flame, _direction * CHARA_SIZE_Y, CHARA_SIZE_X, CHARA_SIZE_Y), _invisible_alpha);
		break;
	case WIN:
		SpriteBatch.Draw(*_win, _draw_spy_pos, RectWH(CHARA_SIZE_X * (int)_win_flame, 0, CHARA_SIZE_X, CHARA_SIZE_Y));
		break;
	case LOSE:
		SpriteBatch.Draw(*_lose, _draw_spy_pos, RectWH(CHARA_SIZE_X * (int)_lose_flame, 0, CHARA_SIZE_X, CHARA_SIZE_Y));
		break;
	}
}

void Spy::Animetion()
{
	const int animetion_flame_max = 40;

	_animetion_flame = int(_animetion_flame + 1) % animetion_flame_max;
}


void Spy::WinAnimetion()
{
	const float flame_speed	= 0.8f;
	const int max_flame		= 50;

	_win_flame += flame_speed;
	_win_flame = max(_win_flame, max_flame);

}

void Spy::LoseAnimetion()
{
	const float flame_speed	= 0.8f;
	const int max_flame		= 30;

	_lose_flame += flame_speed;
	_lose_flame = max(_lose_flame, max_flame);

}

void Spy::OnCollisionEnter(std::string tag)
{
	_state = LOSE;
}
