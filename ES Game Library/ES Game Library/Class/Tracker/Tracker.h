/**
 * @file  Tracker.h
 * @brief 鬼側のクラス
 * @author 星寛文
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

	//攻撃していないとき
	void Default() { _collision = Rect(0, 0, 0, 0); };
	void MoveCollision();
	void StunTime();

	std::unique_ptr<Move> _move;
	std::unique_ptr<TrackerState> _ctracker_state;

	TrackerState::State		 _tracker_state;
	TrackerState::State		 _old_tracker_state;

	Direction			_direc;

	float	_stun_time;
	bool	_stun_flag;

};