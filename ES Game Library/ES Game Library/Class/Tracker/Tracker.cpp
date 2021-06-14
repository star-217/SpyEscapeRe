#include "Tracker.h"


bool Tracker::Initialize(std::vector<cstring> data)
{
	map_data = data;
	tracker_win = GraphicsDevice.CreateSpriteFromFile(_T("oniwin.png"));
	tracker = GraphicsDevice.CreateSpriteFromFile(_T("oni2.png"));
	tracker_attack = GraphicsDevice.CreateSpriteFromFile(_T("punch.png"));
	tracker_spd =5.0f;
	tracker_pos = Vector3(1500, 800, 0);
	tracker_state = 0;
	tracker_flame_x = 0;
	direc = 0;
	stun_state = false;
	chara_size = 50;
	move.Initialize();

	return false;
}

Vector3 Tracker::Update()
{
	tracker_pos = move.Move(tracker_pos,map_data,tracker_spd,1);
	direc = move.GetDirection();
	Animetion();

	return tracker_pos;
}

void Tracker::Draw()
{
	SpriteBatch.Draw(*tracker, Vector3(tracker_pos.x, tracker_pos.y - 20, 0), RectWH(chara_size * tracker_flame_x, 70 * direc, 50, 70));
}



void Tracker::Animetion()
{
	tracker_flame_x++;

	tracker_flame_x = (int)tracker_flame_x % 40;
}
