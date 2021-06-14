#pragma once

#include "../../ESGLib.h"
#include "../Controller/Controller.h"
#include "../Base/Move.h"

class Tracker
{
public:

	bool Initialize(std::vector<cstring>);
	Vector3 Update();
	void Draw();
	void Animetion();
private:

	CMove move;

	std::vector<cstring> map_data;

	SPRITE tracker;
	SPRITE tracker_attack;
	SPRITE tracker_win;
	SPRITE lose;
	Vector3 tracker_pos;


	float tracker_alpha;
	float tracker_spd;
	float stun_time;
	float tracker_count;
	float tracker_flame_x;
	float attack_state;
	float win_flame;
	float win_time;
	float lose_flame;
	float lose_time;

	bool stun_state;
	int tracker_state;
	int direc;
	int pad_direction;
	int chara_size;


};