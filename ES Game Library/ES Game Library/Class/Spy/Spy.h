/**
 * @file  Spy.h
 * @brief Spy.cppのヘッダーファイル
 * @author 星寛文
 * @date 2021/04/20
 */
#pragma once

#include "../../ESGLib.h"
#include "Skill/SkillState.h"
#include "../Controller/Controller.h"
#include "../Base/Move.h"
#include "../Base/GameState.h"

class Spy
{
public:
	Spy();
	virtual ~Spy() {}

	void Initialize(const std::vector<cstring>&, const Vector3);
	Vector3 Update();
	void Draw();
	Rect GetCollision() { return _collision; }
	void AttackHit();

private:

	void Animetion();
	void WinAnimetion();
	void LoseAnimetion();

	Move _move;
	SkillState _skill;

	SpyState _state;
	std::vector<cstring> _map_data;

	SPRITE _spy;
	SPRITE _win;
	SPRITE _lose;

	Vector3 _spy_pos;
	Vector3 _draw_spy_pos;

	Rect _collision;

	Direction _direction;
	int _speed;

	float _animetion_flame;
	float _win_flame;
	float _lose_flame;
	float _invisible_alpha;
};