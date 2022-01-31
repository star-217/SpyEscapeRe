/**
 * @file  Spy.h
 * @brief ì¶Ç∞ÇÈë§ÇÃÉNÉâÉX
 * @author êØä∞ï∂
 * @date 2021/04/20
 */

#pragma once

#include "../../ESGLib.h"
#include "Skill/SkillState.h"
#include "../Base/Move/Move.h"
#include "../Map/Map.h"
#include "../Base/HumanBase/HumanBase.h"
#include "SpyState/SpyState.h"

class Spy : public HumanBase
{
public:
	Spy();
	virtual ~Spy() {}

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void OnCollisionEnter(std::string tag) override;
	void DoMove(HumanBase* human) override {};

private:

	std::unique_ptr<Move>		_move;
	std::unique_ptr<SkillState> _skill;
	std::unique_ptr<SpyState>	_state;

	int _direction;
	int _player_count;

	float _invisible_alpha;

	Vector3 _old_pos;
};