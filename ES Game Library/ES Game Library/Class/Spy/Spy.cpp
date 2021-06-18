#include "Spy.h"

void Spy::Initialize(const std::vector<cstring> data, const Vector3 pos)
{
	_spy = GraphicsDevice.CreateSpriteFromFile(_T("spy.png"));
	_attack = GraphicsDevice.CreateSpriteFromFile(_T("punch.png"));
	_win = GraphicsDevice.CreateSpriteFromFile(_T("playerwin.png"));
	_lose = GraphicsDevice.CreateSpriteFromFile(_T("playerdown.png"));

	_spy_pos = pos;
	_map_data = data;

	_direction = 0;
	_player_count = 0;
	_chara_size_width = 50;
	_chara_size_height = 70;
	_fix_pos_y = 20;
	_speed = 5;

	_animetion_flame = 0;
	_win_flame = 0;
	_lose_flame = 0;

	_animetion_flame_max = 40;

	_invisible_alpha = 1.0f;
	_move.Initialize();

}

Vector3 Spy::Update()
{
	KeyboardBuffer key = Keyboard->GetBuffer();
	_spy_pos = _move.Move(_spy_pos,_map_data, _speed,0);
	_invisible_alpha = _skill.Update();
	_direction = _move.GetDirection();

	_collision = Rect(_spy_pos.x, _spy_pos.y, _spy_pos.x + _chara_size_width, _spy_pos.y + _chara_size_height);

	Animetion();

	if (key.IsPressed(Keys_Enter)) {
		_skill.RandomSkil();
	}


	return _spy_pos;
}

void Spy::Draw()
{

	_draw_spy_pos = Vector3(_spy_pos.x, _spy_pos.y - 20, 0.0f);

	_skill.Draw();
	switch (_state) {
	case DEFAULT:
		SpriteBatch.Draw(*_spy, _draw_spy_pos, RectWH(_chara_size_width * (int)_animetion_flame, _direction * _chara_size_height, _chara_size_width, _chara_size_height), _invisible_alpha); break;
	case WIN:
		SpriteBatch.Draw(*_win, _draw_spy_pos, RectWH(_chara_size_width * (int)_win_flame, 0, _chara_size_width, _chara_size_height)); break;
	case LOSE:
		SpriteBatch.Draw(*_lose, _draw_spy_pos, RectWH(_chara_size_width * (int)_lose_flame, 0, _chara_size_width, _chara_size_height)); break;
	}

}

void Spy::Animetion()
{
	_animetion_flame++;
	_animetion_flame = (int)_animetion_flame % (int)_animetion_flame_max;
}


void Spy::WinAnimetion()
{
	_win_flame += 0.8f;
	_win_flame = max(_win_flame, 50);

}

void Spy::LoseAnimetion()
{
	_lose_flame += 0.8f;
	_lose_flame = max(_lose_flame, 30);

}

void Spy::AttackHit()
{
}
