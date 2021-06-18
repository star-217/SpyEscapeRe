#pragma once

#include "../../ESGLib.h"
#include "../Controller/Controller.h"
#include "../Base/Move.h"
#include "../Base/GameState.h"

class Tracker
{
public:

	bool Initialize(std::vector<cstring>);
	Vector3 Update();
	void Draw();
	void Animetion();
	void WinAnimetion();
	void LoseAnimetion();
	Rect GetCollision() { return _collision; }
private:

	CMove _move;

	std::vector<cstring> _map_data;

	SPRITE _tracker;
	SPRITE _tracker_attack;
	SPRITE _tracker_win;
	SPRITE _lose;

	Rect _collision;
	Vector3 _tracker_pos;


	int _chara_size_width;
	int _chara_size_height;

	float _tracker_alpha;
	float _tracker_spd;
	float _stun_time;
	float _tracker_flame_x;
	float _attack_state;
	float _win_flame;
	float _win_time;
	float _lose_flame;
	float _lose_time;

	bool _stun_state;

	int _tracker_state;
	int _direc;


};