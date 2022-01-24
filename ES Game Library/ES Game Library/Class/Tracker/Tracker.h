/**
 * @file  Tracker.h
 * @brief Tracker.cppのヘッダーファイル
 * @author 星寛文
 * @date 2021/04/20
 */
#pragma once

#include "../../ESGLib.h"
#include "../Controller/Controller.h"
#include "../Base/Move.h"
#include "../Base/GameState.h"

class Tracker
{
public:
	Tracker();
	~Tracker() {};

	bool Initialize(std::vector<cstring>&);
	Vector3 Update();
	void Draw();
	void Stun();
	void Attack();
	Rect GetCollision() { return _collision; }
private:

	void StunTime();
	void Animetion();
	void WinAnimetion();
	void LoseAnimetion();
	void AttackAnimetion();

	Move _move;

	TrackerState		 _tracker_state;
	Direction			 _direc;

	std::vector<cstring> _map_data;

	SPRITE _tracker;
	SPRITE _tracker_win;
	SPRITE _tracker_lose;
	SPRITE _tracker_attack;

	Rect	_collision;
	Vector3 _tracker_pos;

	float	_tracker_spd;
	float	_stun_time;
	float	_tracker_flame_x;
	float	_win_flame;
	float	_lose_flame;
	float   _attack_flame;

	bool	_stun_flag;



};