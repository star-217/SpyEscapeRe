#include "Tracker.h"


bool Tracker::Initialize(std::vector<cstring> data)
{
	_map_data = data;
	_tracker_win = GraphicsDevice.CreateSpriteFromFile(_T("oniwin.png"));
	_tracker = GraphicsDevice.CreateSpriteFromFile(_T("oni2.png"));
	_tracker_attack = GraphicsDevice.CreateSpriteFromFile(_T("punch.png"));

	_tracker_spd =5.0f;
	_tracker_pos = Vector3(1500, 800, 0);
	_tracker_state = 0;
	_tracker_flame_x = 0;
	_win_flame = 0;
	_lose_flame = 0;

	_chara_size_width = 50;
	_chara_size_height = 70;

	_direc = 0;
	_stun_flag = false;
	_move.Initialize();

	return false;
}

Vector3 Tracker::Update()
{
	_tracker_pos = _move.Move(_tracker_pos,_map_data,_tracker_spd,1);
	_collision = Rect(_tracker_pos.x, _tracker_pos.y, _tracker_pos.x + _chara_size_width, _tracker_pos.y + _chara_size_height);
	_direc = _move.GetDirection();
	Animetion();

	return _tracker_pos;
}

void Tracker::Draw()
{
	SpriteBatch.Draw(*_tracker, Vector3(_tracker_pos.x, _tracker_pos.y - 20, 0), RectWH(_chara_size_width * _tracker_flame_x, _chara_size_height * _direc, _chara_size_width, _chara_size_height));
}



void Tracker::Animetion()
{
	_tracker_flame_x++;

	_tracker_flame_x = (int)_tracker_flame_x % 40;
}

void Tracker::WinAnimetion()
{
	_win_flame += 0.8f;
	_win_flame = max(_win_flame, 50);

}

void Tracker::LoseAnimetion()
{
	_lose_flame += 0.8f;
	_lose_flame = max(_lose_flame, 30);

}

void Tracker::Stun()
{

}
