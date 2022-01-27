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
#include "../Base/CheckMove/CheckMove.h"

class Spy : public HumanBase
{
public:
	Spy() {};
	virtual ~Spy() {}

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void OnCollisionEnter(std::string tag) override;
	void DoMove(HumanBase* human) override {};

	void SetStartPos(Vector3& pos) { _pos = pos; }
	void SetCheckMoveClass(CheckMove* check_move) { _check_move = check_move; }

private:

	void Animetion();
	void WinAnimetion();
	void LoseAnimetion();

	Move* _move;
	CheckMove* _check_move;

	SkillState _skill;

	SPRITE _spy;
	SPRITE _win;
	SPRITE _lose;

	const int SPEED = 5.0f;

	SpyState _state;
	int _direction;
	int _player_count;

	float _animetion_flame;
	float _win_flame;
	float _lose_flame;
	float _invisible_alpha;

	Vector3 _old_pos;
};