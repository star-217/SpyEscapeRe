/**
 * @file  Tracker.h
 * @brief ‹S‘¤‚ÌƒNƒ‰ƒX
 * @author ¯Š°•¶
 * @date 2021/04/20
 */
#pragma once

#include "../../ESGLib.h"
#include "../Base/Move/Move.h"
#include "../Base/HumanBase/HumanBase.h"
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

private:

	//UŒ‚‚µ‚Ä‚¢‚È‚¢‚Æ‚«
	void Default() { _collision = Rect(0, 0, 0, 0); };
	void MoveCollision();
	void StunTime();

	Move* _move;
	TrackerState* _ctracker_state;

	TrackerState::State		 _tracker_state;
	TrackerState::State		 _old_tracker_state;

	Direction			_direc;

	Rect	_collision;

	float	_stun_time;

	bool	_stun_flag;

};