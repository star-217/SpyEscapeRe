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

	void Animetion();
	void WinAnimetion();
	void LoseAnimetion();

	Move* _move;
	SkillState* _skill;
	SpyState _state;

	SPRITE _spy;
	SPRITE _win;
	SPRITE _lose;

	int _direction;
	int _player_count;

	float _animetion_flame;
	float _win_flame;
	float _lose_flame;
	float _invisible_alpha;

	Vector3 _old_pos;
};