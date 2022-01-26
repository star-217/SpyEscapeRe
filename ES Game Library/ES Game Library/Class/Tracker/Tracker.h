/**
 * @file  Tracker.h
 * @brief Tracker.cppのヘッダーファイル
 * @author 星寛文
 * @date 2021/04/20
 */
#pragma once

#include "../../ESGLib.h"
#include "../Base/Move/Move.h"
#include "../Base/HumanBase/HumanBase.h"
#include "../Base/CheckMove/CheckMove.h"
#include "../Map/Map.h"

class Tracker : public HumanBase
{
public:
	Tracker();
	~Tracker() {};

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void OnCollisionEnter(std::string tag) override;
	void DoMove(HumanBase* human) override {};


	void SetCheckMoveClass(CheckMove* check_move) { _check_move = check_move; }
	void Attack();

private:
	enum class TrackerState
	{
		Default,
		Win,
		Lose,
		Attack
	};

	void StunTime();
	void Animetion();
	void WinAnimetion();
	void LoseAnimetion();
	void AttackAnimetion();

	Move* _move;
	CheckMove* _check_move;

	TrackerState		 _tracker_state;
	Move::Direction			 _direc;

	SPRITE _tracker;
	SPRITE _tracker_win;
	SPRITE _tracker_lose;
	SPRITE _tracker_attack;

	Rect	_collision;

	float	_tracker_spd;
	float	_stun_time;
	float	_tracker_flame_x;
	float	_win_flame;
	float	_lose_flame;
	float   _attack_flame;

	bool	_stun_flag;

};