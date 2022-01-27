/**
 * @file  Tracker.h
 * @brief ãSë§ÇÃÉNÉâÉX
 * @author êØä∞ï∂
 * @date 2021/04/20
 */
#pragma once

#include "../../ESGLib.h"
#include "../Base/Move/Move.h"
#include "../Base/HumanBase/HumanBase.h"
#include "../Base/CheckMove/CheckMove.h"
#include "../Map/Map.h"
#include "TrackerState/TrackerState.h"

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
	void MoveCollision();

	//çUåÇÇµÇƒÇ¢Ç»Ç¢Ç∆Ç´
	void Default() { _collision = Rect(0, 0, 0, 0); };

private:

	void StunTime();
	void Animetion();
	void WinAnimetion();
	void LoseAnimetion();
	void AttackAnimetion();

	Move* _move;
	CheckMove* _check_move;
	TrackerState* _ctracker_state;

	TrackerState::State		 _tracker_state;
	TrackerState::State		 _old_tracker_state;

	Direction			_direc;

	Rect	_collision;

	float	_tracker_spd;
	float	_stun_time;
	float	_tracker_flame_x;
	float	_win_flame;
	float	_lose_flame;
	float   _attack_flame;

	bool	_stun_flag;

};